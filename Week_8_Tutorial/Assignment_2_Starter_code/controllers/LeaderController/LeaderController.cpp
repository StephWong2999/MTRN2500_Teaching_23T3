// File:          LeaderController.cpp
// Date:          
// Description:   Controller for the Leader RObot
// Author:        Stephanie Liaw  
// Modifications:

#include <webots/Robot.hpp>
#include "LeaderController.hpp"


LeaderRobot::LeaderRobot() {};
LeaderRobot::~LeaderRobot() {};

void LeaderRobot::run() {
  while (step(TIME_STEP) != -1) {
    talk();
  };
};
void LeaderRobot::move(double speed) {};
void LeaderRobot::rotate(double speed) {};
void LeaderRobot::talk() {
  std::cout << "I am the Leader Robot" << std::endl;
};



int main(int argc, char **argv) {
  LeaderRobot leader;
  leader.run();
  return 0;
}
