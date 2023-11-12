









// You are using GCC
#include <iostream>
#include <string>
#include <vector>

class FishItem {
public:
    std::string name;
    double price;
    int quantity;
    FishItem(const std::string& fishName, double fishPrice, int fishQuantity)
        : name(fishName), price(fishPrice), quantity(fishQuantity) {}
};

class FishMarket {
private:
    std::vector<FishItem> fishItems;
public:
    void addFish(const std::string& name, double price, int quantity) {
        fishItems.push_back(FishItem(name, price, quantity));
        std::cout << "Fish " << name << " added with price Rs." << price << " and quantity " << quantity << std::endl;
    }
    void updateFishPrice(const std::string& name, double newPrice) {
        for (FishItem& fish : fishItems) {
            if (fish.name == name) {
                fish.price = newPrice;
                std::cout << "Fish " << name << " price updated to Rs." << newPrice << std::endl;
                return;
            }
        }
        std::cout << "Fish " << name << " not found in the list. Cannot update price." << std::endl;
    }

    void sellFish(const std::string& name, int quantity) {
        for (FishItem& fish : fishItems) {
            if (fish.name == name) {
                if (fish.quantity >= quantity) {
                    fish.quantity -= quantity;
                    std::cout << quantity << " units of fish " << name << " sold." << std::endl;
                    return;
                } else {
                    std::cout << "Insufficient quantity of fish " << name << " in stock. Cannot sell." << std::endl;
                    return;
                }
            }
        }
        std::cout << "Fish " << name << " not found in the list. Cannot sell." << std::endl;
    }

    void displayFish() const {
        if (fishItems.empty()) {
            std::cout << "List is empty. No fish to display." << std::endl;
            return;
        }
        std::cout << "Available fish:" << std::endl;
        for (const FishItem& fish : fishItems) {
            std::cout << "- " << fish.name << " Rs." << fish.price << "; Quantity: " << fish.quantity << std::endl;
        }
    }
};

int main() {
    FishMarket fishMarket;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string name;
        double price;
        int quantity;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> price;
        std::cin >> quantity;
        fishMarket.addFish(name, price, quantity);
    }

    fishMarket.displayFish();
    std::string fishToUpdate;
    double newPrice;
    std::cin.ignore();
    std::getline(std::cin, fishToUpdate);
    std::cin >> newPrice;
    fishMarket.updateFishPrice(fishToUpdate, newPrice);
    std::string fishToSell;
    int quantityToSell;
    std::cin.ignore();
    std::getline(std::cin, fishToSell);
    std::cin >> quantityToSell;
    fishMarket.sellFish(fishToSell, quantityToSell);
    fishMarket.displayFish();
    return 0;
}
