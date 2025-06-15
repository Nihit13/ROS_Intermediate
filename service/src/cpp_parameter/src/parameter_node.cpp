#include<chrono>
#include<functional>
#include<rclcpp/rclcpp.hpp>
#include<string>

using namespace std::chrono_literals;
class parameter : public rclcpp::Node
{
public:
	parameter():Node("parameter_node"){
	auto param_desc=rcl_interfaces::msg::ParameterDescriptor{};
	param_desc.description ="this parameter is mine!";
	
	this->declare_parameter("my_parameter","world",param_desc);
	timer_=this->create_wall_timer(1000ms, std::bind(&parameter::timer_callback,this));
	}
	
	void timer_callback(){
	  std::string my_param=this->get_parameter("my_parameter").as_string();
	  RCLCPP_INFO(this->get_logger(),"hello %s!", my_param.c_str());
		
	  std::vector<rclcpp::Parameter>all_new_parameters{
	    rclcpp::Parameter("my_parameter", words[count%3])
	  };
	  this->set_parameters(all_new_parameters);
	  count++;
	} 
	
private:
rclcpp::TimerBase::SharedPtr timer_;
std::string words[3]={"I","Love","Ros"};
int count=0;
};
int main(int argc ,char**argv)
{
rclcpp::init(argc,argv);
rclcpp::spin(std::make_shared<parameter>());
rclcpp::shutdown();
return 0;
}	

