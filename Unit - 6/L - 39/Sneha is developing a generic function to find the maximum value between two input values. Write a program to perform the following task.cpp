









#include <iostream>

template <class T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
int int1, int2;
    double double1, double2;

    std::cin >> int1 >> int2 >> double1 >> double2;

    int maxInt = maxValue(int1, int2);
    double maxDouble = maxValue(double1, double2);

    std::cout << "Maximum value: " << maxInt << std::endl;
    std::cout << "Maximum value: " << maxDouble << std::endl;

    return 0;
}
