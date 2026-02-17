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
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(uav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

# Thêm source code
add_executable(controller_node
  src/controller.cpp
)

add_executable(pos_controller_node
  src/pid_controller.cpp
)

add_executable(smc_controller_node
  src/smc_controller.cpp
)


ament_target_dependencies(controller_node
    rclcpp
    sensor_msgs
    geometry_msgs
    std_msgs
    nav_msgs
    tf2
    tf2_ros
    tf2_geometry_msgs
    uav_msgs
)

ament_target_dependencies(pos_controller_node
  rclcpp
  geometry_msgs
  std_msgs
  nav_msgs
  sensor_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
)

ament_target_dependencies(smc_controller_node
  rclcpp
  sensor_msgs
  geometry_msgs
  std_msgs
  uav_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
)

target_include_directories(controller_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(pos_controller_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(smc_controller_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)


# Cài đặt binary
install(
  TARGETS 
  controller_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  TARGETS
  pos_controller_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  TARGETS
  smc_controller_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
