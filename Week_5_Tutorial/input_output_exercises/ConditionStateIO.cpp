#include <iostream>

int main() {

    do {
        std::cout << "Please input an integer number:\n";
        int input {};
        std::cin >> input;
        std::cout << "Your input was " << input << '\n';
        std::cout << "goodbit: " << std::cin.good() << '\n';
        std::cout << "eofbit: " << std::cin.eof() << '\n';
        std::cout << "failbit: " << std::cin.fail() << '\n';
        std::cout << "badbit: " << std::cin.bad() << '\n';
    } while (std::cin.good());

    if (std::cin.eof()) {
        std::cerr << "End-of-file reached\n";
    } else if (std::cin.bad()) {
        std::cerr << "Read/write error\n";
    } else if (std::cin.fail()) {
        std::cerr << "Logical error\n";
    } else {
        std::cerr << "There was somehow an error!";
    }

    return 0;

}