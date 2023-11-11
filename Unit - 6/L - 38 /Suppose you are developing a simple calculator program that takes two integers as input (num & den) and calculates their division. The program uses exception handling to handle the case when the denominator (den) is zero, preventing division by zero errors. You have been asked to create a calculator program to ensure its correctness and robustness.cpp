








#include <iostream>

int main() {
    try {
        int num, den;
        std::cin >> num >> den;

        if (den == 0) {
            throw "Divide by Zero Exception";
        } else {
            double result = static_cast<double>(num) / den;
            std::cout << static_cast<int>(result) << std::endl;  // Adjusted output to match the expected result.
        }
    } catch (const char* errorMsg) {
        std::cout << errorMsg << std::endl;
    }

    return 0;
}
