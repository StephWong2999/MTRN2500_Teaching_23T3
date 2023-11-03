#include <iostream>

struct Base {
    Base() { std::cout << "Creating Base." << std::endl; }
    ~Base() { std::cout << "Destroying Base." << std::endl; }
};

struct Derived : public Base {
    Derived() { std::cout << "Creating Derived." << std::endl; }
    ~Derived() { std::cout << "Destroying Derived." << std::endl; }
};

int main() {
    Base* b = new Derived;  // Up-cast.
    delete b;
    
    // What is the output?
    // Does this create an issue?
    // How do we fix this?
}