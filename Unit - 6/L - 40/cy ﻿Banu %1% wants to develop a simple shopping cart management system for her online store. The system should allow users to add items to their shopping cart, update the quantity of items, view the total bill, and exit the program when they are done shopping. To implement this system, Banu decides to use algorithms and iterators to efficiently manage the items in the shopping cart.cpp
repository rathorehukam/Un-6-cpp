#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath> // for modf function

class Item {
public:
    std::string name;
    int quantity;
    double price;
    Item(const std::string& itemName, int itemQuantity, double itemPrice)
        : name(itemName), quantity(itemQuantity), price(itemPrice) {}
};

// Function to find an item by name
auto findItem(std::vector<Item>& cart, const std::string& itemName) {
    return std::find_if(cart.begin(), cart.end(), [&itemName](const Item& item) {
        return item.name == itemName;
    });
}

int main() {
    std::vector<Item> cart;
    int choice;
    
    while (true) {
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string itemName;
                int itemQuantity;
                double itemPrice;
                std::cin >> itemName >> itemQuantity >> itemPrice;
                cart.push_back(Item(itemName, itemQuantity, itemPrice));
                break;
            }
            case 2: {
                std::string itemName;
                int newQuantity;
                std::cin >> itemName >> newQuantity;
                auto itemIter = findItem(cart, itemName);
                if (itemIter != cart.end()) {
                    itemIter->quantity = newQuantity;
                } else {
                    std::cout << "Item not found in cart" << std::endl;
                }
                break;
            }
            case 3: {
                double totalBill = 0.0;
                for (const Item& item : cart) {
                    totalBill += item.quantity * item.price;
                }
                // Check if the total bill has a fractional part
                double intPart;
                if (std::modf(totalBill, &intPart) == 0.0) {
                    std::cout << "Total Bill: " << static_cast<int>(intPart) << std::endl;
                } else {
                    std::cout << "Total Bill: " << std::fixed << std::setprecision(2) << totalBill << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Exiting the program." << std::endl;
                return 0; // Exit the program
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break; // Just indicate invalid choice, don't exit
            }
        }
    }
}
