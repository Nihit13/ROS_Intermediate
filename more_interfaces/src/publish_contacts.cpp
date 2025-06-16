#include <memory>
#include <chrono>    
#include <string>  

#include "rclcpp/rclcpp.hpp"
#include "more_interfaces/msg/custom_contacts.hpp"
#include "more_interfaces/msg/address_book.hpp"

using namespace std::chrono_literals;

class ContactsPublisher : public rclcpp::Node{
  public:
    ContactsPublisher():Node("contacts"){
      contacts_ = this->create_publisher<more_interfaces::msg::CustomContacts>("contacts_books",10);
      
      auto publish_address = [this]() -> void {
        auto contact_book = more_interfaces::msg::CustomContacts();
        
          std::string first_names[5] = {"Ayush", "Aqibe", "Anushri", "Gargie", "Nihit"};
          std::string last_names[5] = {"Negi", "Shaikh", "Arora", "Kapte", "Shevade"};
          std::string phone_numbers[5] = {"1234567890", "2345678900", "3456789000", "4567890000", "5678900000"};
        
        for(int i=0;i<5;i++){
          auto message = more_interfaces::msg::AddressBook();

          message.first_name = first_names[i];
          message.last_name = last_names[i];
          message.phone_number = phone_numbers[i];
          message.phone_type = message.PHONE_TYPE_MOBILE;
          
          contact_book.contacts.push_back(message);
        }
        
        this->contacts_->publish(contact_book);
        
      };
      
      timer_=this->create_wall_timer(5s,publish_address);
    }
    
    
  private:
    rclcpp::Publisher<more_interfaces::msg::CustomContacts>::SharedPtr contacts_;
    rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ContactsPublisher>());
  rclcpp::shutdown();

  return 0;
}
