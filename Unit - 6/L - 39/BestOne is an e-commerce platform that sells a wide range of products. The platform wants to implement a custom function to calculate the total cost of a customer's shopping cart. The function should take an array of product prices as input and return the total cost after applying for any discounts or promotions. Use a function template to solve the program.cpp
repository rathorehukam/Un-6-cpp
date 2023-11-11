




#include <iostream>
#include <vector>

template <typename T>
T calculateTotalCost(const std::vector<T>& prices) {
    T totalCost = 0;

    for (const T& price : prices) {
        totalCost += price;
    }

    return totalCost;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<double> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    double totalCost = calculateTotalCost(prices);
    std::cout << totalCost << std::endl;

    return 0;
}
