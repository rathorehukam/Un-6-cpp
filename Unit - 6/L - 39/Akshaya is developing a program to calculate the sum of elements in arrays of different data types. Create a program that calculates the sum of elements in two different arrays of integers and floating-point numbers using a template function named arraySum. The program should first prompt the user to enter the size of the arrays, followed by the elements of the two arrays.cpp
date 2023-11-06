










#include <iostream>

template<class T>
T arraySum(T arr[], int n) {
    T sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n; 
    int intArray[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> intArray[i];
    }

    float floatArray[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> floatArray[i];
    }

    std::cout << "Sum of integer array: " << arraySum(intArray, n) << std::endl;

    std::cout << "Sum of floating-point array: " << arraySum(floatArray, n) << std::endl;

    return 0;
}
