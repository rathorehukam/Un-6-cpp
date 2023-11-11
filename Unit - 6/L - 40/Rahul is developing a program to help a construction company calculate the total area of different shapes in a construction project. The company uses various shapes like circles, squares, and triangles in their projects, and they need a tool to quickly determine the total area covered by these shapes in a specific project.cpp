












#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

// Define class templates for Circle, Square, and Triangle
template <typename T>
class Circle {
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    T area() const {
        return M_PI * radius * radius;
    }
};

template <typename T>
class Square {
private:
    T side;

public:
    Square(T s) : side(s) {}

    T area() const {
        return side * side;
    }
};

template <typename T>
class Triangle {
private:
    T base, height;

public:
    Triangle(T b, T h) : base(b), height(h) {}

    T area() const {
        return 0.5 * base * height;
    }
};

int main() {
    std::string circleName, squareName, triangleName;
    double circleRadius, squareSide, triangleBase, triangleHeight;

    // Input
    std::getline(std::cin, circleName);
    std::cin >> circleRadius;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
    std::getline(std::cin, squareName);
    std::cin >> squareSide;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
    std::getline(std::cin, triangleName);
    std::cin >> triangleBase >> triangleHeight;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

    // Calculations
    Circle<double> circle(circleRadius);
    Square<double> square(squareSide);
    Triangle<double> triangle(triangleBase, triangleHeight);

    // Calculate total area
    double totalArea = circle.area() + square.area() + triangle.area();

    // Output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total area of all shapes: " << totalArea << std::endl;

    return 0;
}
