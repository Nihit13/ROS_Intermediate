#include <cstdio>
#include <random>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

struct Train {
    int id;
    int currentStation;
    int destinationStation;
};

class platform1 : public rclcpp::Node{
  public:
  	platform1() : Node("station2"){
  		platform1_= this->create_publisher<std_msgs::msg::String>("/station2/platform1/trains",10);
  		platform2_= this->create_publisher<std_msgs::msg::String>("/station2/platform2/trains",10);
  		
  		timer_=this->create_wall_timer(
  			std::chrono::seconds(5),
  			std::bind(&platform1::timer_callback,this));
  	}
  	
  private:
    void timer_callback(){
  	auto message = std_msgs::msg::String();
  	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> id_distrib(1, 100);
	std::uniform_int_distribution<> destination_distrib(1, 3);
  	Train train={id_distrib(gen),2,destination_distrib(gen)};
  	message.data= "Train " + std::to_string(train.id) + " - leaving for destination " + std::to_string(train.destinationStation);
	
	RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
	
        std::uniform_int_distribution<> platform_distrib(1, 2);
	if (platform_distrib(gen) == 1) {
		platform1_->publish(message);
	} 
	else {
		platform2_->publish(message);
	}
	
  }
	
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr platform1_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr platform2_;
 	rclcpp::TimerBase::SharedPtr timer_;        
 };
 
 
int main(int argc, char ** argv)
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<platform1>());
	rclcpp::shutdown();
	return 0;
}
