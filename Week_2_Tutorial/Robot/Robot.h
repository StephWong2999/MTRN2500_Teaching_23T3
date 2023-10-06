#pragma once

#include <cmath>
#include <string>
#include <utility>


class Robot {
public:
	Robot() = delete;
	Robot(std::string const& name, int const& n) : Robot(name, n, 0) {};
	Robot(std::string const& name, int const& n, int const& m)
		: name_(name), num_wheels_(n), num_sensors_(m) {};
	~Robot() = default;

	std::string getName();
	int getNumWheels();
	int getNumSensors();

	void setName(std::string const& name);
	void move(double x, double y);
	std::pair<double, double> localise();

private:
	double distance() const;
	double angle() const;

	std::string name_;
	const int num_wheels_;
	const int num_sensors_;
	std::pair<double, double> pose_;
};
