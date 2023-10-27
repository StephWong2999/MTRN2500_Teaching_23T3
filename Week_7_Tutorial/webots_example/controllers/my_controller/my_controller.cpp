// File:          my_controller.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include "my_camera.hpp"

// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();

  // How much time is taken between physics calculations
  int timeStep = (int)robot->getBasicTimeStep();
  
  // Find Motors
  auto leftMotor = robot->getMotor("left wheel motor");
  auto rightMotor = robot->getMotor("right wheel motor");

  // Motors will turn for 3 radians - Don't use this for motors. Mainly used for servos
  // leftMotor->setPosition(3.0);
  // rightMotor->setPosition(3.0);
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);

  // Velocity set to 0.0
  leftMotor->setVelocity(0.0);
  rightMotor->setVelocity(0.0);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  // Write action code here
  while (robot->step(timeStep) != -1) {
    print_camera();
    leftMotor->setVelocity(5.0);
    rightMotor->setVelocity(5.0);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
