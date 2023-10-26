#include <iomanip> 
#include <iostream> 
#include <limits>
  
int main() 
{ 
    std::string name {};
    std::string firstName {};
    std::string lastName {};

    // Input and output using >> and << operators
    std::cout << "Please enter your full name (FirstName LastName): ";
    std::cin >> firstName >> lastName;
    std::cout << "Welcome to MTRN2500,  " << firstName << " " << lastName << "!\n";

    // Discard everything in the input stream including the newline
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Please enter your full name (FirstName LastName) again: ";
    std::getline(std::cin, name);
    std::cout << "Welcome to MTRN2500 again,  " << name << "!\n";




    return 0; 
} 