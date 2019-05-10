#pragma once
#include "pigpiod.hpp"
#include <pigpiod_if2.h>

using ros::Pigpiod;

namespace ros {
class Serial {
public:
  Serial();
  bool init(const char *dev_file, int baudrate);
  int write(unsigned char tx_data);
  int writes(char *tx_data, unsigned int tx_len);
  int read();
  int reads(char *rx_data, unsigned int rx_len);
  int available();
  ~Serial();

private:
  int gpio_handle_;
  int serial_handle_;
};
};
