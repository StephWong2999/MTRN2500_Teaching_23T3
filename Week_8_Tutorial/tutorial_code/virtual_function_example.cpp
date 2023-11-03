#include <iostream>
#include <string>


class A {
public:
    virtual std::string getName() const { return "A"; }
};

class B: public A {
public:
    virtual std::string getName() const { return "B"; }
};

class C: public B {
public:
    // note: no getName() function here
};

class D: public C {
public:
    virtual std::string getName() const { return "D"; }
};

int main() {
    
    // Ex 1
    B b{};
    A& bBase{b};
    std::cout << bBase.getName() << std::endl; // “B”

    // Ex 2
    D d{};
    A& dBase{d};
    std::cout << dBase.getName() << std::endl; // “D”

    // Ex 3
    C c{};
    A& cBase{c};
    std::cout << cBase.getName() << std::endl; // “B”
}