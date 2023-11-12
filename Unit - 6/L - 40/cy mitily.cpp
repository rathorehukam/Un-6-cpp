








// You are using GCC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

struct Milk {
    std::string brand;
    int quantityInLiters;
    double pricePerLiter;
};

class MilkInventory {
private:
    std::vector<Milk> milks;
public:
    void addMilk(const std::string& brand, int quantityInLiters, double pricePerLiter) {
        milks.push_back({brand, quantityInLiters, pricePerLiter});
    }
    void updateQuantity(const std::string& brand, int newQuantity) {
        auto it = std::find_if(milks.begin(), milks.end(), [brand](const Milk& m) {
            return m.brand == brand;
        });
        if (it != milks.end()) {
            it->quantityInLiters = newQuantity;
        }
    }

    void displayMilkInventory() {
        std::cout << "Milk Inventory Details:" << std::endl;
        for (const Milk& m : milks) {
            std::cout << "Brand: " << m.brand << ", Quantity (Liters): " << m.quantityInLiters
                      << ", Price per Liter: $" << m.pricePerLiter << std::endl;
        }
    }
};

int main() {
    MilkInventory milkInventory;
    std::string brand;
    int quantity;
    double price;
    char choice;
    do {
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cin.ignore();
                std::getline(std::cin, brand);
                std::cin >> quantity;
                std::cin >> price;
                milkInventory.addMilk(brand, quantity, price);
                break;

            case '2':
                std::cin.ignore();
                std::getline(std::cin, brand);
                std::cin >> quantity;
                milkInventory.updateQuantity(brand, quantity);
                break;

            case '3':
                milkInventory.displayMilkInventory();
                break;

            case '4':
                std::cout << "Exiting the program.";
                break;

            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != '4');
    return 0;
}
