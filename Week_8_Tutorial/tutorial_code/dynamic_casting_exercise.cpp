#include <iostream>


struct Base {
    void foo() { std::cout << "Base." << std::endl; }
};

struct Derived : public Base {
    void foo() { std::cout << "Derived." << std::endl; }
};

int main () {

    Base b;
    Derived d;
    b.foo();
    d.foo();

    // TODO: Demonstrate up-casting (i.e. from Derived* to Base*). 
    // What is the expected output of foo() on the casted object?
    // Base* b_ptr{dynamic_cast<Base*>(&d)};
    // b_ptr->foo();

    return 0;
}