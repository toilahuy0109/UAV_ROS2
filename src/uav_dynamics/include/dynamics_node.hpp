#pragma once

#include "rclcpp/rclcpp.hpp"
#include "uav_model.hpp"
#include "uav_msgs/msg/uav_state.hpp"
#include "uav_msgs/msg/uav_cmd.hpp"

class DynamicsNode : public rclcpp::Node {
    public:
    explicit DynamicsNode(double dt = 0.01);

    private:
    void cmdCallback(const uav_msgs::msg::UavCmd::SharedPtr msg);
    void update();

    UavModel model_;

    // ROS interface
    rclcpp::Subscription<uav_msgs::msg::UavCmd>::SharedPtr cmd_sub_;
    rclcpp::Publisher<uav_msgs::msg::UavState>::SharedPtr state_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};