/*
Convert the following program such that it uses a function template instead of function overloads:
*/

#include <iostream>

// void print(double var) { std::cout << var << std::endl; }
// void print(int var) { std::cout << var << std::endl; }
// void print(std::string var) { std::cout << var << std::endl; }
// void print(char var) { std::cout << var << std::endl; }

template <typename T> 
T print(T var){
    std::cout << var << std::endl;
    return var;
}

int main() {
    print(3.23); // return 3.23
    print(3); // return 3
    print("t3af4");
    print('!');
}




/*
template <typename T>
void print(T var) {
    std::cout << var << std::endl;
    // We can even define variables of type T now
    T t{var};
}

*/