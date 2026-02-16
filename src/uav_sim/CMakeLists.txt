cmake_minimum_required(VERSION 3.8)
project(uav_sim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(uav_msgs REQUIRED)

add_executable(data_node
  src/show_data.cpp
)

ament_target_dependencies(data_node
  rclcpp
  geometry_msgs
  std_msgs
  nav_msgs
  uav_msgs
)

target_include_directories(data_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Cài launch files
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# Cài models (SDF, world)
install(
  DIRECTORY models
  DESTINATION share/${PROJECT_NAME}
)

# Cai dat binary
install(
  TARGETS
  data_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
