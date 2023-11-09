










#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

template <typename T>
void addOrUpdate(std::unordered_map<std::string, T>& inventory, 
                 std::vector<std::string>& order,
                 const std::string& name, 
                 T quantity, 
                 bool update = false) {
    if (update) {
        if (inventory.find(name) != inventory.end()) {
            inventory[name] = quantity;
            std::cout << "Updated " << name << " quantity to " << quantity << " units in the inventory." << std::endl;
        } else {
            std::cout << "Material " << name << " not found in the inventory." << std::endl;
        }
    } else {
        if (inventory.find(name) == inventory.end()) {
            order.push_back(name);  
        }
        inventory[name] = quantity;
        std::cout << "Added " << quantity << " units of " << name << " to the inventory." << std::endl;
    }
}

template <typename T>
void displayInventory(const std::unordered_map<std::string, T>& inventory, 
                      const std::vector<std::string>& order) {
    std::cout << "Current Inventory Status:" << std::endl;
    for (const auto& name : order) {
        std::cout << name << ": " << inventory.at(name) << " units" << std::endl;
    }
}

int main() {
    std::unordered_map<std::string, int> inventory;
    std::vector<std::string> order;  
    int n;
    std::string name;
    int quantity;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> name >> quantity;
        addOrUpdate(inventory, order, name, quantity);
    }

    std::cin >> name >> quantity;
    addOrUpdate(inventory, order, name, quantity, true);

    displayInventory(inventory, order);

    return 0;
}
