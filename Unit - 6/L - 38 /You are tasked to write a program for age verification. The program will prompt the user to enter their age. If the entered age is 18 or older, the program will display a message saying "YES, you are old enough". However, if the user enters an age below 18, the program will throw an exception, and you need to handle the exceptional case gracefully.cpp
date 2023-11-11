












#include <iostream>

int main() {
    try {
        int age;
      //  std::cout << "Enter your age: ";
        std::cin >> age;

        if (age >= 18) {
            std::cout << "YES, you are old enough." << std::endl;
        } else {
            throw age;
        }
    } catch (int age) {
        std::cout << "No, You must be at least 18 years old" << std::endl;
        std::cout << "Current Age is : " << age << std::endl;
    }

    return 0;
}
