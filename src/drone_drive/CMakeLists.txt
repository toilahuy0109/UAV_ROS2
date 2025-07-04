cmake_minimum_required(VERSION 3.8)
project(drone_drive)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(gazebo_dev REQUIRED)
find_package(gazebo_msgs REQUIRED)


# Include directories
include_directories(
  include
  ${gazebo_dev_INCLUDE_DIRS}
)

# Build plugin library
add_library(drone_drive SHARED 
  src/drone_drive.cpp
)

# Link libraries
target_link_libraries(drone_drive
  ${gazebo_dev_LIBRARIES}
)

# Add dependencies
ament_target_dependencies(drone_drive
  rclcpp
  geometry_msgs
  gazebo_ros
  gazebo_dev
  gazebo_msgs
)

# Install library
install(TARGETS
  drone_drive
  DESTINATION lib
)

# Install header files
install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

# Install package.xml
install(FILES package.xml
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
