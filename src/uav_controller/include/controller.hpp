#pragma once

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "uav_msgs/msg/uav_cmd.hpp"



// To calculate e_dot
struct DerivativePID
{
    double ex, ey, ez;

    int tick;

    DerivativePID() : ex(0.0), ey(0.0), ez(0.0), tick(0) {};
};

// To calculate att_dot, att_ref_dot, att_ref_ddot
struct DerivativeSMC
{
    double phi_, theta_, psi_;
    double ephi_, etheta_, epsi_;
    double phi_ref_, theta_ref_, psi_ref_;
    double phi_ref_dot, theta_ref_dot, psi_ref_dot;

    double w1, w2, w3, w4;

    DerivativeSMC() : phi_(0.0), theta_(0.0), psi_(0.0),
                        ephi_(0.0), etheta_(0.0), epsi_(0.0),
                        phi_ref_(0.0), theta_ref_(0.0), psi_ref_(0.0),
                        phi_ref_dot(0.0), theta_ref_dot(0.0), psi_ref_dot(0.0),
                        w1(0.0), w2(0.0), w3(0.0), w4(0.0)
    {}
};


class PID
{
    public:
    PID(double kp, double ki, double kd);
    double get_integral();

    double update(double e, double Ts_);
    
    private:
    double kp_, ki_, kd_;
    double integral_ = 0.0;
    double eps_;
    double N_;
    double prev_error_ = 0.0;
    double derivative_ = 0.0;
    
};

class SMC
{
    public:
    SMC(double lambda, double k);

    double update(double e, double edot);
    double get_slide(double e, double edot);
    double get_lambda();

    private:
    double lambda_;
    double k_;
};

class Controller : public rclcpp::Node
{
    public:
    explicit Controller();

    // Callback
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void controlLoop(const sensor_msgs::msg::Imu::SharedPtr msg);

    private:

    // Publisher for show node
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr pos_err_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr pos_dot_err_;

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr attitude_ref_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr thrust_ref_pub_;

    // For SMC controller
    rclcpp::Publisher<uav_msgs::msg::UavCmd>::SharedPtr motor_pub_;

    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr att_err_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr att_err_dot_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr slide_sur_;

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;

    // State
    double x_, y_, z_;

    double phi_, theta_, psi_;

    DerivativePID pid_data;
    DerivativeSMC smc_data;

    // Reference
    double x_ref_, y_ref_, z_ref_, yaw_ref_;

    // PID
    std::shared_ptr<PID> pid_x_;
    std::shared_ptr<PID> pid_y_;
    std::shared_ptr<PID> pid_z_;

    std::shared_ptr<SMC> smc_phi_;
    std::shared_ptr<SMC> smc_theta_;
    std::shared_ptr<SMC> smc_psi_;

    double Ts_pid;
    double Ts_smc;

    rclcpp::Time start_time_;
    rclcpp::Time prev_time_pid;
    rclcpp::Time prev_time_smc;

    double phi_ref, theta_ref, psi_ref;
    double thrust_ref;

    // Constants
    const double g_ = 9.8;
    const double m_ = 1.5;
    const double Ix_ = 0.0211;
    const double Iy_ = 0.0219;
    const double Iz_ = 0.0366;
    const double Jr_ = 0.0;

    const double length_ = 0.156;
    const double b_ = 1.105e-5;
    const double d_ = 3.558e-7;

    double k1_ = 10.0;
}; 

