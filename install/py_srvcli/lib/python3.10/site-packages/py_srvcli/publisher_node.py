import rclpy
from rclpy.node import Node
from tutorial_interfaces.msg import Num



class PublisherNode(Node):
    def __init__(self):
        super().__init__('publisher_node')
        self.publisher_ = self.create_publisher(Num, 'topic', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.count = 0

    def timer_callback(self):
        msg = Num()
        msg.num = self.count
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.num}')
        self.count += 5

    
def main(args=None):
    args= args
    rclpy.init(args=args)

    publisher_node = PublisherNode()

    rclpy.spin(publisher_node)

    publisher_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
