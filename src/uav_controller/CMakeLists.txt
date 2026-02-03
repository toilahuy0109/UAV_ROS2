cmake_minimum_required(VERSION 3.8)
project(uav_controller)

# Nếu dùng C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Tìm các package cần thiết
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

# Thêm source code
add_executable(imu_node
  src/imu_read.cpp
)


ament_target_dependencies(imu_node
    rclcpp
    sensor_msgs
)

target_include_directories(imu_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


# Cài đặt binary
install(
  TARGETS 
  imu_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
