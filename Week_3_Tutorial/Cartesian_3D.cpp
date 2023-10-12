#include <iostream>
#include <vector>
#include <tuple>

// Define a representation for a 3D cartesian space using std::tuple. 
// Write a short program to demonstrate how it should be initialised and printed.
int main() {
	std::tuple<double, double, double> t1{ 0.0, 0.0,0.0 };
	std::tuple<double, double, double> t2{ 1.0, 1.0,1.0 };

	std::vector<std::tuple<double, double, double>> cartesian_space{
		{ 0.0, 0.0,0.0 },
		{ 1.0, 1.0,1.0 },
		{ 0.0, 0.0,0.0 }
	};

	for (auto const& point : cartesian_space) {
		std::cout << "pt 1" << std::get<0>(point) << "pt 2" 
			<< std::get<1>(point) << "pt 3" << std::get<2>(point) << std::endl;

	}

	std::cout << "pt 1" << std::get<0>(t1) << "pt 2" << std::get<1>(t1) << "pt 3"
		<< std::get<2>(t1) << std::endl;


}

