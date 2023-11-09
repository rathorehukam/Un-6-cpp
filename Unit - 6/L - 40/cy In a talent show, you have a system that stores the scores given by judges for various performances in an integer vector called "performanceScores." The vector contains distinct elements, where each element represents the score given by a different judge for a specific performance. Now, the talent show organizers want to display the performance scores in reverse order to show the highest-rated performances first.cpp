





#include <iostream>
#include <vector>

void customReverse(std::vector<int>& performanceScores) {
    int n = performanceScores.size();
    for (int i = 0; i < n / 2; i++) {
        int temp = performanceScores[i];
        performanceScores[i] = performanceScores[n - i - 1];
        performanceScores[n - i - 1] = temp;
    }
}

int main() {
    int n;
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Invalid input\n";
        return 0;
    }
    std::vector<int> performanceScores(n);
    for (int i = 0; i < n; i++) {
        std::cin >> performanceScores[i];
    }
    customReverse(performanceScores);
    for (int i = 0; i < n; i++) {
        std::cout << performanceScores[i] << (i < n - 1 ? " " : "");
    }
    std::cout << '\n';  
    return 0;
}
