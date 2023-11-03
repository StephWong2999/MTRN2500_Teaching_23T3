#include <iostream>
#include <string>

class Base {
public:
    virtual void mustImplement() const = 0; // pure virtual function
};

class Child : public Base {
public:
    void mustImplement() const {
        std::cout << "Implemented!" << std::endl;
    }
};

int main() {
    // TODO: Implement Base
    Child c;
    c.mustImplement();
    return 0;
}
























// class Child : public Base {
// public:
//     void mustImplement() const {
//         std::cout << "Implemented" << std::endl;
//     }
// };