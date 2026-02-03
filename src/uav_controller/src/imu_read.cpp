#include "imu_read.hpp"

ImuSubscriber::ImuSubscriber() : Node("imu_subscriber")
{
    subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "/drone/imu_plugin/out",
        10,
        std::bind(&ImuSubscriber::callback, this, std::placeholders::_1)
    );
}

void ImuSubscriber::callback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(),
        "Orientation: x=%.3f, y=%.3f, z=%.3f, w=%.3f",
        msg->orientation.x,
        msg->orientation.y,
        msg->orientation.z,
        msg->orientation.w
    );

    RCLCPP_INFO(this->get_logger(),
        "Angular vel: x=%.3f, y=%.3f, z=%.3f",
        msg->angular_velocity.x,
        msg->angular_velocity.y,
        msg->angular_velocity.z
    );

    RCLCPP_INFO(this->get_logger(),
        "Linear acc: x=%.3f, y=%.3f, z=%.3f",
        msg->linear_acceleration.x,
        msg->linear_acceleration.y,
        msg->linear_acceleration.z
    );
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ImuSubscriber>());
    rclcpp::shutdown();
    return 0;
}