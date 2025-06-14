import rclpy 
from rclpy.node import Node  # Changed from 'from rclpy import Node'
from rclpy.action import ActionClient
from turtlesim.action import RotateAbsolute

class Turtlecli(Node):
    def __init__(self ):
        super().__init__("Turtlecli")
        self._action_cli = ActionClient(self, RotateAbsolute, "/turtle1/rotate_absolute")
        # Wait for action server
        self._action_cli.wait_for_server()
       
    def send_goal(self,theta):
        goal = RotateAbsolute.Goal()
        goal.theta = theta

        self.future_send_action = self._action_cli.send_goal_async(goal)
        self.future_send_action.add_done_callback(self.get_result)

    def get_result(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Goal rejected')
            return
        self.result_future = goal_handle.get_result_async()
        self.result_future.add_done_callback(self.process_result)

    def process_result(self, future):
        result = future.result().result
        relative_movement = abs(self.previous_angle - result.delta)
        self.get_logger().info(f"Absolute target angle: {self.previous_angle}")
        self.get_logger().info(f"Delta from target: {result.delta}")
        self.get_logger().info(f"Total movement: {relative_movement}")
        rclpy.shutdown() 
        return relative_movement

def main(args=None):
    rclpy.init(args=args)
    angle = 3.14
    action_client = Turtlecli()
    relative_movement =  action_client.send_goal(angle)
    angle = relative_movement
    rclpy.spin(action_client)
    

if __name__ == '__main__':
    main()

