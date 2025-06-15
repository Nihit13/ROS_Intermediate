#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Subscriber : public rclcpp::Node
{
public:
	Subscriber() :Node("sub_key")
	{
	subscription_ = this->create_subscription<std_msgs::msg::String>("topic_command",10,
	std::bind(&Subscriber::command_callback, this, std::placeholders::_1)
	);
	RCLCPP_INFO(this->get_logger()," Stimulation is ready,");
	}
	
private:
	void command_callback(const std_msgs::msg::String::SharedPtr msg)
	{
		std::string cmd = msg->data;
		if (cmd == "forward")RCLCPP_INFO(this->get_logger(), "moves forwarde");
		else if (cmd == "backward")RCLCPP_INFO(this->get_logger(), "moves backward");
		else if (cmd == "right")RCLCPP_INFO(this->get_logger(), "moves right");
		else if (cmd == "left")RCLCPP_INFO(this->get_logger(), "moves left");
		else if (cmd == "stop")RCLCPP_INFO(this->get_logger(), "stop");
		else RCLCPP_WARN(this->get_logger(), "unknown command: '%s'", cmd.c_str());
	}
	
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc,char*argv[])
{
rclcpp::init(argc,argv);
rclcpp::spin(std::make_shared<Subscriber>());
rclcpp::shutdown();
return 0;
}

			
