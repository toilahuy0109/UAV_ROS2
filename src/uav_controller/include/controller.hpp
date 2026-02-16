#pragma once

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "uav_msgs/msg/uav_cmd.hpp"

struct DerivativeMemory
{
    double prev;
    bool initialized;

    DerivativeMemory() : prev(0.0), initialized(false)
    {}
};


// To calculate e_dot
struct DerivativePID
{
    double ex, ey, ez;

    PrevData() : ex(0.0), ey(0.0), ez(0.0) {};
};


class PID
{
    public:
    PID(double kp, double ki, double kd, double Ts);
    double get_integral();

    double update(double e, double edot);
    
    private:
    double kp_, ki_, kd_, Ts_;
    double integral_;
    double eps_;
    double N_;
    double prev_error_;
    double derivative_;
    
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
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);
    void controlLoop();

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
    double x_dot_, y_dot_, z_dot_;

    double phi_, theta_, psi_;
    double phi_dot_, theta_dot_, psi_dot_;

    PrevData prev;

    // Reference
    double x_ref_, y_ref_, z_ref_, yaw_ref_;

    double phi_, theta_, psi_;

    // PID
    std::shared_ptr<PID> pid_x_;
    std::shared_ptr<PID> pid_y_;
    std::shared_ptr<PID> pid_z_;
    double Ts_;
    rclcpp:: Time start_time_;

    // Constants
    const double g_ = 9.8;
    double m_ = 1.5;
};

