cmake_minimum_required(VERSION 3.8)
project(Andinobot_base)

find_package(ament_cmake REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)

# COMPILE
add_library(Andinobot_hardware SHARED
  src/Andinobot_hardware.cpp
  src/wheel.cpp
  src/motor_encoder.c
  src/MotorDriver.c
  src/esp32_bridge.c
  src/DEV_Config.c
)

target_include_directories(Andinobot_hardware PRIVATE include)

ament_target_dependencies(
  Andinobot_hardware
  hardware_interface
  pluginlib
  rclcpp
  rclcpp_lifecycle
)

# Link WiringPi library to Andinobot_hardware target
target_link_libraries(Andinobot_hardware wiringPi)

# Export hardware plugin
pluginlib_export_plugin_description_file(hardware_interface Andinobot_hardware.xml)

# INSTALL
install(
  DIRECTORY include/
  DESTINATION include/Andinobot_hardware
)

install(
  TARGETS Andinobot_hardware
  DESTINATION share/${PROJECT_NAME}
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

include_directories(include)

# EXPORTS
ament_export_libraries(Andinobot_hardware)

ament_package()
