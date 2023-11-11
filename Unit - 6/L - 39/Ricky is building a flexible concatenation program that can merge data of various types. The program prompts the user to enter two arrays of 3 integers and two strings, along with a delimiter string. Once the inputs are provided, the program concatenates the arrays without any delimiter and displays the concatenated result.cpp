







#include <iostream>
#include <string>

template<typename T>
void concatenateArrays(T arr1[], T arr2[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr1[i] + arr2[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void concatenateStrings(T str1, T str2, T delimiter) {
    std::cout << "Concatenated string: " << str1 << delimiter << str2 << std::endl;
}

int main() {
    int a1, a2, a3, b1, b2, b3;
    std::string s1, s2, delimiter;

    std::cin >> a1 >> a2 >> a3;

    std::cin >> b1 >> b2 >> b3;

    std::cin >> s1;

    std::cin >> s2;

    std::cin >> delimiter;

    std::cout << "Concatenated array: ";
    concatenateArrays<int>(new int[3]{a1, a2, a3}, new int[3]{b1, b2, b3}, 3);

    concatenateStrings<std::string>(s1, s2, delimiter);

    // Don't forget to deallocate memory
    delete[] new int[3]{a1, a2, a3};
    delete[] new int[3]{b1, b2, b3};

    return 0;
}
