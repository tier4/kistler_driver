// Copyright 2024 TIER IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef KISTLER_DRIVER__KISTLER_DRIVER_HPP_
#define KISTLER_DRIVER__KISTLER_DRIVER_HPP_

// ROS2
#include <rclcpp/rclcpp.hpp>
#include <can_msgs/msg/frame.hpp>

// C++
#include <string>

// Msg
#include <kistler_driver_msgs/msg/e0_status.hpp>
#include <kistler_driver_msgs/msg/e1_status.hpp>
#include <kistler_driver_msgs/msg/e2_status.hpp>
#include <kistler_driver_msgs/msg/e3_status.hpp>
#include <kistler_driver_msgs/msg/e4_status.hpp>
#include <kistler_driver_msgs/msg/e5_status.hpp>
#include <kistler_driver_msgs/msg/e6_status.hpp>
#include <kistler_driver_msgs/msg/e7_status.hpp>
#include <kistler_driver_msgs/msg/e8_status.hpp>
#include <kistler_driver_msgs/msg/e9_status.hpp>
#include <kistler_driver_msgs/msg/ea_status.hpp>
#include <kistler_driver_msgs/msg/eb_status.hpp>

namespace kistler_driver
{
  using can_msgs::msg::Frame;
  using kistler_driver_msgs::msg::E0Status;
  using kistler_driver_msgs::msg::E1Status;
  using kistler_driver_msgs::msg::E2Status;
  using kistler_driver_msgs::msg::E3Status;
  using kistler_driver_msgs::msg::E4Status;
  using kistler_driver_msgs::msg::E5Status;
  using kistler_driver_msgs::msg::E6Status;
  using kistler_driver_msgs::msg::E7Status;
  using kistler_driver_msgs::msg::E8Status;
  using kistler_driver_msgs::msg::E9Status;
  using kistler_driver_msgs::msg::EAStatus;
  using kistler_driver_msgs::msg::EBStatus;

class KistlerDriver : public rclcpp::Node
{
public:
  explicit KistlerDriver(const rclcpp::NodeOptions & node_options);

private:
  // Subscriber
  rclcpp::Subscription<Frame>::SharedPtr sub_can_;

  void onCan(Frame::ConstSharedPtr msg);

  Frame initializeCanMsg() const;

  // Publisher
  rclcpp::Publisher<E0Status>::SharedPtr pub_e0_status_;
  rclcpp::Publisher<E1Status>::SharedPtr pub_e1_status_;
  rclcpp::Publisher<E2Status>::SharedPtr pub_e2_status_;
  rclcpp::Publisher<E3Status>::SharedPtr pub_e3_status_;
  rclcpp::Publisher<E4Status>::SharedPtr pub_e4_status_;
  rclcpp::Publisher<E5Status>::SharedPtr pub_e5_status_;
  rclcpp::Publisher<E6Status>::SharedPtr pub_e6_status_;
  rclcpp::Publisher<E7Status>::SharedPtr pub_e7_status_;
  rclcpp::Publisher<E8Status>::SharedPtr pub_e8_status_;
  rclcpp::Publisher<E9Status>::SharedPtr pub_e9_status_;
  rclcpp::Publisher<EAStatus>::SharedPtr pub_ea_status_;
  rclcpp::Publisher<EBStatus>::SharedPtr pub_eb_status_;
};

} // namespace kistler_driver


#endif // KISTLER_DRIVER__KISTLER_DRIVER_HPP_