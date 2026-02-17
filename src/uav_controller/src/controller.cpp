#include "controller.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <algorithm>
#include <cmath>


PID::PID(double kp, double ki, double kd)
: kp_(kp), ki_(ki), kd_(kd), integral_(0.0), eps_(1.0), N_(57.1413988020802), prev_error_(0.0)
{}

double PID::get_integral()
{
    return integral_;
}

double PID::update(double e, double edot, double Ts_)
{
    double alpha = N_*Ts_ / (1.0 + N_ * Ts_);
    derivative_ = alpha * derivative_ + (kd_ * N_ / (1.0 + N_ * Ts_))*(e - prev_error_);
    if (std::abs(e) > eps_)
    {
        integral_ += e*Ts_;
        
    }
    prev_error_ = e;
    return kp_*e + ki_*integral_ + derivative_;
}

SMC::SMC(double lambda, double k) : lambda_(lambda), k_(k)
{}

double SMC::update(double e, double edot)
{
    // sliding surface
    double s = edot + lambda_*e;

    return -k_ * std::tanh(s);
}

double SMC::get_lambda()
{
    return lambda_;
}

double SMC::get_slide(double e, double edot)
{
    return edot + lambda_*e;
}


Controller::Controller() : Node("controller_node"), x_(0.0), y_(0.0), Ts_(0.01), start_time_(0.0), prev_time_(0.0)
{
    start_time_ = this->get_clock()->now();
    prev_time_ = this->get_clock()->now();

    // Publish Data to show
    pos_err_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/pos_err", 10);

    pos_dot_err_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/pos_dot_err", 10);
    
    attitude_ref_pub_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/attitude_ref", 10);

    thrust_ref_pub_ = this->create_publisher<std_msgs::msg::Float64>(
        "/thrust_ref", 10);
    
    att_err_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/att_error", 10);

    att_err_dot_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/att_error_dot", 10);

    slide_sur_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/slide_sur", 10);

    // Publish velocity of motor

    motor_pub_ = this->create_publisher<uav_msgs::msg::UavCmd>(
        "/motor_vel", 10);

    // Subscribe info from sensor

    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10,
        std::bind(&Controller::odomCallback, this, std::placeholders::_1)
    );

    imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "/drone/imu_plugin/out", 50,
        std::bind(&Controller::controlLoop, this, std::placeholders::_1)
    );

    /*------------------------ Controller -----------------------------*/
    pid_x_ = std::make_shared<PID>(0.0274953657924367, 0.00055898718103685, 0.330530505324201);
    pid_y_ = std::make_shared<PID>(0.0274953657924367, 0.00055898718103685, 0.330530505324201);
    pid_z_ = std::make_shared<PID>(0.0274953657924367, 0.00055898718103685, 0.330530505324201);

    smc_phi_ = std::make_shared<SMC>(10.0, 10.0);
    smc_theta_ = std::make_shared<SMC>(10.0, 10.0);
    smc_psi_ = std::make_shared<SMC>(10.0, 10.0);

}

void Controller::odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
        x_ = msg->pose.pose.position.x;
        y_ = msg->pose.pose.position.y;
        z_ = msg->pose.pose.position.z;
}

