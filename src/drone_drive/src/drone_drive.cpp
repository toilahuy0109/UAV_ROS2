#include "drone_drive/drone_drive.hpp"

namespace drone_drive_ros2
{
    DroneDrive::DroneDrive(const rclcpp::NodeOptions & options) : Node("drone_drive", options)
    {
        // Declare and get parameters
        this->declare_parameter<std::string>("namespace","");
        this->declare_parameter<double>("mass",1.5);
        this->declare_parameter<double>("arm_length",0.3);
        this->declare_parameter<double>("max_thrust",20.0);

        drone_namespace_ = this->get_parameter("namespace").as_string();
        mass_ = this->get_parameter("mass").as_double();
        arm_length_ = this->get_parameter("arm_length").as_double();
        max_thrust_ = this->get_parameter("max_thrust").as_double();

        // Create Oos profile
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10));

        // Initialize publishers/subcribers
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel", qos, std::bind(&DroneDrive::cmdVelCallback, this, std::placeholders::_1));

        motor_speed_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("motor_speed", qos);

        odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", qos);

        // Initialize odometry timer (50Hz)
        odom_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20),
            std::bind(&DroneDrive::updateOdometry, this)
        );
        
        // Initialize state
        position_ = Eigen::Vector3d::Zero();
        orientation_ = Eigen::Quaterniond::Identity();
        last_update_ = this->now();
    }

    Eigen::Vector4d DroneDrive::calculateMotorSpeeds(const geometry_msgs::msg::Twist & msg)
    {
        Eigen::Vector4d speeds;

        // Thrust (Vertical)
        double thrust = msg.linear.z;
        
        // Roll (x-axis rotation)
        double roll = msg.angular.x;

        // Pitch (y-axis rotation)
        double pitch = msg.angular.y;

        // Yaw (z-axis rotation)
        double yaw = msg.angular.z;

        // Motor mixing for X configuration
        speeds[0] = thrust - roll + pitch - yaw;
        speeds[1] = thrust + roll + pitch + yaw;
        speeds[2] = thrust - roll - pitch + yaw;
        speeds[3] = thrust + roll - pitch - yaw;

        // Normalize motor speeds
        speeds = speeds.cwiseMax(0).cwiseMin(max_thrust_);

        return speeds;
    }

    void DroneDrive::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        // Calculate motor speeds
        Eigen::Vector4d motor_speeds = calculateMotorSpeeds(*msg);

        // Publish motor speeds
        auto motor_cmd = std::make_unique<geometry_msgs::msg::Twist>();
        motor_cmd->linear.x = motor_speeds[0];
        motor_cmd->linear.y = motor_speeds[1];
        motor_cmd->linear.z = motor_speeds[2];
        motor_cmd->angular.x = motor_speeds[3];

        motor_speed_pub_->publish(std::move(motor_cmd));
    }

    void DroneDrive::updateOdometry()
    {
        // Simplified odometry update - integrate motor speeds

        auto current_time = this->now();
        double dt = (current_time - last_update_).seconds();
        last_update_ = current_time;

        // Create odometry message
        auto odom = std::make_unique<nav_msgs::msg::Odometry>();
        odom->header.stamp = current_time;
        odom->header.frame_id = drone_namespace_ + "/odom";
        odom->child_frame_id = drone_namespace_ + "/base_link";

        // TODO: Implement proper odometry calculation
        // For now just publish identity
        odom->pose.pose.position.x = position_.x();
        odom->pose.pose.position.y = position_.y();
        odom->pose.pose.position.z = position_.z();
        odom->pose.pose.orientation.x = orientation_.x();
        odom->pose.pose.orientation.y = orientation_.y();
        odom->pose.pose.orientation.z = orientation_.z();
        odom->pose.pose.orientation.w = orientation_.w();

        odom_pub_->publish(std::move(odom));

        // Publish transform
        geometry_msgs::msg::TransformStamped transform;
        transform.header.stamp = current_time;
        transform.header.frame_id = drone_namespace_ + "/odom";
        transform.child_frame_id = drone_namespace_ + "/base_link";
        transform.transform.translation.x = position_.x();
        transform.transform.translation.y = position_.y();
        transform.transform.translation.z = position_.z();
        transform.transform.rotation.x = orientation_.x();
        transform.transform.rotation.y = orientation_.y();
        transform.transform.rotation.z = orientation_.z();
        transform.transform.rotation.w = orientation_.w();

        tf_broadcaster_->sendTransform(transform);
    }
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(drone_drive_ros2::DroneDrive)