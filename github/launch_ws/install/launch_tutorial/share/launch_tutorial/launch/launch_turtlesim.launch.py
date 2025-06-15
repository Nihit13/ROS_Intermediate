from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import PushRosNamespace
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    launch_dir = PathJoinSubstitution([
        FindPackageShare('launch_tutorial'), 'launch'
    ])

    return LaunchDescription([
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([launch_dir, 'turtlesim_world_1.launch.py'])
            )
        ),

        
        GroupAction(
            actions=[
                PushRosNamespace('turtlesim2'),
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(
                        PathJoinSubstitution([launch_dir, 'turtlesim_world_2.launch.py'])
                    )
                )
            ]
        ),

        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([launch_dir, 'broadcaster_listener.launch.py'])
            ),
            launch_arguments={'target_frame': 'carrot1'}.items()
        ),

        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([launch_dir, 'mimic.launch.py'])
            )
        ),

        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([launch_dir, 'fixed_broadcaster.launch.py'])
            )
        ),

        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([launch_dir, 'turtlesim_rviz.launch.py'])
            )
        ),
    ])

