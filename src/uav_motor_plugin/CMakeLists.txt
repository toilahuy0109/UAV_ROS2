cmake_minimum_required(VERSION 3.8)
project(uav_motor_plugin)

find_package(ament_cmake REQUIRED)
find_package(gazebo_dev REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(uav_msgs REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
  ${gazebo_dev_INCLUDE_DIRS}
)

add_library(uav_motor_plugin SHARED
  src/uav_motor_plugin.cpp
)

ament_target_dependencies(uav_motor_plugin
  rclcpp
  std_msgs
  gazebo_ros
  uav_msgs
)

target_link_libraries(uav_motor_plugin
  ${gazebo_dev_LIBRARIES}
)

install(
  TARGETS uav_motor_plugin
  LIBRARY DESTINATION lib
)

ament_package()
