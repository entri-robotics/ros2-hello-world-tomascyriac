cmake_minimum_required(VERSION 3.8)
project(entri_ros2_basics_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)git 
find_package(rclcpp REQUIRED)

# TODO: Add the executable target named 'hello_node'
# 1. Add executable using src/hello_node.cpp
add_executable(hello_node src/hello_node.cpp)
# 2. Add dependencies (ament_target_dependencies) for rclcpp
ament_target_dependencies(hello_node rclcpp)
# 3. Install the target to the DESTINATION lib/${PROJECT_NAME}
install(TARGETS
  hello_node /*executable target*/
  DESTINATION lib/${PROJECT_NAME}/*destination for the executable target*/
)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
