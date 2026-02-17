from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch.event_handlers import OnProcessExit
from launch.actions import RegisterEventHandler
from launch.actions import TimerAction
import os

def generate_launch_description():
    pkg_path = get_package_share_directory('uav_sim')
    world = os.path.join(pkg_path, 'models', 'uav_world.world')
    sdf = os.path.join(pkg_path, 'models', 'uav', 'drone.sdf')

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('gazebo_ros'),
                'launch',
                'gazebo.launch.py'
            )
        ),
        launch_arguments={'world' : world}.items(),
    )

    spawn = Node(
        package='gazebo_ros', 
        executable='spawn_entity.py',
        arguments=['-entity', 'uav',
                   '-file', sdf],
        output='screen'
    )

    controller = Node(
        package = 'uav_controller',
        executable='controller_node',
        output='screen'
    )

    pos_controller = Node(
        package='uav_controller',
        executable='pos_controller_node',
        output='screen'
    )

    att_controller = Node(
        package='uav_controller',
        executable='smc_controller_node',
        output='screen'
    )

    start_controllers = TimerAction(
        period = 5.0,
        actions = [controller]
    )

    return LaunchDescription([
        gazebo,
        spawn,
        start_controllers
    ])

