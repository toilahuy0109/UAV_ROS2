#pragma once

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/float64.hpp"


class UavCmdPublisher : public rclcpp::Node
{
    public:
    explicit UavCmdPublisher();

    private:
    void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg);
    void publish_command();

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr cmd_pub_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub_joy_;
    std::vector<rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr> pubs_;

    rclcpp::TimerBase::SharedPtr timer_;
};