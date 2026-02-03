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

    m.sub = ros_node_->create_subscription<std_msgs::msg::Float64>("motor_cmd_" + std::to_string(i),
      10,
      [this, i](std_msgs::msg::Float64::SharedPtr msg)
      {
        motors_[i].command = std::clamp(msg->data, 0.0, 1.0);
      }
    );
    motors_.push_back(m);
  }
  update_connection_ = event::Events::ConnectWorldUpdateBegin(
    std::bind(&QuadMotorPlugin::OnUpdate, this)
  );
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
