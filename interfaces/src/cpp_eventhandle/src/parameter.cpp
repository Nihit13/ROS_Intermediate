#include <memory>

#include "rclcpp/rclcpp.hpp"

class Parameters : public rclcpp::Node
{
public:
  Parameters()
  : Node("node_with_parameters")
  {
    this->declare_parameter("an_int_param", 0);
    this->declare_parameter("another_double_param",0.0 );

    param_subscriber_ = std::make_shared<rclcpp::ParameterEventHandler>(this);

    auto cb=[this](const rclcpp::Parameter &p){
    RCLCPP_INFO(this->get_logger(),"cb:Loacal param \"%s\"change: %ld",
    p.get_name().c_str(),p.as_int());
    };
    cb_handle_ = param_subscriber_->add_parameter_callback("an_int_param", cb);
    auto cb2=[this](const rclcpp::Parameter & p){
    RCLCPP_INFO(this->get_logger(),"cb2 :Remote Param\"%s\"changed: %2lf",
    p.get_name().c_str(),p.as_double());
    };
    cb_handle2_ = param_subscriber_->add_parameter_callback("a_double_param", cb2, "parameter_blackboard");
    auto event_cb =[this](const rcl_interfaces::msg::ParameterEvent & parameter_event){
    RCLCPP_INFO(this->get_logger(),"Recieved parameter event from node \"%s\"",
    parameter_event.node.c_str());
    for(const auto& p: parameter_event.changed_parameters){
    RCLCPP_INFO(this->get_logger(),"inside evenet: \"%s\" changed to %s",
    p.name.c_str(),
    rclcpp::Parameter::from_parameter_msg(p).value_to_string().c_str());
    }
    };
    event_cb_handle_ = param_subscriber_->add_parameter_event_callback(event_cb);    
  }

private:
  std::shared_ptr<rclcpp::ParameterEventHandler> param_subscriber_;
  std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle_;
  std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle2_;
  std::shared_ptr<rclcpp::ParameterEventCallbackHandle> event_cb_handle_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Parameters>());
  rclcpp::shutdown();

  return 0;
}

