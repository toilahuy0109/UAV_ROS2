#pragma once
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <eigen3/Eigen/Dense>

namespace drone_drive_ros2 {

class DroneDrive : public rclcpp::Node {
public:
    explicit DroneDrive(const rclcpp::NodeOptions & options);
    
private:
    // ROS2 components
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr motor_speeds_pub_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    
    // Timers
    rclcpp::TimerBase::SharedPtr control_timer_;
    rclcpp::TimerBase::SharedPtr odom_timer_;

    // Callbacks
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);
    void controlUpdate();
    void odomUpdate();
    
    // Motor control
    Eigen::Vector4d calculateMotorSpeeds(const geometry_msgs::msg::Twist & cmd);
    void publishMotorCommands(const Eigen::Vector4d & speeds);
    
    // Drone state
    struct DroneState {
        Eigen::Vector3d position;
        Eigen::Vector3d velocity;
        Eigen::Quaterniond orientation;
        Eigen::Vector3d angular_velocity;
    } current_state_;
    
    // Parameters
    struct {
        double mass;
        double arm_length;
        double max_thrust;
        double thrust_coefficient;
        double drag_coefficient;
    } params_;
    
    // Utility functions
    void loadParameters();
    void initializePublishers();
    void initializeSubscribers();
};

} // namespace drone_drive_ros2