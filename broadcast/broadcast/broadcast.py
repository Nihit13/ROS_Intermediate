import rclpy
from rclpy.node import Node

from std_msgs.msg import String

class Broadcast(Node):
  
  def __init__(self):
    super().__init__('broadcast_station')
    
    self.subscription1_1 = self.create_subscription(
            String,
            '/station1/platform1/trains',
            self.listener_callback,
            10)
    self.subscription1_2 = self.create_subscription(
            String,
            '/station1/platform2/trains',
            self.listener_callback,
            10)
    self.subscription1_1
    self.subscription1_2
    
    self.subscription2_1 = self.create_subscription(
            String,
            '/station2/platform1/trains',
            self.listener_callback,
            10)
    self.subscription2_2 = self.create_subscription(
            String,
            '/station2/platform2/trains',
            self.listener_callback,
            10)
    self.subscription2_1
    self.subscription2_2
    
    self.subscription3_1 = self.create_subscription(
            String,
            '/station3/platform1/trains',
            self.listener_callback,
            10)
    self.subscription3_2 = self.create_subscription(
            String,
            '/station3/platform2/trains',
            self.listener_callback,
            10)
    self.subscription3_1
    self.subscription3_2
            
  def listener_callback(self,msg):
    data_recieved = msg.data.split()
    self.get_logger().info('I heard: "%s"' % data_recieved[5])
    

def main():
    print('Hi from broadcast.')


if __name__ == '__main__':
    main()
