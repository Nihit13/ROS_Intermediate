import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Subscriber(Node):
    def __init__(self):
        super().__init__('sub_key1')
        self.subscription = self.create_subscription(
            String,
            'topic_command',
            self.command_callback,
            10
        )
        self.get_logger().info('Subscriber started and waiting for commands...')

    def command_callback(self, msg):
        command = msg.data
        if command == 'forward':
            self.get_logger().info('Robot moving forward')
        elif command == 'backward':
            self.get_logger().info('Robot moving backward')
        elif command == 'left':
            self.get_logger().info('Robot turning left')
        elif command == 'right':
            self.get_logger().info('Robot turning right')
        elif command == 'stop':
            self.get_logger().info('Robot stopping')
        else:
            self.get_logger().warn(f"Unknown command: {command}")

def main(args=None):
    rclpy.init(args=args)
    node = Subscriber()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
