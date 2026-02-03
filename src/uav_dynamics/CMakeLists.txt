cmake_minimum_required(VERSION 3.8)
project(uav_dynamics)

# Nếu dùng C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Tìm các package cần thiết
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(uav_msgs REQUIRED)  # nếu bạn có package message riêng
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# Thêm source code
add_executable(dynamics_node
  src/dynamics_node.cpp
  src/uav_model.cpp
)

add_executable(cmd_pub_node
  src/uav_cmd_pub.cpp
)

ament_target_dependencies(dynamics_node
    rclcpp
    uav_msgs
)

ament_target_dependencies(cmd_pub_node
    rclcpp
    std_msgs
    sensor_msgs
)

target_include_directories(dynamics_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(cmd_pub_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Cài đặt binary
install(
  TARGETS 
  dynamics_node
  cmd_pub_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
