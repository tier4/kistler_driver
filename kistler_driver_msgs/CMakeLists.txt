cmake_minimum_required(VERSION 3.8)
project(kistler_driver_msgs)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

rosidl_generate_interfaces(${PROJECT_NAME}
  msg/E0Status.msg
  msg/E1Status.msg
  msg/E2Status.msg
  msg/E3Status.msg
  msg/E4Status.msg
  msg/E5Status.msg
  msg/E6Status.msg
  msg/E7Status.msg
  msg/E8Status.msg
  msg/E9Status.msg
  msg/EAStatus.msg
  msg/EBStatus.msg
  DEPENDENCIES
    builtin_interfaces
    std_msgs
)

ament_auto_package()
