#include "Robot.h"


std::string Robot::getName() {
	return name_;
};

int Robot::getNumWheels() {
	return num_wheels_;
};

int Robot::getNumSensors() {
	return num_sensors_;
};

void Robot::setName(std::string const& name)
{
	name_ = name;
};

void Robot::move(double x, double y) {
	pose_ = { x, y };
};

std::pair<double, double> Robot::localise() { return { distance(), angle() }; };

double Robot::distance() const {
	return std::sqrt(std::pow(pose_.first, 2) + std::pow(pose_.second, 2));
};

double Robot::angle() const { return std::atan2(pose_.second, pose_.first); };