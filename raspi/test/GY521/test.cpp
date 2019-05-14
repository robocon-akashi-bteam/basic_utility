#include "../../include/GY521.hpp"
#include <ros/ros.h>

using ros::GY521;

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "GY521_test");
  GY521 gyro;
  gyro.start();

  ros::NodeHandle n;
  ros::Time start = ros::Time::now();
  ros::Duration time;
  ros::Rate loop_rate(1000);

  while (ros::ok()) {
    gyro.update();
    time = ros::Time::now() - start;
    ROS_INFO_STREAM(time.sec << "." << time.nsec << ", " << gyro.yaw_);
  }

  return 0;
}
