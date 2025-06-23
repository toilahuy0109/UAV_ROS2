from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        #Node joy
        Node(
            package = 'joy',
            executable = 'joy_node',
            name = 'joy_node',
            output = 'screen',
        ),

        #Node ps4_controller
        Node(
            package = 'ps4_controller',
            executable = 'ps4_controller_node',
            name = 'ps4_controller_node',
            output = 'screen',
        ),
        #Node servo_controller 
        Node(
            package = 'ps4_controller',
            executable = 'servo_controller_node',
            name = 'servo_controller_node',
            output = 'screen',
        )
    ])