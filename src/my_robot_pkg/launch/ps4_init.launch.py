import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    joy = Node(
        package = 'joy',
        executable = 'joy_node',
        name = 'joy_node',
        output = 'log',
    )

    controller = Node(
        package = 'my_robot_pkg',
        executable = 'ps4_controller_node',
        name = 'ps4_controller_node',
        output = 'log',
    )


    return LaunchDescription([
        joy,
        controller,
    ])