

















#include <iostream>
#include <vector>
#include <stdexcept>

// Maximum stock that can be handled
const int MAX_STOCK = 100;

// Custom exceptions
class InvalidIDException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid eyeglass ID.";
    }
};

class OutOfStockException : public std::exception {
public:
    const char* what() const throw() {
        return "Eyeglass out of stock.";
    }
};

// Function to add eyeglasses to the showroom
void addEyeglasses(std::vector<int>& showroom, int id) {
    if (showroom.size() >= MAX_STOCK) {
        throw OutOfStockException();
    }
    showroom.push_back(id);
    std::cout << "Eyeglass with ID " << id << " added to the showroom.\n";
}

// Function to sell eyeglasses
void sellEyeglass(std::vector<int>& showroom, int customerID) {
    for (int id : showroom) {
        if (id == customerID) {
            std::cout << "Eyeglass with ID " << customerID << " sold.\n";
            return;
        }
    }
    throw InvalidIDException();
}

int main() {
    int n, customerID;
    std::cin >> n;

    std::vector<int> showroom;
    
    try {
        for (int i = 0; i < n; ++i) {
            int id;
            std::cin >> id;
            addEyeglasses(showroom, id);
        }
    } catch (const OutOfStockException& e) {
        std::cout << "Exception caught. Error: " << e.what() << std::endl;
        return 1; // Exit with error code
    }

    std::cin >> customerID;

    try {
        sellEyeglass(showroom, customerID);
    } catch (const InvalidIDException& e) {
        std::cout << "Exception caught. Error: " << e.what() << std::endl;
    } catch (const OutOfStockException& e) {
        std::cout << "Exception caught. Error: " << e.what() << std::endl;
    }

    return 0;
}
