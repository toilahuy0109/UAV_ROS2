#include "dynamics_node.hpp"

using namespace std::chrono_literals;

DynamicsNode::DynamicsNode(double dt)
: Node("uav_dynamics"),
model_(0.01)
{
    cmd_sub_ = create_subscription<uav_msgs::msg::UavCmd>(
        "cmd", 10,
        std::bind(&DynamicsNode::cmdCallback, this, std::placeholders::_1)
    );

    state_pub_ = create_publisher<uav_msgs::msg::UavState>("state", 10);

    timer_ = create_wall_timer(
        10ms, std::bind(&DynamicsNode::update, this)
    );
}

void DynamicsNode::cmdCallback(const uav_msgs::msg::UavCmd::SharedPtr msg)
{
    
}

void DynamicsNode::update()
{
    model_.step();
    auto s = model_.getState();

    uav_msgs::msg::UavState msg;
    msg.x = s[0];
    msg.y = s[1];
    msg.z = s[2];
    msg.vx = s[3];
    msg.vy = s[4];
    msg.vz = s[5];

    state_pub_->publish(msg);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DynamicsNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}