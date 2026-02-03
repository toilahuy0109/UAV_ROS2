#pragma once

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"

class ImuSubscriber : public rclcpp::Node
{
    public:
    explicit ImuSubscriber();

    private:
    void callback(const sensor_msgs::msg::Imu::SharedPtr msg);
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription_;
};