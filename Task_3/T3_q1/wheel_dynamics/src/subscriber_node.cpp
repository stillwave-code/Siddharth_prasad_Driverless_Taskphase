#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "wheel_interfaces/msg/task_one.hpp"

using std::placeholders::_1;

class WheelSubscriber : public rclcpp::Node
{
public:
  WheelSubscriber() : Node("wheel_subscriber_node")
  {
    
    subscription_ = this->create_subscription<wheel_interfaces::msg::TaskOne>(
      "/taskone", 10, std::bind(&WheelSubscriber::topic_callback, this, _1));
  }

private:
  // 2. This function runs automatically whenever data is received
  void topic_callback(const wheel_interfaces::msg::TaskOne::SharedPtr msg) const
  {
    // 3. Calculate longitudinal speed (v = angular velocity * radius)
    double speed = msg->ang_vel * msg->radius;
    
    std::cout << "\n[Message Received]" << std::endl;
    std::cout << "Angular Velocity: " << msg->ang_vel << " rad/s" << std::endl;
    std::cout << "Wheel Radius: " << msg->radius << " m" << std::endl;
    std::cout << "--> Calculated Longitudinal Speed: " << speed << " m/s" << std::endl;
  }
  
  rclcpp::Subscription<wheel_interfaces::msg::TaskOne>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  std::cout << "--- Wheel Subscriber Started ---" << std::endl;
  // Keep the node listening indefinitely
  rclcpp::spin(std::make_shared<WheelSubscriber>());
  rclcpp::shutdown();
  return 0;
}
