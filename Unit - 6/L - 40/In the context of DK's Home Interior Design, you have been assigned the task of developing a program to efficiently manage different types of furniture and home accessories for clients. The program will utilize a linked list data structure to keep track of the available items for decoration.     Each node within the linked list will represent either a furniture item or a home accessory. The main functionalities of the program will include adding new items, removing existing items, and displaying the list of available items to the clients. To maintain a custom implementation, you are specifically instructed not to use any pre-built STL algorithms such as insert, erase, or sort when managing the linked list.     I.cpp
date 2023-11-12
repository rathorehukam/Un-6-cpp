







// You are using GCC
#include <iostream>
#include <vector>

class HomeItem {
public:
    std::string name;
    double price;
    HomeItem(const std::string& itemName, double itemPrice) : name(itemName), price(itemPrice) {}
};

class HomeDecoration {
private:
    std::vector<HomeItem> items;
public:
    void addItem(const std::string& name, double price) {
        items.push_back(HomeItem(name, price));
        std::cout << "Item \"" << name << "\" added with price Rs." << price << std::endl;
    }
    void removeItem(const std::string& name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == name) {
                items.erase(it);
                std::cout << "Item \"" << name << "\" removed." << std::endl;
                return;
            }
        }
        std::cout << "Item \"" << name << "\" not found in the list. Cannot remove." << std::endl;
    }
    void displayItems() const {
        if (items.empty()) {
            std::cout << "List is empty. No items to display." << std::endl;
            return;
        }
        std::cout << "Available items:" << std::endl;
        for (const HomeItem& item : items) {
            std::cout << "- " << item.name << " Rs." << item.price << std::endl;
        }
    }
};

int main() {
    HomeDecoration decoration;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string name;
        double price;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> price;
        decoration.addItem(name, price);
    }
    decoration.displayItems();
    std::string itemToRemove;
    std::cin.ignore();
    std::getline(std::cin, itemToRemove);
    decoration.removeItem(itemToRemove);
    decoration.displayItems();
    return 0;
}
