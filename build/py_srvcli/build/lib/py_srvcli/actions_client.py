import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from tutorial_interfaces.actions import CountUntill

class CountUntilClient(Node):
    def __init__(self):
        super().__init__('count_until_client')
        self._action_client = ActionClient(self, CountUntill, 'CountUntill')

    def send_goal(self, target_number, period):
        goal_msg = CountUntill.Goal()
        goal_msg.target_number = target_number
        goal_msg.period = period

        self._action_client.wait_for_server()
        self.get_logger().info('Sending goal...')
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            return

        self.get_logger().info('Goal accepted :)')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Feedback received")

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: Reached number = {result.reached_number}")
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    client = CountUntilClient()
    client.send_goal(target_number=5, period=1.0)

    rclpy.spin(client)

if __name__ == '__main__':
    main()
