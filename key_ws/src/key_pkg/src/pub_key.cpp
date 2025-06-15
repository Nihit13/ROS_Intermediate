#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>

using std::placeholders::_1;

class Keyboard : public rclcpp::Node
{
public:
	Keyboard()
	:Node("pub_key")
	{
	publisher_=this->create_publisher<std_msgs::msg::String>("topic_command",10);
	RCLCPP_INFO(this->get_logger(),"Keyboard Publisher started. Use keys:W/A/S/D/X");
	
	while (rclcpp::ok()){
	std::string input;
	std::cout<<"enter ommand (W/A/S/D/X):";
	std::getline(std::cin, input);
	
	std_msgs::msg::String msg;
	if (input == "W" || input == "w") msg.data = "forward";
	else if (input == "S" || input == "s") msg.data ="backward";
	else if (input == "A" || input == "a") msg.data ="left";
	else if (input == "D" || input == "d") msg.data ="right";
	else if (input == "X" || input == "x") msg.data ="stop";
	else{
		RCLCPP_WARN(this->get_logger(), "Invalid key. Use W/A/S/D/X.");
	continue;
	}
	
	publisher_->publish(msg);
	RCLCPP_INFO(this->get_logger(), "Published command: '%s'", msg.data.c_str());
	}
	}
	
private:
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
	};

int main(int argc,char * argv[])
{
	rclcpp::init(argc,argv);
	std::shared_ptr<Keyboard> node = std::make_shared<Keyboard>();
	rclcpp::shutdown();
	return 0;
}				
