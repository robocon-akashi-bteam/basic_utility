#pragma once
#include "pigpiod.hpp"
#include <pigpiod_if2.h>

using ros::Pigpiod;

namespace ros {
class I2c {
public:
  I2c();
  bool init(unsigned int dev_id);
  void write(unsigned int reg, unsigned int data);
  int read(unsigned int reg);
  ~I2c();

private:
  int gpio_handle_;
  int i2c_handle_;
};
};
