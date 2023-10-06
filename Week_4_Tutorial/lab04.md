# MTRN2500 - Lab04 (Classes II & STL)

## Learning Outcomes

This week's lab exercises cover:
- More C++ classes:
  - More constructors i.e. copy and move constructors, copy and move assignment operators.
  - Differences between methods, static methods, and friend functions.
  - Operator overloading.
- STL:
  - Iterators.
  - STL algorithms.
  - Lambda functions.
  - STL containers.
  - Iterator adaptors.

## Classes II

<details>
  <summary><b>View tasks</b></summary>
  
### Exercise: Complex (Continued)

Take the `Complex` class from a previous lab and extend it with the following specification:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>Complex(Complex const& z)</code></td>
        <td>Copy constructor. </td>
        <td><pre><code>Complex z1;
Complex z2(z1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex(Complex&& z)</code></td>
        <td>Move constructor. </td>
        <td><pre><code>Complex z1;
Complex z2(std::move(z1));</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex& operator=(Complex const& z)</code></td>
        <td>Copy assignment. </td>
        <td><pre><code>Complex z1;
Complex z2;
z2 = z1;</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex& operator=(Complex&& z)</code></td>
        <td>Move assignment. </td>
        <td><pre><code>Complex z1;
Complex z2;
z2 = std::move(z1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>static Complex make_conjugate(Complex const& z)</code></td>
        <td>Returns the conjugate of <code>z</code>. Equivalent to <code>z.conjugate()</code>.</td>
        <td><pre><code>Complex z1(42, 75); // z1 = 42 + 75i
Complex z2{Complex::make_conjugate(z1)}; // z2 = 42 - 75i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend Complex operator+(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns the addition of two complex numbers.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3{z1 + z2}; // z3 = 7 + 9i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend Complex operator-(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns the subtraction of two complex numbers.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3{z1 - z2}; // z3 = -1 + -1i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend Complex operator*(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns the multiplication of two complex numbers.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3{z1 * z2}; // z3 = -8 + 31i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend bool operator==(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns true if real components are equal and imaginary components equal.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3(4, 5); // z3 = 4 + 5i
bool t1{z1 == z2}; // false
bool t2{z2 == z3}; // true</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend bool operator!=(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns false if real components are equal and imaginary components equal.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3(4, 5); // z3 = 4 + 5i
bool t1{z1 != z2}; // true
bool t2{z2 != z3}; // false</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend std::ostream& operator<<(std::ostream& os, Complex const& z)</code></td>
        <td>Writes the complex number to the output in the format <code>a+bi</code> where <code>a</code> and <code>b</code> are the real and imaginary component respectively.</td>
        <td><pre><code>Complex z(3, 4); // z = 3 + 4i
std::cout &lt;&lt; z; // 3+4i</code></pre></td>
        <td>None</td>
    </tr>
</table>

In addition to the above specification, you must:
- Implement `const`-correctness for methods and member variables.
- Mark appropriate constructors, assignments, and destructor as `default` or `delete`.
- Have correct access specifiers.
- Write more tests for the new methods.



---

### Exercise: Simple Robot (Continued)

Take the `Robot` class from a previous lab and extend it with the following specification:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>Robot(Robot const& r)</code></td>
        <td>Copy constructor. </td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2(r1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Robot(Robot&& r)</code></td>
        <td>Move constructor. </td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2(std::move(r1));</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Robot& operator=(Robot const& r)</code></td>
        <td>Copy assignment.</td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2("r2", 2, 0);
r1 = r2;</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Robot& operator=(Robot&& r)</code></td>
        <td>Move assignment.</td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2("r2", 2, 0);
r1 = std::move(r2);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>static std::pair&lt;double, double&gt; cartesian_to_polar(std::pair&lt;double, double&gt; const& val)</code></td>
        <td>Converts a cartesian coordinate to polar coordinate.</td>
        <td><pre><code>std::pair&lt;double, double&gt; carte{3, 4};
std::pair&lt;double, double&gt; polar{Robot::cartesian_to_polar(carte)}; // (5, 0.9273)</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend std::ostream& operator&lt;&lt;(std::ostream& os, Robot const& r)</code></td>
        <td>Writes the name, number of wheels, number of sensors, cartesian coordinates, and polar coordinates of the robot.</td>
        <td><pre><code>Robot r("r", 4, 7);
r.move(3, 4);
std::cout &lt;&lt; r; // "r", 4, 7, (3, 4), (5, 0.9273)</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend std::istream& operator&lt;&lt;(std::istream& is, Robot& r)</code></td>
        <td>Inputs the <code>x</code> then <code>y</code> coordinates for the robot. It is equivalent to <code>r.move(x, y)</code>.</td>
        <td><pre><code>Robot r("r", 4, 7);
std::cin >> r; // 3 4</code></pre></td>
        <td>None</td>
    </tr>
</table>

In addition to the above specification, you must:
- Implement `const`-correctness for methods and member variables.
- Mark appropriate constructors, assignments, and destructor as`default` or `delete`.
- Have correct access specifiers.
- Write more tests for the new methods.



---

### Methods vs Static Methods vs Friend Functions

Consider the following example class with a variety of function types and how they are used:
```cpp
struct MyFunctions {
    void foo1();
    static void foo2();
    friend void foo3();
};

int main() {
    MyFunctions mf;
    mf.foo1();
    MyFunctions::foo2();
    foo3();
}
```

When should one use these different function types?



---

### Challenge: Implement a Shared Pointer (Continued)

Take the `SharedPointer` class from **lab03-1** and extend it with the following specification:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>SharedPointer(SharePointer const& sp)</code></td>
        <td>Copy constructor. The use count should increase by 1.</td>
        <td><pre><code>SharedPointer sp1;
SharedPointer sp2(sp1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>SharedPointer(SharePointer&& sp)</code></td>
        <td>Move constructor. The use count should not increase.</td>
        <td><pre><code>SharedPointer sp1;
SharedPointer sp2(std::move(sp1));</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>SharedPointer& operator=(SharePointer const& sp)</code></td>
        <td>Copy assignment. The use count should increase by 1.</td>
        <td><pre><code>SharedPointer sp1;
SharedPointer sp2;
sp2 = sp1;</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>SharedPointer& operator=(SharePointer&& sp)</code></td>
        <td>Move assignment. The use count should not increase.</td>
        <td><pre><code>SharedPointer sp1;
SharedPointer sp2;
sp2 = std::move(sp1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend bool operator==(SharedPointer const& lhs, SharedPointer const& rhs)</code></td>
        <td>Returns true if the values of the resources owned by <code>lhs</code> and <code>rhs</code> are the same.</td>
        <td><pre><code>int* ptr{new int{42}};
SharedPointer sp1(ptr);
SharedPointer sp2(ptr);
sp1 == sp2; // true</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend std::ostream& operator&lt;&lt;(std::ostream& os, SharedPointer const& sp)</code></td>
        <td>Outputs the value of the resource owned by <code>*this</code>.</td>
        <td><pre><code>int* ptr{new int{42}};
SharedPointer sp(ptr);
std::cout &lt;&lt; sp; // &ptr</code></pre></td>
        <td>None</td>
    </tr>
</table>


</details>

---

## STL
<details>
<summary><b>View tasks</b></summary>

### Exercise: Iterators

What is an iterator?



Where in `std::vector` does `std::vector::begin()` and `std::vector::end()` point to?



How would one obtain the datatype of the iterator for `std::vector<int>`?



Write a program that uses iterators in a for-loop to print each element of `std::set`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<double> s{0.2, 1.41, 12.2, 43.3};

    // WRITE YOUR SOLUTION HERE.
}
```



---

### Iterator Types

C++14 has five types of iterators. Fill out the following table to compare their differences.

<table>
    <tr>
        <th>Iterator Type</th>
        <th>Read/Write Operation</th>
        <th>Read/Write Access Order</th>
    </tr>
    <tr>
        <td><code>InputIterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>OutputIterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>ForwardIterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>BidirectionalIterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>RandomAccessIterator</code></td>
        <td></td>
        <td></td>
    </tr>
</table>



---

### Exercise: STL Algorithms

STL algorithms are convenience functions that lets us interact with STL containers via iterators. There is a list of what STL algorithms C++ provides: https://en.cppreference.com/w/cpp/algorithm.

What is the main header library for most STL algorithms?



What are typically the first two parameters of an STL algorithm?



Write a program which uses an STL algorithm to assign every element of `vec` of size `vec_size` with `value`. The first line of input is `vec_size`. The second line of input is `value`.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td><pre><code>0
1</code></pre></td>
        <td><pre><code></code></pre></td>
    </tr>
    <tr>
        <td><pre><code>3
4</code></pre></td>
        <td><pre><code>4 4 4</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>5
0</code></pre></td>
        <td><pre><code>0 0 0 0 0</code></pre></td>
    </tr>
</table>

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Read in the vector size.
    int vec_size{0};
    std::cin >> vec_size;
    std::vector<int> vec(vec_size);

    // Read in the value.
    int value{0};
    std::cin >> value;

    // WRITE YOUR SOLUTION HERE.

    // To print the vector.
    for (auto const& i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
```



---

### Exercise: Lambda Functions

How do we change the default behaviour of an STL algorithm?



What is the signature of a lambda function?



What is a lambda function?



Modify the program from **Exercise: Iterators** such that it uses an STL algorithm and lambda function instead.



---

### Exercise: Splitting Pairs

Write a program which uses STL algorithms to split `vec` into `result1` and `result2`.

```cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<std::string, int>> vec{
        {"hello", 12382},
        {"apple", 2310},
        {"triangle", 814},
        {"world", 584},
        {"sentence", 9432},
    };
    std::vector<std::string> result1;
    std::vector<int> result2;

    // WRITE YOUR SOLUTION HERE.

    // To print the results.
    for (auto const& i : result1) {
        std::cout << i << " " << std::endl;
    }
    std::cout << std::endl;

    for (auto const& i : result2) {
        std::cout << i << " " << std::endl;
    }
    std::cout << std::endl;
}
```



---

### Exercise: Counting Upper Case Characters

Write a program which uses an STL algorithm to count how many upper case characters there are in `str`.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td><pre><code></code></pre></td>
        <td><pre><code>0</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>ab52nc2b3a</code></pre></td>
        <td><pre><code>0</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>abcDEfg</code></pre></td>
        <td><pre><code>2</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>ABCDEFGHI</code></pre></td>
        <td><pre><code>9</code></pre></td>
    </tr>
</table>

```cpp
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    int count{0};

    // WRITE YOUR SOLUTION HERE.

    std::cout << count << std::endl;
}
```



---

### STL Containers

STL containers are convenience classes that stores data of any datatype. There is a list of what STL containers C++ provides: https://en.cppreference.com/w/cpp/container.

Define an appropriate data structure for looking up a person's name via their number ID.



Define an appropriate data structure for a line of people waiting to order food at a canteen. Represent people by their names i.e. `std::string`.



---

### Exercise: Counting String Occurrences

Write a program that counts each string occurrence in a vector of strings. The program should output the string in alphabetical order with its count.

Hint: consider defining an STL container to keep track of the string occurrences.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td><pre><code></code></pre></td>
        <td><pre><code></code></pre></td>
    </tr>
    <tr>
        <td><pre><code>Apple
Apple
Apple
Apple</code></pre></td>
        <td><pre><code>Apple: 4</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>Apple
Banana
Pear
Apple</code></pre></td>
        <td><pre><code>Apple: 2
Banana: 1
Pear: 1</code></pre></td>
    </tr>
</table>

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::string str;
    std::vector<std::string> vec;
    while (std::cin >> str) {
        vec.push_back(str);
    }

    // WRITE YOUR SOLUTION HERE.
}
```



---

### Iterator Adaptors

What is an iterator adaptor?



Fill out the following table comparing the different types of iterator adaptors. When filling out the *functionality* column, consider the arguments required to create the iterator adaptor.
<table>
    <tr>
        <th>Iterator Adaptor</th>
        <th>Functionality</th>
        <th>Iterator Type</th>
    </tr>
    <tr>
        <td><code>std::reverse_iterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>std::move_iterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>std::front_insert_iterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>std::back_insert_iterator</code></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><code>std::insert_iterator</code></td>
        <td></td>
        <td></td>
    </tr>
</table>



Some STL containers have applied the reverse iterator adaptor for you e.g. vector's [`rbegin`](https://en.cppreference.com/w/cpp/container/vector/rbegin) and [`rend`](https://en.cppreference.com/w/cpp/container/vector/rend).

---

### Exercise: Appending Max Element N Times

Write a program which appends the max element of a given container for another `n` number of times.

You may only use STL algorithms.

<table>
    <tr>
        <th>n</th>
        <th>Container</th>
        <th>Output</th>
    </tr>
    <tr>
        <td><pre><code>1</code></pre></td>
        <td><pre><code></code></pre></td>
        <td><pre><code>Throws "Vec is empty."</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>0</code></pre></td>
        <td><pre><code>1 2</code></pre></td>
        <td><pre><code>1 2</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>1</code></pre></td>
        <td><pre><code>0 0</code></pre></td>
        <td><pre><code>0 0 0</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>2</code></pre></td>
        <td><pre><code>0 5 1</code></pre></td>
        <td><pre><code>0 5 1 5 5</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>3</code></pre></td>
        <td><pre><code>9 1 1 2 3</code></pre></td>
        <td><pre><code>9 1 1 2 3 9 9 9</code></pre></td>
    </tr>
</table>

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Read in n.
    int n{0};
    std::cin >> n;

    // Read in the vector.
    int i{0};
    std::vector<int> vec;
    while (std::cin >> i) {
        vec.push_back(i);
    }

    // WRITE YOUR SOLUTION HERE.

    // To print the vector.
    for (auto const& i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
```



---

### Exercise: Last Occurrence

Write a program which uses an STL algorithm to find the last occurrence of a value given by `std::cin`. The index of the last occurrence should be printed out.

<table>
    <tr>
        <th>Value</th>
        <th>Container</th>
        <th>Output</th>
    </tr>
    <tr>
        <td><pre><code>23</code></pre></td>
        <td><pre><code>1 2 3</code></pre></td>
        <td><pre><code>Throws "Could not find value."</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>1</code></pre></td>
        <td><pre><code>1 1 1 1</code></pre></td>
        <td><pre><code>4</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>2</code></pre></td>
        <td><pre><code>1 1 2 1 1 1</code></pre></td>
        <td><pre><code>2</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>3</code></pre></td>
        <td><pre><code>2 1 2 2 3 2</code></pre></td>
        <td><pre><code>4</code></pre></td>
    </tr>
</table>

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Read in the value.
    int val{0};
    std::cin >> val;

    // Read in the vector.
    int i{0};
    std::vector<int> vec;
    while (std::cin >> i) {
        vec.push_back(i);
    }

    // WRITE YOUR SOLUTION HERE.

    std::cout << 42 << std::endl;
}
```



---

### Challenge: C-Style Iterating

Consider the program from **Exercise: Iterators**. Convert the C++ program to its C-style equivalent of iterating. Assume that `vec` has a fixed size of 4.

Hint: `begin()` and `end()` should not be used.



---

### Challenge: Counting Different Characters Between 2 Strings

Write a program which counts the number of different characters between 2 strings.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td><pre><code>abcdef
abd</code></pre></td>
        <td><pre><code>3</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>123
abc</code></pre></td>
        <td><pre><code>6</code></pre></td>
    </tr>
    <tr>
        <td><pre><code>1234
</code></pre></td>
        <td><pre><code>4</code></pre></td>
    </tr>
</table>

```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    int diff = 0;

    // WRITE YOUR SOLUTION HERE.

    std::cout << diff << std::endl;
}
```




</details>

---
