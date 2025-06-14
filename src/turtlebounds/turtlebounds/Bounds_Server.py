import rclpy
from rclpy.node import Node
from tutorial_interfaces.srv import MoveBot 
from geometry_msgs.msg import Twist
class MoveBotServ(Node):
    def __init__(self):
        super().__init__("MoveBot_Srv")
        self.srv = self.create_service(MoveBot,"Service",self.Velocity_Callback)
        self.publish = self.create_publisher(Twist, "/turtle1/cmd_vel",10)

    def Velocity_Callback(self, request, response):
        msg = Twist()
        msg.linear.x = request.linear
        msg.angular.z = request.angular
        self.publisher.publish(msg)
        response.success = True
        return response
    

def main(args=None):
    rclpy.init(args=args)
    node = MoveBotServ()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()