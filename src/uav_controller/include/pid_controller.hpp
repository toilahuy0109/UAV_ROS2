#pragma once

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/imu.hpp"

struct PrevData
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
    double imax_;
    double eps_;
    
};

class Pos_Controller : public rclcpp::Node
{
    public:
    explicit Pos_Controller();

    private:

    // Publisher for show node
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr pos_err_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr pos_dot_err_;

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr attitude_ref_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr thrust_ref_pub_;

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    rclcpp::TimerBase::SharedPtr control_timer_;

    // State
    double x_, y_, z_;
    double x_dot_, y_dot_, z_dot_;

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
    const double g_;
    double m_ = 1.4;

    // Callback
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);
    void controlLoop();
};

