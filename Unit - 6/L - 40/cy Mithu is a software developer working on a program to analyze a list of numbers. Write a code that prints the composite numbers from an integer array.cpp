





#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

bool isComposite(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;

    if (n < 1 || n > 15) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Composite numbers:";

    std::remove_copy_if(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "),
                        [](int num) { return !isComposite(num); });

    return 0;
}
