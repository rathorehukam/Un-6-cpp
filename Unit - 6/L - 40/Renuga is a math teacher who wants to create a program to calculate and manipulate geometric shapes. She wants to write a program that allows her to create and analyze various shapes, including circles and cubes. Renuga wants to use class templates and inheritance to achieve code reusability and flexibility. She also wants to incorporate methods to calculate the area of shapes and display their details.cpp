










#include <iostream>
#include <cmath>

template <typename T>
class Shape {
public:
    virtual void readInput() = 0;
    virtual void displayDetails() = 0;
    virtual T calculateArea() = 0;
};

template <typename T>
class Circle : public Shape<T> {
private:
    T radius;
    T centerX, centerY;

public:
    void readInput() override {
        std::cin >> radius >> centerX >> centerY;
    }

    void displayDetails() override {
        std::cout << "Circle Details:" << std::endl;
        std::cout << "Circle with radius: " << radius << std::endl;
        std::cout << "Area: " << calculateArea() << std::endl;
    }

    T calculateArea() override {
        return 3.14159265358979323846 * radius * radius;
    }
};

template <typename T>
class Cube : public Shape<T> {
private:
    T sideLength;
    T centerX, centerY, centerZ;

public:
    void readInput() override {
        std::cin >> sideLength >> centerX >> centerY >> centerZ;
    }

    void displayDetails() override {
        std::cout << "Cube Details:" << std::endl;
        std::cout << "Cube with side length: " << sideLength << std::endl;
        std::cout << "Surface area: " << calculateArea() << std::endl;
    }

    T calculateArea() override {
        return 6 * sideLength * sideLength;
    }
};

int main() {
    int shapeType;
    std::cin >> shapeType;

    Shape<double>* shape = nullptr;

    switch (shapeType) {
        case 1:
            shape = new Circle<double>();
            break;
        case 2:
            shape = new Cube<double>();
            break;
        default:
            std::cout << "Invalid shape type selected." << std::endl;
            return 0;
    }

    shape->readInput();
    shape->displayDetails();

    delete shape;

    return 0;
}
