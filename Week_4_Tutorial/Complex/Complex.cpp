#include "complex.h"

Complex Complex::conjugate() const {
	return Complex(real_, -imaginary_);
}

double Complex::modulus() {
	return std::sqrt(std::pow(real_, 2) + std::pow(imaginary_, 2));
};

double Complex::argument() {
	return std::atan2(imaginary_, real_);
};


static Complex make_conjugate(Complex const& z) {
	return z.conjugate();

}

Complex operator+(Complex const& lhs, Complex const& rhs) {
	return { lhs.real_ + rhs.real_, lhs.imaginary_ + rhs.imaginary_ };
}

Complex operator-(Complex const& lhs, Complex const& rhs) {
	return { lhs.real_ - rhs.real_, lhs.imaginary_ - rhs.imaginary_ };
}

Complex operator*(Complex const& lhs, Complex const& rhs) {
	return { (lhs.real_ * rhs.real_) - (lhs.imaginary_*rhs.imaginary_), 
		(lhs.real_ * rhs.real_) + (lhs.imaginary_ * rhs.imaginary_) };
}


bool operator==(Complex const& lhs, Complex const& rhs) {
	return { (lhs.real_ == rhs.real_) &&
		(lhs.imaginary_ == rhs.imaginary_)
	};
}

bool operator!=(Complex const& lhs, Complex const& rhs) {
	return !operator==(lhs, rhs);
}

std::ostream& operator<<(std::ostream& os, Complex const& z) {
	os << z.real_ << "+" << z.imaginary_ << "i";
	return os;
};