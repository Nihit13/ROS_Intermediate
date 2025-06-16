#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_srvs/srv/empty.hpp"

const float PI= 3.14159;

using namespace std;
using namespace std::chrono_literals;

class turtle : public rclcpp::Node{
  public:
    turtle() : Node("turtle_controller"){
      turtle_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
      
      char choose='n';
      
      while(choose != 'y' ){
        string draw; 
        cout << "Choose what to draw - circle,polygon,design : ";
        cin >> draw;
        
      	if(draw=="circle") make_circle();
      	else if(draw=="polygon") make_gon();
      	else if(draw=="design") make_design();
      	
      	cout << " Exit ? y/n : ";
        cin >> choose;
        
        clear_screen();
      }
    }
    
    // circle
    void make_circle(){
      msg.linear.x=5.0;
      msg.angular.z=2*PI-0.002;
      
      turtle_->publish(msg);
      
      auto node = rclcpp::Node::make_shared("logger_node");
      RCLCPP_INFO(node->get_logger(), "circle completed ");
    }
    
    // polygon
    void make_gon(){
      auto node = rclcpp::Node::make_shared("logger_node");
      int sides=1;
      while(sides<3 && rclcpp::ok()){
        cout<< "Enter number of sides : ";
        cin >> sides; 
        cout<<endl;
      }
      
      float angle = (2*PI)/sides;
    
      for(int i=0;i<sides;i++){
        msg.linear.x=1;
        msg.angular.z=0;
        turtle_->publish(msg);
        this_thread::sleep_for(chrono::seconds(1));
        msg.linear.x=0;
        msg.angular.z=angle;
        turtle_->publish(msg);
        this_thread::sleep_for(chrono::seconds(3));
      }
        
      RCLCPP_INFO(node->get_logger(), "Polygon completed ");
       
    }
    
    // design
    void make_design(){
        geometry_msgs::msg::Twist msg;
        
        int sides=1;
        while(sides<3 && rclcpp::ok()){
          cout<< "Enter number of sides : ";
          cin >> sides; 
          cout<<endl;
        } 
        
        double angle1 = 2*PI - (2*PI)/sides;
        double angle2 = 2*((2*PI)/sides) - 2*PI;

        msg.linear.x = 0.0;
        msg.angular.z = angle1 - 0.049;
        turtle_->publish(msg);

        for (int i = 0; i < sides; ++i)
        {
            msg.linear.x = 1.0;
            msg.angular.z = 0.0;
            turtle_->publish(msg);
            this_thread::sleep_for(chrono::seconds(1));

            msg.linear.x = 1.5;
            msg.angular.z = angle2;
            turtle_->publish(msg);
            this_thread::sleep_for(chrono::seconds(3));

            msg.linear.x = 1.0;
            msg.angular.z = 0.0;
            turtle_->publish(msg);
            this_thread::sleep_for(chrono::seconds(1));

            msg.linear.x = 0.75;
            msg.angular.z = angle1;
            turtle_->publish(msg);
            this_thread::sleep_for(chrono::seconds(3));
        }
        
      auto node = rclcpp::Node::make_shared("logger_node");
      RCLCPP_INFO(node->get_logger(), "design completed ");
    }
    
    void clear_screen(){
      client_ = this->create_client<std_srvs::srv::Empty>("/clear");

      auto request = std::make_shared<std_srvs::srv::Empty::Request>();
      auto result = client_->async_send_request(request);
    }
    
  private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle_;
    geometry_msgs::msg::Twist msg;
    rclcpp::Client<std_srvs::srv::Empty>::SharedPtr client_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(make_shared<turtle>());

  return 0;
}
