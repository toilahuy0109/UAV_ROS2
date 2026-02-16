#include "uav_motor_plugin.hpp"

namespace gazebo
{

void QuadMotorPlugin::Load(physics::ModelPtr model, sdf::ElementPtr sdf)
{
  model_ = model;

  // ROS2 node
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ros_node_ = rclcpp::Node::make_shared("quad_motor_plugin");
  vel_cmd_ = ros_node_->create_subscription<uav_msgs::msg::UavCmd>(
    "/motor_vel", 10,
    std::bind(&QuadMotorPlugin::CommandCallback, this, std::placeholders::_1)
  );

  // Read config of 4 motors
  for (int i = 0; i < 4; i++)
  {
    std::string link_name = sdf->Get<std::string>("motor_" + std::to_string(i) + "_link");
    double thrust_coeff = sdf->Get<double>("motor_" + std::to_string(i) + "_thrust_coeff", 1.0).first;
    double torque_coeff = sdf->Get<double>("motor_" + std::to_string(i) + "_torque_coeff", 0.05).first;
    int direction = sdf->Get<int>("motor_" + std::to_string(i) + "_direction", 1).first;

    Motor m;
    m.link = model_->GetLink(link_name);
    m.thrust_coeff = thrust_coeff;
    m.torque_coeff = torque_coeff;
    m.direction = direction;
    m.command = 0.0;

    motors_.push_back(m);
  }
  update_connection_ = event::Events::ConnectWorldUpdateBegin(
    std::bind(&QuadMotorPlugin::OnUpdate, this)
  );
}

void QuadMotorPlugin::CommandCallback(const uav_msgs::msg::UavCmd::SharedPtr msg)
{
  motors_[0].command = msg->w1;
  motors_[1].command = msg->w2;
  motors_[2].command = msg->w3;
  motors_[3].command = msg->w4;
}

void QuadMotorPlugin::OnUpdate()
{
  for (auto &m : motors_)
  {
    double thrust = m.thrust_coeff * m.command * m.command;
    double torque = m.torque_coeff * thrust * m.direction;

    m.link->AddRelativeForce(ignition::math::Vector3d(0, 0, thrust));

    m.link->AddRelativeTorque(ignition::math::Vector3d(0, 0, torque));
  }
  rclcpp::spin_some(ros_node_);
}
}
