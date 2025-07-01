# import os
# from ament_index_python.packages import get_package_share_directory

# from launch import LaunchDescription
# from launch.substitutions import LaunchConfiguration, Command
# from launch.actions import DeclareLaunchArgument
# from launch_ros.actions import Node

# import xacro

# from launch.actions import IncludeLaunchDescription
# from launch.launch_description_sources import PythonLaunchDescriptionSource


# def generate_launch_description():
#     use_sim_time = LaunchConfiguration('use_sim_time')


#     #URDF process
#     pkg_path = os.path.join(get_package_share_directory('my_robot_pkg'))
#     xacro_file = os.path.join(pkg_path,'description','drone.urdf.xacro')
#     robot_description_config = xacro.process_file(xacro_file)
#     controller_file = os.path.join(pkg_path,'config','drone_controller.yaml')

#     # Create a robot_state_publisher node
#     params = {'robot_description': Command(['xacro',xacro_file]), 'use_sim_time': use_sim_time}
    
#     node_robot_state_publisher = Node(
#         package = 'robot_state_publisher',
#         executable='robot_state_publisher',
#         namespace='drone',
#         name='robot_state_publisher',
#         output='screen',
#         parameters=[params]
#     )

#     ps4 = IncludeLaunchDescription(
#         PythonLaunchDescriptionSource([os.path.join(
#             get_package_share_directory('my_robot_pkg'),'launch','ps4_init.launch.py'
#         )]),
#     )

#     gazebo = IncludeLaunchDescription(
#         PythonLaunchDescriptionSource([
#             os.path.join(
#                 get_package_share_directory('gazebo_ros'),'launch','gazebo.launch.py'
#             )
#         ]),
#     )

#     spawn_entity = Node(package="gazebo_ros", executable="spawn_entity.py",
#                         arguments=['-entity','drone','-topic','robot_description','-x','0','-y','0','-z','0.1'],output='screen')


#     controller_manager = Node(
#         package='controller_manager',
#         executable='spawner',
#         arguments=['joint_state_broadcaster'],
#         output='screen'
#     )

#     # Launch
#     return LaunchDescription([

#         DeclareLaunchArgument(
#             'use_sim_time',
#             default_value='false',
#             description='Use sim time if true'
#         ),
#         node_robot_state_publisher,
#         ps4,
#         gazebo,
#         spawn_entity,
#         Node(
#             package='controller_manager',
#             executable='ros2_control_node',
#             parameters=[controller_file,{'use_sim_time':'True'}],
#             output='screen'
#         ),
#         controller_manager,
#         Node(
#             package='my_robot_pkg',
#             executable='drone_controller',
#             name='drone_controller',
#             output='screen'
#         ),
#         Node(
#             package='controller_manager',
#             executable='spawner',
#             arguments=['velocity_controller','--control-manager','/controller_manager'],
#             output='screen'
#         ),
#         Node(
#             package='controller_manager',
#             executable='spawner',
#             arguments=['joint_state_broadcaster','--controller-manager','/controller_manager'],
#             output='screen'
#         ),

#     ])
    




from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess, DeclareLaunchArgument
from launch.substitutions import Command, LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    pkg_share = get_package_share_directory('my_robot_pkg')
    urdf_file = os.path.join(pkg_share, 'description', 'drone.urdf.xacro')
    controller_file = os.path.join(pkg_share, 'config', 'drone_controller.yaml')

    return LaunchDescription([
        # Declare Gazebo world file (optional)
        DeclareLaunchArgument(
            'world', default_value='',
            description='SDF world file'
        ),

        # Start Gazebo server
        ExecuteProcess(
            cmd=['gzserver', '--verbose', '-s', 'libgazebo_ros_factory.so', LaunchConfiguration('world')],
            output='screen'
        ),

        # Start Gazebo client
        ExecuteProcess(
            cmd=['gzclient', '--verbose'],
            output='screen'
        ),

        # Robot state publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            namespace='drone',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': Command(['xacro ', urdf_file]), 'use_sim_time': True}]
        ),

        # Spawn the drone
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=['-entity', 'drone', '-topic', 'robot_description', '-x', '0', '-y', '0', '-z', '0.1'],
            output='screen'
        ),

        # ROS2 Control node
        Node(
            package='controller_manager',
            executable='ros2_control_node',
            parameters=[controller_file, {'use_sim_time': True}],
            output='screen'
        ),

        # Spawn joint_state_broadcaster
        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'],
            output='screen'
        ),

        # Spawn velocity_controller
        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['velocity_controller', '--controller-manager', '/controller_manager'],
            output='screen'
        ),

        # Drone controller
        Node(
            package='my_robot_pkg',
            executable='drone_controller',
            name='drone_controller',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),

        # Joy node for PS4 controller
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),

        # PS4 controller node
        Node(
            package='my_robot_pkg',
            executable='ps4_controller_node',
            name='ps4_controller_node',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),

        # RViz2
        Node(
            package='rviz2',
            executable='rviz2',
            namespace='drone',
            name='rviz2',
            output='screen',
            parameters=[{'use_sim_time': True}]
        )
    ])