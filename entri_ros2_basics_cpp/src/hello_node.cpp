// Used for adding milliseconds to the timer
#include <chrono> 
#include <functional>
#include <memory>//for shared pointer
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

/*
 * TODO: Create a Class named 'HelloNode' that inherits from rclcpp::Node.
 * Requirements:
 * 1. The constructor should name the node "hello_world_node".
 * 2. Create a timer that triggers every 1000ms (1 second).
 * 3. The timer callback should print "Hello, World!" using the RCLCPP_INFO macro.
 */

//hello node is derived from rclcpp::Node, which means it inherits all the functionalities of a node.
class HelloNode : public rclcpp::Node
{
public:
  HelloNode()
  : Node("hello_world_node")
  {
    // TODO: Initialize the timer here
    //calls the timer callback function every 1000ms
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&HelloNode::timer_callback, this));
  }

private:
  // TODO: Define the timer_callback function here
  void timer_callback()
  {
    RCLCPP_INFO(this->get_logger(), "Hello, World!"); //Logger macro that prints "Hello, World!" to the console. this->get_logger() is used to get the logger associated with the node.
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}
