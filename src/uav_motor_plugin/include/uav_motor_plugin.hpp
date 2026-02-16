#pragma once

#include <gazebo/gazebo.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/Events.hh>

#include <rclcpp/rclcpp.hpp>
#include "uav_msgs/msg/uav_cmd.hpp"
#include <std_msgs/msg/float64.hpp>
#include <std_msgs/msg/bool.hpp>
#include <ignition/math/Vector3.hh>

namespace gazebo
{
    class QuadMotorPlugin : public ModelPlugin
    {
        public:
        void Load(physics::ModelPtr model, sdf::ElementPtr sdf) override;

        private:
        void OnUpdate();
        void CommandCallback(const uav_msgs::msg::UavCmd::SharedPtr msg);

        // Gazebo
        struct Motor 
        {
            physics::LinkPtr link;
            double thrust_coeff;
            double torque_coeff;
            int direction;
            double command;
        };

        physics::ModelPtr model_;
        rclcpp::Node::SharedPtr ros_node_;
        event::ConnectionPtr update_connection_;
        std::vector<Motor> motors_;
        rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr run_cmd;
        rclcpp::Subscription<uav_msgs::msg::UavCmd>::SharedPtr vel_cmd_;
        bool run = false;
    };
    GZ_REGISTER_MODEL_PLUGIN(QuadMotorPlugin)
}