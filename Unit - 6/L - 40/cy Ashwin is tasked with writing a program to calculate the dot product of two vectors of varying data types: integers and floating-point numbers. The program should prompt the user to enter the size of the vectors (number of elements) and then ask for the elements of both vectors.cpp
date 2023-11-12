











#include <iostream>
#include <vector>

template<class T>
T dotProduct(const std::vector<T>& v1, const std::vector<T>& v2) {
    T result = 0;

    for (int i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v1(n), v2(n);
    std::vector<double> v3(n), v4(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v1[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> v2[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> v3[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> v4[i];
    }

    int intDotProduct = dotProduct(v1, v2);
    double doubleDotProduct = dotProduct(v3, v4);

    std::cout << "Dot product of integer vectors: " << intDotProduct << std::endl;
    std::cout << "Dot product of floating-point vectors: " << doubleDotProduct << std::endl;

    return 0;
}
