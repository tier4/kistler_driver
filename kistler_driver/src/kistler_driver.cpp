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

#include <kistler_driver/kistler_driver.hpp>

namespace kistler_driver
{

KistlerDriver::KistlerDriver(const rclcpp::NodeOptions & node_options)
: Node("kistler_driver", node_options)
{
  using std::placeholders::_1;

  // Subscriber
  sub_can_ = this->create_subscription<Frame>("input/from_can_bus", rclcpp::QoS(1000), std::bind(&KistlerDriver::onCan, this, _1));

  // Publisher
  pub_e0_status_ = this->create_publisher<E0Status>("output/e0_status", 10);
  pub_e1_status_ = this->create_publisher<E1Status>("output/e1_status", 10);
  pub_e2_status_ = this->create_publisher<E2Status>("output/e2_status", 10);
  pub_e3_status_ = this->create_publisher<E3Status>("output/e3_status", 10);
  pub_e4_status_ = this->create_publisher<E4Status>("output/e4_status", 10);
  pub_e5_status_ = this->create_publisher<E5Status>("output/e5_status", 10);
  pub_e6_status_ = this->create_publisher<E6Status>("output/e6_status", 10);
  pub_e7_status_ = this->create_publisher<E7Status>("output/e7_status", 10);
  pub_e8_status_ = this->create_publisher<E8Status>("output/e8_status", 10);
  pub_e9_status_ = this->create_publisher<E9Status>("output/e9_status", 10);
  pub_ea_status_ = this->create_publisher<EAStatus>("output/ea_status", 10);
  pub_eb_status_ = this->create_publisher<EBStatus>("output/eb_status", 10);
}

void KistlerDriver::onCan(Frame::ConstSharedPtr msg)
{
  if (msg->id == 0x07E0)
  {
    auto e0_status_msg = E0Status();
    e0_status_msg.velocity_x = (static_cast<int16_t>((msg->data.at(1) << 8) + msg->data.at(0))) * 0.036;
    e0_status_msg.velocity_y = (static_cast<int16_t>((msg->data.at(3) << 8) + msg->data.at(2))) * 0.036;
    e0_status_msg.velocity = (static_cast<int16_t>((msg->data.at(5) << 8) + msg->data.at(4))) * 0.036;
    e0_status_msg.angle = (static_cast<int8_t>((msg->data.at(7) << 8) + msg->data.at(6))) * 0.01;

    pub_e0_status_->publish(e0_status_msg);
  } else if (msg->id == 0x07E1)
  {
    auto e1_status_msg = E1Status();
    e1_status_msg.distance = (static_cast<int32_t>((msg->data.at(3) << 8 + msg->data.at(2) << 8 + msg->data.at(1) << 8 + msg->data.at(0)))) * 0.001;

    pub_e1_status_->publish(e1_status_msg);
  } else if (msg->id == 0x07E2)
  {
    /* code */
  } else if (msg->id == 0x07E3)
  {
    /* code */
  } else if (msg->id == 0x07E4)
  {
    /* code */
  } else if (msg->id == 0x07E5)
  {
    /* code */
  } else if (msg->id == 0x07E6)
  {
    /* code */
  } else if (msg->id == 0x07E7)
  {
    /* code */
  } else if (msg->id == 0x07E8)
  {
    /* code */
  } else if (msg->id == 0x07E9)
  {
    /* code */
  } else if (msg->id == 0x07EA)
  {
    /* code */
  } else if (msg->id == 0x07EB)
  {
    /* code */
  } else
  {
    RCLCPP_WARN_THROTTLE(
      this->get_logger(), *this->get_clock(), 3000, "Receive undefined CAN ID: %d", msg->id);
  }
}

} // namespace kistler_driver