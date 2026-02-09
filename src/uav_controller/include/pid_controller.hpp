#pragma once

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"


class PID
{
    public:
    PID(double kp, double ki, double kd, double Ts);

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
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr attitude_ref_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr thrust_ref_pub_;
    rclcpp::TimerBase::SharedPtr control_timer_;

    // State
    double x_, y_, z_;
    double vx_, vy_, vz_;

    // Reference
    double x_ref_, y_ref_, z_ref_, yaw_ref_;

    // PID
    std::shared_ptr<PID> pid_x_;
    std::shared_ptr<PID> pid_y_;
    std::shared_ptr<PID> pid_z_;
    double Ts_;
    rclcpp:: Time start_time_;

    // Constants
    const double g_;

    // Callback
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void controlLoop();
};

