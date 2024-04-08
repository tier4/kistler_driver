cmake_minimum_required(VERSION 3.8)
project(kistler_driver)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(kistler_driver SHARED
  src/kistler_driver.cpp
)

ament_auto_package(
  INSTALL_TO_SHARE
)
