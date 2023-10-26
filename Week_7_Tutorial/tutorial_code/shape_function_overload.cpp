#include <iostream>
#include <string>

// Base Class - Shape
class Shape {
public:
    Shape (const std::string& color = "orange") : mColor{color} {};
    std::string getColor() const {return mColor;};
    void setColor(const std::string& color) {mColor = color;};
private:
    std::string mColor{};

};

// Derived Class - Circle. 
// How can the getColor function be overloaded
class Circle : public Shape {
public:
    Circle(double radius = 2.0) 
        : mRadius{radius} {};
    double getRadius() const {return mRadius;};
    void setRadius(double radius) {mRadius = radius;};
    // Overloaded Function - The getColor function is overloaded from Base Class
    //std::string getColor() const {return mColor;};
private:
    //std::string mColor{"green"};
    double mRadius{};
};


int main() {

    Shape shape{};
    std::cout << "The colour of shape is: " << shape.getColor() << std::endl;
    // The colour of the shape is: orange\n

    Circle circle{};
    std::cout << "The colour of circle is: " << circle.getColor() << std::endl;
    // The colour of the circle is: orange\n”

    // Run Overloaded Operator
    //std::cout << "The colour of circle is: " << circle.Shape::getColor() << std::endl;


    return 0;
}