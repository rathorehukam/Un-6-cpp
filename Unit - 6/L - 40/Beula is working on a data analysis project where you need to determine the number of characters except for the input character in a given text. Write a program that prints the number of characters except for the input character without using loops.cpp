









#include <iostream>
#include <algorithm>

int main() {
    std::string text;
    char ch;

    std::getline(std::cin, text);
    std::cin >> ch;

    int count = std::count_if(text.begin(), text.end(), [ch](char c) { return c != ch; });

    std::cout << count << std::endl;

    return 0;
}
