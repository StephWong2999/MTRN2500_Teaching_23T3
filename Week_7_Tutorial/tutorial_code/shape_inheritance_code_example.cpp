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

// Derived Class - Circle
class Circle : public Shape {
public:
    Circle(double radius = 2.0) : mRadius{radius} {};
    double getRadius() const {return mRadius;};
    void setRadius(double radius) {mRadius = radius;};
private:
    double mRadius{};
};

// Derived Class - Rectangle 
class Rectangle : public Shape {
public:
    Rectangle(const std::string& color = "blue", double length = 2.0, double width = 3.0) 
        : Shape{color}, mWidth{width}, mLength{length} {};
    double getWidth() const {return mWidth;};
    void setWidth(double Width) {mWidth = Width;};
    double getLength() const {return mLength;};
    void setLength(double length) {mLength = length;};
private:
    double mWidth{};
    double mLength{};
};


/*
TODO:
1. Implement Derived Class - Rectangle
2. Set the color of Circle to blue from default orange 
*/



int main() {

    Shape shape{};
    std::cout << "The colour of shape is: " << shape.getColor() << std::endl;
    // The colour of the shape is: orange\n

    Circle circle{};
    std::cout << "The colour of circle is: " << circle.getColor() << std::endl;
    // The colour of the circle is: orange\n”
    circle.setColor("blue");
    std::cout << "The colour of circle is: " << circle.getColor() << std::endl;



    //Rectangle rectangle{};
    //std::cout << "The colour of rectangle is: " << rectangle.getColor() << std::endl;
    // Constructing -> Base -> Derived
    // Destructing -> Derived -> Based


    return 0;
}