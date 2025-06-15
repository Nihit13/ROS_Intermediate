#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <cmath>
#include "std_srvs/srv/empty.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"
#include <chrono>
using namespace std;
using namespace std::chrono_literals;

class Shape:public rclcpp::Node{
  public:
    Shape():Node("shapes_node"){
    publisher_=this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
    clear_client_= this->create_client<std_srvs::srv::Empty>("/clear");
    teleport_client_=this->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    
     RCLCPP_INFO(this->get_logger(), "Choose a shape");
     
     string input;
     int count=0,sides=0,test=1;
     float angle=0;
     
     
    cout<<"enter circle/polygon/unique:";
    getline(cin,input);
    
      
    if(input=="circle"){
    while(rclcpp::ok()&&count<1){
    msg.linear.x=3.0;
    msg.angular.z=2*M_PI;
    this_thread::sleep_for(std::chrono::seconds(2));
    count++;
    RCLCPP_INFO(this->get_logger(), "count: '%d'",count);
     publisher_->publish(msg);
     
    }
    this_thread::sleep_for(std::chrono::seconds(2));
    }
    
    
    else if(input=="polygon"){
    cout<<"enter No. of sides:";
    cin>>sides;
    angle=M_PI-(((sides-2)*M_PI)/sides);
    RCLCPP_INFO(this->get_logger(), "angle: '%f'",angle);
    while(rclcpp::ok()&&count<sides){
    msg.linear.x=2.0;
    msg.angular.z=0.0;
    this_thread::sleep_for(std::chrono::seconds(2));
    publisher_->publish(msg);
    
    msg.linear.x=0.0;
    msg.angular.z=angle;
     count++;
     this_thread::sleep_for(std::chrono::seconds(2));

    RCLCPP_INFO(this->get_logger(), "count: '%d'",count);
    
     publisher_->publish(msg);
    	}
    	this_thread::sleep_for(std::chrono::seconds(2));
    	}
    else if(input=="unique"){
    while(rclcpp::ok()&&test<29){
    if(test%4==0){
    msg.linear.x=1.0;
    msg.angular.z=0.524;
    publisher_->publish(msg);
    this_thread::sleep_for(std::chrono::seconds(1));
    RCLCPP_INFO(this->get_logger(), "count 4 divisible: '%d'",test);
    test++;
    
    }
    else if(test%2==0){
    msg.linear.x=0.0;
    msg.angular.z=1.309;
    publisher_->publish(msg);
    this_thread::sleep_for(std::chrono::seconds(2));
    RCLCPP_INFO(this->get_logger(), "count even: '%d'",test);
    test++;
    
    }
    
    else{
    msg.linear.x=2.0;
    msg.angular.z=1.8;
    publisher_->publish(msg);
    this_thread::sleep_for(std::chrono::seconds(3));
    RCLCPP_INFO(this->get_logger(), "count odd: '%d'",test);
    test++;
   
    }
      
    }
    this_thread::sleep_for(std::chrono::seconds(2));
    }	
       
    else{
    RCLCPP_WARN(this->get_logger(), "Invalid or incorrect commad: '%s'",input.c_str());
   
    }  
    
    
    std::shared_ptr<turtlesim::srv::TeleportAbsolute::Request> tp_req=std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    tp_req->x = 5.544;
    tp_req->y = 5.544;
    tp_req->theta = 0.0;
    teleport_client_->wait_for_service();
    teleport_client_->async_send_request(tp_req);
    
    rclcpp::sleep_for(std::chrono::milliseconds(500));
    
    auto clear_req=std::make_shared<std_srvs::srv::Empty::Request>();
    clear_client_->async_send_request(clear_req);
    rclcpp::sleep_for(std::chrono::milliseconds(500));
    
    RCLCPP_INFO(this->get_logger(),"reset");
     
    
    rclcpp::spin_some(this->get_node_base_interface());
    }
  private:
      rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
      geometry_msgs::msg::Twist msg;
      rclcpp::Client<std_srvs::srv::Empty>::SharedPtr clear_client_;
      rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr teleport_client_;
              
};
 

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  std::shared_ptr<Shape> node=std::make_shared<Shape>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  
  return 0;
}
