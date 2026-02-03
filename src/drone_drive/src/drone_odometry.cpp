#include "drone_drive/drone_odometry.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <chrono>

using namespace std::chrono_literals;

namespace drone_drive_ros2
{
    DroneOdometry::DroneOdometry(rclcpp::Node* node, const std::string& drone_namespace) : node_(node), drone_namespace_(drone_namespace)
    {
        // Initialize Parameters
        initializeParameters();

        // Initialize TF broadcaster
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*node);

        // Initialize publisher
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10));
        odom_pub_ = node_->create_publisher<nav_msgs::msg::Odometry>(
            drone_namespace_ + "/odom", qos
        );

        // Initialize begin status
        position_.setZero();
        orientation_.setIdentity();
        linear_velocity_.setZero();

        last_update_time_ = node_->now();

        RCLCPP_INFO(node_->get_logger(), "DroneOdometry initialize for %s", drone_namespace_.c_str());
    }

    void DroneOdometry::initializeParameters()
    {
        // Read data from node parameters
        params_.mass = node_->get_parameter("mass").as_double();
        params_.arm_length = node_->get_parameter("arm_length").as_double();
        params_.thrust_coefficient = node_->get_parameter("thrust_coefficient").as_double();
        params_.drag_coefficient = node_->get_parameter("drag_coefficient").as_double();
        
        // Default moment of inertia
        params_.inertia_xx = 0.1;
        params_.inertia_yy = 0.1;
        params_.inertia_zz = 0.1;

        use_imu_ = node_->get_parameter("use_imu").as_bool();
    }

    void DroneOdometry::updateFromImu(const sensor_msgs::msg::Imu::SharedPtr imu_msg)
    {
        
    }
}