#include <iostream>
#include <string>
#include <array>

// define a class template
template <typename T, int N>
class MyArray {
public:
    MyArray() = default;
    T at(int i) const {
        return mData[i];
    };
    void set(int i, T val) const {
        mData[i] = val;
    }
private:
    std::array<T,N> mData{};
};

// template<typename T, int N>
// T MyArray<T,N>::at(int i) const {
//     return mData[i];
// }

// template<typename T, int N>
// void MyArray<T,N>::set(int i, T val) const {
//     mData[i] = val;
// }

int main () {
    // with class template
    MyArray<int, 3> myArray1{};
    myArray1.set(0,0);
    std::cout << myArray1.at(0) << "\n";

    MyArray<std::string, 4> myArray2{};
    myArray2.set(2, "UNSW"); // "UNSW"
    std::cout << myArray2.at(2) << '\n';

    return 0;
}