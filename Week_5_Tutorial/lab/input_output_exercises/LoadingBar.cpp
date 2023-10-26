#include <iomanip>
#include <ios>
#include <iostream>

int main() {
    int num_bars;
    std::cin >> num_bars;
    for (int i = 0; i <= num_bars; i++) {
        std::cout << "[";
        std::cout << std::setfill('*') << std::setw(i) << "";
        std::cout << std::setfill(' ') << std::setw(num_bars - i) << "";
        std::cout << "] ";
        std::cout << std::setw(6) << std::right << std::fixed << std::setprecision(2)
                  << static_cast<float>(i) / num_bars * 100 << "%" << std::endl;
    }
}