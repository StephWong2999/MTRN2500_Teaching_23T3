/*
The following program contains an assign() function which throws std::runtime_error 
if the user tries to assign var with an even value. This exception currently crashes 
the program. Modify the following program so that if the exception is thrown, 
cleanup() is applied on the faulty variable, and the program does not crash.
Do not modify assign() and cleanup().
*/

#include <stdexcept>

void assign(int& var, int const& value) {
    if (value % 2 == 0) {
        throw std::runtime_error("Illegal assignment.");
    }
    var = value;
}

void cleanup(int& var) {
    var = 0;
}

int main() {
    int a{0};
    int b{0};

    // MODIFY BELOW HERE.
    try {
        assign(a, 42);
    } catch (std::runtime_error const& e) {
        cleanup(a);
    } 

    try {
        assign(b, 31);
    } catch (std::runtime_error const& e) {
        cleanup(b);
    } catch(...) {
        // do whatever
    }





}