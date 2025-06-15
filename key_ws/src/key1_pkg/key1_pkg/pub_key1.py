import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Keyboard(Node):
    def __init__(self):
        super().__init__('pub_key1')
        self.publisher_ = self.create_publisher(String, 'topic_command', 10)
        self.get_logger().info('Keyboard Publisher started. Use keys: W/A/S/D/X')

        self.run()

    def run(self):
        while rclpy.ok():
            key = input("Enter command (W/A/S/D/X): ").upper()

            msg = String()
            if key == 'W':
                msg.data = 'forward'
            elif key == 'S':
                msg.data = 'backward'
            elif key == 'A':
                msg.data = 'left'
            elif key == 'D':
                msg.data = 'right'
            elif key == 'X':
                msg.data = 'stop'
            else:
                self.get_logger().warn("Invalid key. Use W/A/S/D/X.")
                continue

            self.publisher_.publish(msg)
            self.get_logger().info(f"Published command: '{msg.data}'")

def main(args=None):
    rclpy.init(args=args)
    node = Keyboard()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
