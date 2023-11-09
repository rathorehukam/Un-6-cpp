









#include <iostream>
#include <exception>

class ArrayInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exception caught. Array size should be a positive number.";
    }
};

class ArrayEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exception caught. Array is empty.";
    }
};

int main() {
    int n;
    std::cin >> n;

    try {
        if (n <= 0) {
            throw ArrayInputException();
        }

        int* arr = new int[n];

        if (n > 0) {
            for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
            }
        } else {
            delete[] arr; 
            throw ArrayEmptyException();
        }

        for (int i = 0; i < n; i++) {
            std::cout << arr[i];
            if (i < n - 1) {
                std::cout << " ";
            }
        }

        delete[] arr;
    } catch (const ArrayInputException& e) {
        std::cout << e.what() << std::endl;
    } catch (const ArrayEmptyException& e) {
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught. " << e.what() << std::endl;
    }

    return 0;
}
