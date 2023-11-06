




#include <iostream>
#include <vector>

template <typename T>
T calculateTotalRevenue(const std::vector<T>& bookings) {
    T totalRevenue = 0;
    for (const T& amount : bookings) {
        totalRevenue += amount;
    }
    return totalRevenue;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<double> bookingAmounts(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> bookingAmounts[i];
    }

    double totalRevenue = calculateTotalRevenue(bookingAmounts);

    std::cout << totalRevenue << std::endl;

    return 0;
}
