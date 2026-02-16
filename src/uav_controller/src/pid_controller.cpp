#include "pid_controller.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

PID::PID(double kp, double ki, double kd, double Ts)
: kp_(kp), ki_(ki), kd_(kd), Ts_(Ts), integral_(0.0), imax_(2.0), eps_(1.0)
{}

double PID::get_integral()
{
    return integral_;
}

double PID::update(double e, double edot)
{
    if (std::abs(e) > eps_)
    {
        integral_ += e*Ts_;
        
    }
    return kp_*e + ki_*integral_ + kd_*edot;
}

Pos_Controller::Pos_Controller() : rclcpp::Node("pos_controller"), x_(0.0), y_(0.0), yaw_ref_(0.0), g_(9.81)
{
    Ts_ = 0.01;
    start_time_ = this->get_clock()->now();

    pid_x_ = std::make_shared<PID>(0.0274953657924367, 0.00055898718103685, 0.330530505324201, Ts_);
    pid_y_ = std::make_shared<PID>(0.0274953657924367, 0.00055898718103685, 0.330530505324201, Ts_);
    pid_z_ = std::make_shared<PID>(0.0274953657924367, 0.00055898718103685, 0.330530505324201, Ts_);

    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10,
        std::bind(&Pos_Controller::odomCallback, this, std::placeholders::_1)
    );

    attitude_ref_pub_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/attitude_ref", 10
    );

    thrust_ref_pub_ = this->create_publisher<std_msgs::msg::Float64>(
        "/thrust_ref", 10
    );

    pos_err_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/pos_err", 10
    );

    pos_dot_err_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/pos_dot_err", 10
    );

    control_timer_ = this->create_wall_timer(
        std::chrono::duration<double>(Ts_),
        std::bind(&Pos_Controller::controlLoop, this)
    );

    RCLCPP_INFO(this->get_logger(),
    "Position PID controller (XYZ tracking) started");
}

void Pos_Controller::odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    x_ = msg->pose.pose.position.x;
    y_ = msg->pose.pose.position.y;
    z_ = msg->pose.pose.position.z;
}

void Pos_Controller::imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    tf2::Quaternion q(
        msg->orientation.x,
        msg->orientation.y,
        msg->orientation.z,
        msg->orientation.w
    );
    tf2::Matrix3x3(q).getRPY(phi_, theta_, psi_);
}

void Pos_Controller::controlLoop()
{
    double t = (this->get_clock()->now() - start_time_).seconds();

    double A = 10.0;
    double w = 1/16;
    double z_rate = 0.001;

    x_ref_ = A*std::sin(w*t);
    y_ref_ = A*std::sin(w*t + M_PI / 2.0);
    z_ref_ = z_rate * t;

    /*----------------- Errors --------------------*/
    double ex = x_ref_ - x_;
    double ey = y_ref_ - y_;
    double ez = z_ref_ - z_;

    double ex_dot = (ex - prev.ex)/Ts_;
    double ey_dot = (ey - prev.ey)/Ts_;
    double ez_dot = (ez - prev.ez)/Ts_;
    
    prev.ex = ex;
    prev.ey = ey;
    prev.ez = ez;

    /*------------------ PID ----------------------*/
    double ux = pid_x_->update(ex, ex_dot);
    double uy = pid_y_->update(ey, ey_dot);
    double uz = pid_z_->update(ez, ez_dot) + 1.4*9.8;


    /*---------------- Thrust Ref -------------------*/
    std_msgs::msg::Float64 thrust_ref;
    thrust_ref.data = m_*std::sqrt(ux*ux + uy*uy + (uz+g_)*(uz+g_));

    /*----------------- Attitude Ref ---------------*/
    geometry_msgs::msg::Vector3 att_ref;
    att_ref.x = std::asin(m_*(ux*std::sin(psi_) - uy*std::cos(psi_))/thrust_ref.data);
    att_ref.y = std::atan((ux*std::cos(psi_) + uy*std::sin(psi_))/(uz+g_));
    att_ref.z = yaw_ref_;

    // Publish for show node
    geometry_msgs::msg::Vector3 e_pos;
    e_pos.x = ex;
    e_pos.y = ey;
    e_pos.z = ez;

    geometry_msgs::msg::Vector3 e_pos_dot;
    e_pos_dot.x = ex_dot;
    e_pos_dot.y = ey_dot;
    e_pos_dot.z = ez_dot;

    pos_err_->publish(e_pos);
    pos_dot_err_->publish(e_pos_dot);

    attitude_ref_pub_->publish(att_ref);
    thrust_ref_pub_->publish(thrust_ref);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pos_Controller>());
    rclcpp::shutdown();
    return 0;
}