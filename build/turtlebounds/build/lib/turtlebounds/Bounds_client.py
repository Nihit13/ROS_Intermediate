import rclpy
from rclpy.node import Node
from tutorial_interfaces.srv import MoveBot


class MoveBot(Node):
    def __init__(self):
        super().__init__("Move_Bot")
        self.cli = self.create_client(MoveBot,"service",10)
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = MoveBot.Request()

    def send_request(self, linear  , angular ):
        self.req.linear = linear 
        self.req.angular = angular
        self.future = self.cli.call_async(self.req)


   
        
def main(args=None):
    rclpy.init(args=args)
    client = MoveBot()
    client.send_request(2 ,1)
    while rclpy.ok():
        rclpy.spin_once(client)
        if client.future.done():
            try:
                response = client.future.result()
                print(f"Success: {response.success}")
            except Exception as e:
                print(f"Service call failed: {e}")
            break
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()