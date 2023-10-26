#include <iostream>
#include <iomanip>

int main() {
   
    // default precision is 6, i.e., 6 digits overall
    std::cout << "|" << 123.456789 << "|\n";                // |123.457| (fixed-point format)
    std::cout << "|" << 1234567.89 << "|\n";                // |1.23457e+006| (scientific-notation for e>=6)

    // showpoint - show trailing zeros in default mode
    std::cout<< std::showpoint << "|" << 123. << "|\n";     // |123.000|
    std::cout<< std::noshowpoint << "|" << 123. << "|\n";   // |1   // fixed-oi t formatting, defaults to 6 digits after the decimal point
    std::cout<< std::fixed;
    std::cout<< "|" << 1234567.89 << "|\n";                 // |1234567.890000|
    
    // scientfic  formatting
    std::cout<< std::scientific;
    std::cout<< "|" << 1234567.89 << "|\n";                 // |1.234568e+006|
    
    // setprecision to be n digits after the decimal point
    std::cout<< std::fixed << std::setprecision(2);
    std::cout<< "|" << 123.456789 << "|\n";                 // |123.46|
    std::cout<< "|" << 123. << "|\n";                       // |123.00|
    std::cout<< std::setprecision(0);
    std::cout<< "|" << 123.456789 << "|\n";                 // |123|

    return 0;
}
