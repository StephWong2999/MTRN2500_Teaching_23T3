#include <iostream>
#include "complex.h"


int main(void) {

	auto complex1 = Complex(1.2, 3.5);
	auto complex2 = Complex(5.3, 2.1);

	auto complex3 = complex1 + complex2;

	std::cout << complex3;

}

