import rclpy
from tutorial_interfaces.actions import CountUntill
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
import time

class ActionServ(Node):
    def __init__(self):
        super().__init__("Action_serv")
        self.count_untill_action_ =  ActionServer(self,CountUntill,"CountUntill",execute_callback=self.execute_callback)

    def execute_callback(self, goalhandle:ServerGoalHandle):
        target_number =  goalhandle.request.target_number 
        period = goalhandle.request.period
        count = 0
        for i in range(target_number):
            count+=1
            time.sleep(period)
        goalhandle.succeed()
        Result = CountUntill.Result
        Result.reached_number = count

        self.get_logger().info("Action server has started")
        return Result




def main(args=None):
    rclpy.init(args=args)

    action_server = ActionServ()

    rclpy.spin(action_server)


if __name__ == '__main__':
    main()


