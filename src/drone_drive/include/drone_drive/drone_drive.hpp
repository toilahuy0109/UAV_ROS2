#pragma once
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <eigen3/Eigen/Dense>

namespace drone_drive_ros2
{
    class DroneDrive : public rclcpp::Node
    {
        public:
        DroneDrive(const rclcpp::NodeOptions & options);
        
        private:
        void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
        void updateOdometry();

        Eigen::Vector4d calculateMotorSpeeds(const geometry_msgs::msg::Twist & msg);

        // ROS2 components
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr motor_speed_pub_;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

        // Timer for odometry update
        rclcpp::TimerBase::SharedPtr odom_timer_;

        // Drone parameters
        std::string drone_namespace_;
        double mass_;
        double arm_length_;
        double max_thrust_;

        // Odometry state
        Eigen::Vector3d position_;
        Eigen::Quaterniond orientation_;
        rclcpp::Time last_update_;
    };
};