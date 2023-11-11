











#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {11, 21, 33, 14, 41, 60, 13, 8, 25, 50};

    int n;
    std::cin >> n;

    if (n < 1 || n > 10) {
        std::cout << "-1" << std::endl;
        return -1; // Terminate with an error code
    }

    auto it = arr.begin() + n - 1;
    // Get the n-th element from the array
    int baseNumber = *it;

    for (int i = 1; i <= 10; ++i) {
        std::cout << baseNumber << " * " << i << " = " << (baseNumber * i) << std::endl;
    }

    return 0; // Successful execution
}
