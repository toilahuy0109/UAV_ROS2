#include "uav_cmd_pub.hpp"

UavCmdPublisher::UavCmdPublisher()
: Node("uav_cmd_pub")
{
    sub_joy_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "joy", 10,
        std::bind(&UavCmdPublisher::joy_callback, this, std::placeholders::_1)
    );

    for (int i = 0; i < 4; i++)
    {
        auto pub = this->create_publisher<std_msgs::msg::Float64>("motor_cmd_" + std::to_string(i), 10);
        pubs_.push_back(pub);
    }

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&UavCmdPublisher::publish_command, this)
    );
}

void UavCmdPublisher::joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
    for (int i = 0; i < 4; i++)
    {
        auto msg = std_msgs::msg::Float64();
        
    }
}

void UavCmdPublisher::publish_command()
{
    for (int i = 0; i < 4; i++)
    {
        auto msg = std_msgs::msg::Float64();
        if (i == 0 || i == 1)
        {
            msg.data = 0.38;
        }
        else msg.data = 0.38;
        pubs_[i]->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Publishing motor_cmd_%d: %f", i, msg.data);
    }
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<UavCmdPublisher>());
    rclcpp::shutdown();
    return 0;
}
