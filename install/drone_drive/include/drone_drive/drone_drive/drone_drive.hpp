#ifndef DRONE_GAZEBO_PLUGIN_DRONE_DIFF_DRIVE_HPP_
#define DRONE_GAZEBO_PLUGIN_DRONE_DIFF_DRIVE_HPP_

#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo_ros/node.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>


namespace gazebo
{
    class DroneDiffDrivePlugin : public ModelPlugin
    {
        public:
        DroneDiffDrivePlugin();
        void Load(gazebo::physics::ModelPtr model, sdf::ElementPtr sdf) override;

        protected:
        void OnUpdate();

        private:
        
        gazebo::physics::ModelPtr model_;
        gazebo::physics::LinkPtr base_link_;
        gazebo::event::ConnectionPtr update_connection_;

        //ROS components 
        gazebo_ros::Node::SharedPtr ros_node_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;
        std::string cmd_topic_;

        //Parameters

        double k_thrust_;
        double k_yaw_;
        double k_forward_;
        double max_rotor_vel_;
        double arm_length_;

        //Control inputs

        double linear_x_;
        double linear_z_;
        double angular_z_;

        void OnCmdVel(const geometry_msgs::msg::Twist::SharedPtr msg);
    };
}


#endif