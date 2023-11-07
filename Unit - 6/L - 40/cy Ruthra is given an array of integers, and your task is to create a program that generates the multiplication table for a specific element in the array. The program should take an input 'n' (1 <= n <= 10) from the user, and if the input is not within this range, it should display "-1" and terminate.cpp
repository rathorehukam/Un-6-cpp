









#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {11, 21, 33, 14, 41, 60, 13, 8, 25, 50};
    int n;
    std::cin >> n;

    if (n < 1 || n > 10) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    std::vector<int>::iterator it = arr.begin() + (n - 1);
    int baseNumber = *it;

    for (int i = 1; i <= 10; ++i) {
        int result = baseNumber * i;
        std::cout << baseNumber << " * " << i << " = " << result << std::endl;
    }

    return 0;
}
