// File:          BaseRobot.hpp
// Date:          XX/XX/XXXX
// Description:   Header file of BaseRobot to be inherited by the Leader and Scout robots classes.
// Author:        Stephanie Liaw
// zID:           z1234567
// Modifications:

#pragma once

// add additional includes as needed
#include <iostream>
#include <memory>
#include <sstream>
#include <cstring>
#include <string>

#include <webots/Receiver.hpp>
#include <webots/Emitter.hpp>
#include <webots/Robot.hpp>


constexpr int TIME_STEP{ 64 };

class BaseRobot : public webots::Robot {
public:
	BaseRobot();
	virtual ~BaseRobot() = default;
  
	virtual void run() = 0;
	virtual void move(double speed) = 0;
	virtual void rotate(double speed) = 0;
	virtual void talk() = 0;

	void keyboardControl();
	void updateCurrentPosition();
	void setTargetPosition(double x, double y);
	bool moveToTarget(double stopDistance);
	   
	void sendMessage(const std::string& ID, const std::string& data0, const std::string& data1);
	std::pair<std::string, std::string> receiveMessage();

protected:
	std::string ID{};
	double currentPositionX{};
	double currentPositionY{};
	double currentYaw{};
	double targetPositionX{};
	double targetPositionY{};

	// add additional members as needed
  
private:
	std::unique_ptr<webots::Receiver> receiver{};
	std::unique_ptr<webots::Emitter> emitter{};
	
	// add additional members as needed
};
