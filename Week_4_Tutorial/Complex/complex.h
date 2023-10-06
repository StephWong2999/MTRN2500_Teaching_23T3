#pragma once

#include <cmath>
#include <utility>
#include <iostream>


class Complex {
public:
	Complex() = default;
	Complex(double const& real) : Complex(real, 0) {}
	Complex(double const& real, double const& imaginary) : real_(real), imaginary_(imaginary) {};
	Complex(Complex const& z) : real_(z.real_), imaginary_(z.imaginary_) {};
	Complex(Complex&& z) : real_(std::exchange(z.real_, 0)), imaginary_(std::exchange(z.imaginary_, 0)) {};
	~Complex() = default;

	Complex& operator=(Complex const& z) {
		real_ = z.real_;
		imaginary_ = z.imaginary_;
		// What do we return?
		return *this;


	};
	Complex& operator=(Complex&& z) {
		/*std::exchange(z.real_, 0);
		std::exchange(z.imaginary_, 0);*/
		real_ = z.real_;
		imaginary_ = z.imaginary_;
		z.real_ = 0;
		z.imaginary_ = 0;
		return *this;
	}

	static Complex make_conjugate(Complex const& z);
	friend Complex operator+(Complex const& lhs, Complex const& rhs);
	friend Complex operator-(Complex const& lhs, Complex const& rhs);
	friend Complex operator*(Complex const& lhs, Complex const& rhs);
	friend bool operator==(Complex const& lhs, Complex const& rhs);
	friend bool operator!=(Complex const& lhs, Complex const& rhs);
	friend std::ostream& operator<<(std::ostream& os, Complex const& z);

	Complex conjugate() const;
	double modulus();
	double argument();
	
	double getReal() { return real_; };
	double getImaginary() { return imaginary_; };
	void setReal(double const& real) { real_ = real;};
	void setImaginary(double const& imaginary) { imaginary_ = imaginary; };

private:
	double real_;
	double imaginary_;
};

