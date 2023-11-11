













#include <iostream>
#include <string>

template <class T>
class Vehicle {
public:
    std::string make;
    std::string model;
    int year;
    double rentalPrice;
    T specificAttribute;

    void inputDetails() {
        std::cin >> make >> model >> year >> rentalPrice >> specificAttribute;
    }

    virtual void displayDetails() const = 0;
};

class Car : public Vehicle<int> {
public:
    void displayDetails() const override {
        std::cout << make << " " << model << " " << year << " " << rentalPrice << std::endl;
        std::cout << specificAttribute << std::endl;
    }
};

class Motorcycle : public Vehicle<std::string> {
public:
    void displayDetails() const override {
        std::cout << make << " " << model << " " << year << " " << rentalPrice << std::endl;
        std::cout << specificAttribute << std::endl;
    }
};

int main() {
    Car car;
    Motorcycle motorcycle;

    std::cout << "Vehicle Details:" << std::endl;

    car.inputDetails();
    motorcycle.inputDetails();

    car.displayDetails();
    motorcycle.displayDetails();

    return 0;
}
