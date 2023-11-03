
#pragma once

#include "../BaseRobot/BaseRobot.hpp"
#include <webots/Robot.hpp>

class LeaderRobot : public BaseRobot {
public:
    LeaderRobot();
    ~LeaderRobot();

    void run() override;
    void move(double speed) override;
	void rotate(double speed) override;
    void talk() override;

protected:
    // To implement

private:
    // To implement

};