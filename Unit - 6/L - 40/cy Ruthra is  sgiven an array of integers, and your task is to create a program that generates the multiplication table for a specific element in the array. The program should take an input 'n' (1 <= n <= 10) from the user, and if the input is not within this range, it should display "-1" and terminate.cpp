





#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> arr = {11, 21, 33, 14, 41, 60, 13, 8, 25, 50};

    int n;
    std::cin >> n;

    if (n < 1 || n > 10) {
        std::cout << "-1" << std::endl;
        return 1; // Terminating with an error code
    }

    std::vector<int>::iterator it = arr.begin();
    std::advance(it, n - 1); // Adjust for 0-based indexing

    int baseNumber = *it;
    for (int i = 1; i <= 10; ++i) {
        std::cout << baseNumber << " * " << i << " = " << baseNumber * i << std::endl;
    }

    return 0; // Program executed successfully
}
