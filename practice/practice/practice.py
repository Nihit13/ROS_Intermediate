import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class MyNode(Node):
    def __init__(self):
        super().__init__('my_node')

        # Publisher (publishes to 'chatter' topic every second)
        self.publisher_ = self.create_publisher(String, 'chatter', 10)

        # Timer (calls timer_callback every 1 second)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.counter = 0

        # Subscriber (listens to 'chatter' topic)
        self.subscription = self.create_subscription(
            String,
            'chatter',
            self.listener_callback,
            10
        )

        self.get_logger().info('Node has been started.')

    def timer_callback(self):
        msg = String()
        msg.data = f'Hello ROS 2! Count: {self.counter}'
        self.publisher_.publish(msg)
        self.get_logger().info(f'Published: "{msg.data}"')
        self.counter += 1

    def listener_callback(self, msg):
        self.get_logger().info(f'Received: "{msg.data}"')


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

