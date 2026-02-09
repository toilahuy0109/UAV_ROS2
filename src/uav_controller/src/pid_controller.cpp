#include "pid_controller.hpp"

PID::PID(double kp, double ki, double kd, double Ts)
: kp_(kp), ki_(ki), kd_(kd), Ts_(Ts), integral_(0.0), imax_(2.0), eps_(1.0)
{}

double PID::update(double e, double edot)
{
    if (std::abs(e) > eps_)
    {
        integral_ += e*Ts_;
        integral_ = std::clamp(integral_, -imax_, imax_);
    }
    return kp_*e + ki_*integral_ + kd_*edot;
}


Pos_Controller::Pos_Controller() : rclcpp::Node("pos_controller"), x_(0.0), y_(0.0), vx_(0.0), vy_(0.0), vz_(0.0), yaw_ref_(0.0), g_(9.81)
{
    Ts_ = 0.02;
    start_time_ = this->get_clock()->now();

    pid_x_ = std::make_shared<PID>(1.0, 0.0, 0.5, Ts_);
    pid_y_ = std::make_shared<PID>(1.0, 0.0, 0.5, Ts_);
    pid_z_ = std::make_shared<PID>(1.0, 0.0, 0.5, Ts_);

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

    vx_ = msg->twist.twist.linear.x;
    vy_ = msg->twist.twist.linear.y;
    vz_ = msg->twist.twist.linear.z;
}

void Pos_Controller::controlLoop()
{
    double t = (this->get_clock()->now() - start_time_).seconds();

    double A = 1.0;
    double w = 0.5;
    double z_rate = 0.001;

    x_ref_ = A*std::sin(w*t);
    y_ref_ = A*std::sin(w*t + M_PI / 2.0);
    z_ref_ = z_rate * t;

    /*----------------- Errors --------------------*/
    double ex = x_ref_ - x_;
    double ey = y_ref_ - y_;
    double ez = z_ref_ - z_;

    double ex_dot = -vx_;
    double ey_dot = -vy_;
    double ez_dot = -vz_;

    /*------------------ PID ----------------------*/
    double ux = pid_x_->update(ex, ex_dot);
    double uy = pid_y_->update(ey, ey_dot);
    double uz = pid_z_->update(ez, ez_dot);

    /*----------------- Attitude Ref ---------------*/
    geometry_msgs::msg::Vector3 att_ref;
    att_ref.x = -uy/g_;
    att_ref.y = -ux/g_;
    att_ref.z = yaw_ref_;

    attitude_ref_pub_->publish(att_ref);

    /*---------------- Thrust Ref -------------------*/
    std_msgs::msg::Float64 thrust_ref;
    thrust_ref.data = g_ + uz;

    thrust_ref_pub_->publish(thrust_ref);

    RCLCPP_INFO(this->get_logger(),
    "ex: %.4f, ey: %.4f, ez: %.4f", ex, ey, ez);

}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pos_Controller>());
    rclcpp::shutdown();
    return 0;
}