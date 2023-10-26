#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // convert strings to numbers
    std::stringstream sst {"54321 98.76"};
    // int iNum2 {};
    // double dNum2 {};
    // sst >> iNum2 >> dNum2;                
    // std::cout << iNum2 << '@' << dNum2 << '\n';
    
    // split string
    std::string myStr {"UNSW-MTRN-2500-20T3-C++"};
    sst.str(myStr);                 // create string stream from the string
    //std::cout << sst.eof() << '\n'; // eof flag is true from previous operations
    sst.clear();                    // reset flags of string stream - Set all bits to 0/ 
    std::vector<std::string> result {}; 
        std::string subStr {};


    while (sst.good()) {
        std::getline(sst, subStr, '-'); // get first string delimited by '-'
        std::cout << "First " << subStr << "\n";
        std::getline(sst, subStr, '-'); // get first string delimited by '-'
        std::cout <<  "Second " << subStr << "\n";
        
        result.push_back(subStr);
    }
    // {"UNSW", "MTRN"}

    // for (const auto &elem : result) { // print all splitted strings
    //     std::cout << elem << '\n';
    // }

    // //convert numbers to strings and buffering
    // int iNum1 {12345};
    // double dNum1 {67.89};
    // sst.str("");
    // sst.clear();
    // sst << iNum1 << '#' << dNum1 << '\n';
    // std::cout << sst.str();

    return 0;
}