cmake_minimum_required(VERSION 3.8)
project(uav_msgs)

# Nếu chưa set chuẩn C++
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Khai báo các file msg/srv/action
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/UavState.msg"
  "msg/UavCmd.msg"
)

# Xuất runtime dependency để các package khác dùng được
ament_export_dependencies(rosidl_default_runtime)

ament_package()
