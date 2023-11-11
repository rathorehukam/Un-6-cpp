











#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

// ... (previous code)

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

    double totalArea = circle.calculateArea() + square.calculateArea() + triangle.calculateArea();

    // Output with fixed precision
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total area of all shapes: " << totalArea << std::endl;

    return 0;
}
