from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'topic',
            default_value='topic1'
        ),
        Node(
            name="talker",
            executable="talker",
            package="choose_topic",
            parameters=[{
                "topic": "topic1"
            }]
        ),
        Node(
            name="talker2",
            executable="talker",
            package="choose_topic",
            parameters=[{
                "topic": "topic2"
            }]
        ),
        Node(
            name="sub",
            executable="listener",
            package="choose_topic",
            parameters=[{
                "topic": LaunchConfiguration("topic")
            }]
        ),
    ])