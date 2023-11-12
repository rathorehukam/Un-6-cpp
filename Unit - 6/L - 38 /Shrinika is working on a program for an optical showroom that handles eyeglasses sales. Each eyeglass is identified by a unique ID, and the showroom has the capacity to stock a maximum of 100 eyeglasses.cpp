













// You are using GCC
#include <iostream>
#include <stdexcept>

class InvalidIDException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid eyeglass ID.";
    }
};

class OutOfStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Eyeglass out of stock.";
    }
};

class OpticalShowroom {
private:
    static const int MAX_STOCK = 100;
    int eyeglassIDs[MAX_STOCK];
    int stockSize;

public:
    OpticalShowroom() : stockSize(0) {}

    void addEyeglass(int id) {
        if (id <= 0) {
            throw InvalidIDException();
        }

        if (stockSize >= MAX_STOCK) {
            throw OutOfStockException();
        }

        eyeglassIDs[stockSize] = id;
        stockSize++;
        std::cout << "Eyeglass with ID " << id << " added to the showroom.\n";
    }

    void sellEyeglass(int id) {
        int foundIndex = -1;
        for (int i = 0; i < stockSize; i++) {
            if (eyeglassIDs[i] == id) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) {
            throw InvalidIDException();
        }

        for (int i = foundIndex; i < stockSize - 1; i++) {
            eyeglassIDs[i] = eyeglassIDs[i + 1];
        }

        stockSize--;
        std::cout << "Eyeglass with ID " << id << " sold.\n";
    }
};

int main() {
    try {
        OpticalShowroom showroom;
        int idInput;
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> idInput;
            showroom.addEyeglass(idInput);
        }

        int customerID;
        std::cin >> customerID;
        showroom.sellEyeglass(customerID);
    } 
    catch (const InvalidIDException& e) {
        std::cout << "Exception caught. " << e.what();
    } 
    catch (const OutOfStockException& e) {
        std::cout << "Exception caught. " << e.what();
    }

    return 0;
}