void Controller::controlLoop(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    rclcpp::Time now(msg->header.stamp);
    Ts_ = (now - prev_time_).seconds();
    double t = (now - start_time_).seconds();
    printf("%.4f", t);

    // Get attitude from sensor
    tf2::Quaternion q(
        msg->orientation.x,
        msg->orientation.y,
        msg->orientation.z,
        msg->orientation.w
    );
    tf2::Matrix3x3(q).getRPY(phi_, theta_, psi_);

    // Reference Trajectory
    double A = 10.0;
    double w = 1/16;
    double z_rate = 0.001;

    x_ref_ = A*std::sin(w*t);
    y_ref_ = A*std::sin(w*t + M_PI / 2.0);
    z_ref_ = 10.0;

    /*----------------- Errors --------------------*/
    double ex = x_ref_ - x_;
    double ey = y_ref_ - y_;
    double ez = z_ref_ - z_;

    double ex_dot = (ex - pid_data.ex)/Ts_;
    double ey_dot = (ey - pid_data.ey)/Ts_;
    double ez_dot = (ez - pid_data.ez)/Ts_;
    
    pid_data.ex = ex;
    pid_data.ey = ey;
    pid_data.ez = ez;

    /*------------------ PID ----------------------*/
    double ux = pid_x_->update(ex, ex_dot, Ts_);
    double uy = pid_y_->update(ey, ey_dot, Ts_);
    double uz = pid_z_->update(ez, ez_dot, Ts_) + m_*g_;


    /*---------------- Thrust Ref -------------------*/
    double thrust_ref = m_*std::sqrt(ux*ux + uy*uy + (uz+g_)*(uz+g_));

    std_msgs::msg::Float64 thrust;
    thrust.data = thrust_ref;
    thrust_ref_pub_->publish(thrust);

    /*----------------- Attitude Ref ---------------*/
    double phi_ref = std::asin(m_*(ux*std::sin(psi_) - uy*std::cos(psi_))/thrust_ref);
    double theta_ref = std::atan((ux*std::cos(psi_) + uy*std::sin(psi_))/(uz+g_));
    double psi_ref = yaw_ref_;

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

    /*---------------------- Derivative ------------------------*/
    double phi_dot, theta_dot, psi_dot;
    double phi_ref_dot, theta_ref_dot, psi_ref_dot;
    double phi_ref_ddot, theta_ref_ddot, psi_ref_ddot;

    phi_dot = (phi_ - smc_data.phi_)/Ts_;
    theta_dot = (theta_ - smc_data.theta_)/Ts_;
    psi_dot = (psi_ - smc_data.psi_)/Ts_;

    phi_ref_dot = (phi_ref - smc_data.phi_ref_)/Ts_;
    theta_ref_dot = (theta_ref - smc_data.theta_ref_)/Ts_;
    psi_ref_dot = (psi_ref - smc_data.psi_ref_)/Ts_;

    phi_ref_ddot = (phi_ref_dot - smc_data.phi_ref_dot)/Ts_;
    theta_ref_ddot = (theta_ref_dot - smc_data.theta_ref_dot)/Ts_;
    psi_ref_ddot = (psi_ref_dot - smc_data.psi_ref_dot)/Ts_;

    /* ----------------- Error -----------------------------*/
    double e_phi = phi_ - phi_ref;
    double e_theta = theta_ - theta_ref;
    double e_psi = psi_ - psi_ref;

    double e_phi_dot = phi_dot - phi_ref_dot;
    double e_theta_dot = theta_dot - theta_ref_dot;
    double e_psi_dot = psi_dot - psi_ref_dot;

    smc_data.phi_ = phi_;
    smc_data.theta_ = theta_;
    smc_data.psi_ = psi_;

    smc_data.ephi_ = e_phi;
    smc_data.etheta_ = e_theta;
    smc_data.epsi_ = e_psi;

    smc_data.phi_ref_ = phi_ref;
    smc_data.theta_ref_ = theta_ref;
    smc_data.psi_ref_ = psi_ref;

    smc_data.phi_ref_dot = phi_ref_dot;
    smc_data.theta_ref_dot = theta_ref_dot;
    smc_data.psi_ref_dot = psi_ref_dot;

    geometry_msgs::msg::Vector3 att_err;
    geometry_msgs::msg::Vector3 att_err_dot;

    att_err.x = e_phi;
    att_err.y = e_theta;
    att_err.z = e_psi;

    att_err_dot.x = e_phi_dot;
    att_err_dot.y = e_theta_dot;
    att_err_dot.z = e_psi_dot;

    /* ----------------- Sliding Surface -----------------------*/
    double P[3];
    geometry_msgs::msg::Vector3 slide_sur;

    P[0] = smc_phi_->update(e_phi, e_phi_dot);
    P[1] = smc_theta_->update(e_theta, e_theta_dot);
    P[2] = smc_psi_->update(e_psi, e_psi_dot);

    slide_sur.x = P[0];
    slide_sur.y = P[1];
    slide_sur.z = P[2];

    /* ----------------- Calculate Tau --------------------------*/
    double tau[3];
    double omega = smc_data.w1 + smc_data.w3 - smc_data.w2 - smc_data.w4;

    tau[0] = Ix_*(-smc_phi_->get_lambda()*e_phi_dot + phi_ref_ddot - theta_dot*psi_dot*(Iy_-Iz_)/Ix_ - Jr_*theta_dot*omega/Ix_ - k1_*smc_phi_->get_slide(e_phi, e_phi_dot) + smc_phi_->update(e_phi, e_phi_dot));
    tau[1] = Iy_*(-smc_theta_->get_lambda()*e_theta_dot + theta_ref_ddot - phi_dot*psi_dot*(Iz_-Ix_)/Iy_ + Jr_*phi_dot*omega/Iy_ - k1_*smc_theta_->get_slide(e_theta, e_theta_dot) + smc_theta_->update(e_theta, e_theta_dot));
    tau[2] = Iz_*(-smc_psi_->get_lambda()*e_psi_dot + psi_ref_ddot - phi_dot*theta_dot*(Ix_-Iy_)/Iz_ - k1_*smc_psi_->get_slide(e_psi, e_psi_dot) + smc_phi_->update(e_psi, e_psi_dot));

    /* ----------------- Calculate w for 4 motors --------------*/
    double w1, w2, w3, w4;

    w1 = std::sqrt(std::abs(thrust_ref/(4*b_) - tau[1]/(2*length_*b_) - tau[2]/(4*d_)));
    w2 = std::sqrt(std::abs(thrust_ref/(4*b_) - tau[0]/(2*length_*b_) + tau[2]/(4*d_)));
    w3 = std::sqrt(std::abs(thrust_ref/(4*b_) + tau[1]/(2*length_*b_) - tau[2]/(4*d_)));
    w4 = std::sqrt(std::abs(thrust_ref/(4*b_) + tau[0]/(2*length_*b_) + tau[2]/(4*d_)));

    w1 = std::clamp(w1, 0.0, 2300.0);
    w2 = std::clamp(w2, 0.0, 2300.0);
    w3 = std::clamp(w3, 0.0, 2300.0);
    w4 = std::clamp(w4, 0.0, 2300.0);
    
    smc_data.w1 = w1;
    smc_data.w2 = w2;
    smc_data.w3 = w3;
    smc_data.w4 = w4;


    /*------------------ Saturation and publish ----------------*/
    uav_msgs::msg::UavCmd motor_cmd;
    
    motor_cmd.w1 = w1;
    motor_cmd.w2 = w2;
    motor_cmd.w3 = w3;
    motor_cmd.w4 = w4;

    motor_pub_->publish(motor_cmd);

    att_err_->publish(att_err);
    att_err_dot_->publish(att_err_dot);
    slide_sur_->publish(slide_sur);
}


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Controller>());
    rclcpp::shutdown();
    return 0;
}