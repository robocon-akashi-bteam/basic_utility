#include "../include/pigpiod.hpp"
#include <pigpiod_if2.h>

using ros::Pigpiod;

const char *ros::PIGPIOD_HOST = "localhost";
const char *ros::PIGPIOD_PORT = "8888";

Pigpiod::Pigpiod() {
  gpio_handle_ = pigpio_start(const_cast<char *>(ros::PIGPIOD_HOST),
                              const_cast<char *>(ros::PIGPIOD_PORT));
}

void Pigpiod::write(int pin, int level) {
  gpio_write(gpio_handle_, pin, level);
}

int Pigpiod::read(int pin) { return gpio_read(gpio_handle_, pin); }

void Pigpiod::set(int pin, int mode, int init) {
  if (mode == ros::IN) {
    set_mode(gpio_handle_, pin, PI_INPUT);
    if (init == ros::PULL_UP) {
      set_pull_up_down(gpio_handle_, pin, PI_PUD_UP);
    } else if (init == ros::PULL_DOWN) {
      set_pull_up_down(gpio_handle_, pin, PI_PUD_DOWN);
    } else if (init == ros::PULL_OFF) {
      set_pull_up_down(gpio_handle_, pin, PI_PUD_OFF);
    }
  } else if (mode == ros::OUT) {
    set_mode(gpio_handle_, pin, PI_OUTPUT);
    gpio_write(gpio_handle_, pin, init);
  }
}

int Pigpiod::checkHandle() { return gpio_handle_; }

bool Pigpiod::checkInit() {
  if (gpio_handle_ < 0) {
    return false;
  } else {
    return true;
  }
}

void Pigpiod::delay(double micro_sec) { time_sleep(micro_sec / 1000000); }

Pigpiod::~Pigpiod() { pigpio_stop(gpio_handle_); }
