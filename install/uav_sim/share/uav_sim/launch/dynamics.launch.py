from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def genderate_launch_description():
    return LaunchDescription([
        ExecuteProcess(
            cmd=['gazebo', '--verbose', 'world/']
        )
    ])