#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main() {
    std::string filename {"test.txt"};

    // Write to file
    std::ofstream ofst {filename};      // default mode is std::ios::out | std::ios::trunc
    if (!ofst) {
        throw std::runtime_error("error: open file for output failed!\n");
    }

    
    ofst << "apple" << '\n';
    ofst.close();                       // flush and close
    
    // Write to file again
    ofst.open(filename, std::ios::out|std::ios::app);   // output appends at the end
    if (!ofst) {
        throw std::runtime_error("error: open file for output failed!\n");
    }
    ofst << "orange" << '\n';
    ofst << "banana" << '\n';           // newline
    // ofst << "banana" << std::endl;  // newline + flush
    ofst.close();

    // Read from file
    std::ifstream ifst {filename};      // default mode std::ios::in
    if (!ifst) {
        throw std::runtime_error("error: open file for input failed!\n");
    }
    
    // Use get() to read char by char
    char ch {};
    while (ifst.get(ch)) {          // till end-of-file
        std::cout << ch;
    }
    ifst.close();

    // Read from file
    ifst.open(filename);            // default mode std::ios::in
    if (!ifst) {
        throw std::runtime_error("error: open file for input failed!\n");
    }
    // use getline() to read line by line
    std::string str {};
    while (std::getline(ifst, str)) {   // till end-of-file
        std::cout << str << '\n';
    }
    ifst.close();

    return 0;
}

