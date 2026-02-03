#pragma once
#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <eigen3/Eigen/Dense>
#include <memory>

namespace drone_drive_ros2
{
    class DroneOdometry
    {
        public:
        explicit DroneOdometry(rclcpp::Node* node, const std::string& drone_namespace);
        ~DroneOdometry() = default;

        // Update status from IMU data
        void updateFromImu(const sensor_msgs::msg::Imu::SharedPtr imu_msg);

        // Update status from motor speeds (use for simulation)
        void updateFromMotorSpeeds(const Eigen::Vector4d& motor_speeds, double dt);

        // Update status from control signal
        void updateFromCmdVel(const geometry_msgs::msg::Twist& cmd_vel, double dt);

        // Public getter
        const Eigen::Vector3d& getPosition() const {return position_;}
        const Eigen::Quaterniond& getOrientation() const { return orientation_; }
        const Eigen::Vector3d& getLinearVelocity() const { return linear_velocity_; }
        const Eigen::Vector3d& getAngularVelocity() const { return angular_velocity_; }

        private:
        // Initialize physical parameters
        void initializeParameters();
        
        // Calculate force and momentum from motor speed
        void calculateForcesAndTorques(const Eigen::Vector4d& motor_speeds, Eigen::Vector3d& force, Eigen::Vector3d& torque);

        // Calculate integrate dynamic equation
        void integrateDynamics(const Eigen::Vector3d& force, const Eigen::Vector3d& torque, double dt);

        // Normalize quaternion
        void normalizeQuaternion();

        // ROS2 components
        rclcpp::Node* node_;
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;


        // Drone state
        Eigen::Vector3d position_;
        Eigen::Quaterniond orientation_;
        Eigen::Vector3d linear_velocity_;
        Eigen::Vector3d angular_velocity_;

        // Drone physical parameters
        struct DroneParams
        {
            double mass;
            double arm_length;
            double thrust_coefficient;
            double drag_coefficient;
            double inertia_xx;
            double inertia_yy;
            double inertia_zz;
        } params_;

        std::string drone_namespace_;
        bool use_imu_;
        rclcpp::Time last_update_time_;
    };
}