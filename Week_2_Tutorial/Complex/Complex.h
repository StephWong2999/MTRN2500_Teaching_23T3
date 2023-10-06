#pragma once

#include <cmath>
#include <utility>


class Complex {
public:
	Complex() = default;
	Complex(double const& real) : Complex(real, 0) {}
	Complex(double const& real, double const& imaginary) : real_(real), imaginary_(imaginary) {};
	~Complex() = default;

	Complex conjugate();
	double modulus();
	double argument();

	double getReal() { return real_; };
	double getImaginary() { return imaginary_; };
	void setReal(double const& real) { real_ = real; };
	void setImaginary(double const& imaginary) { imaginary_ = imaginary; };

private:
	double real_;
	double imaginary_;
};

Complex Complex::conjugate() {
	return Complex(real_, -imaginary_);
}

double Complex::modulus() {
	return std::sqrt(std::pow(real_, 2) + std::pow(imaginary_, 2));
};

double Complex::argument() {
	return std::atan2(imaginary_, real_);
};
