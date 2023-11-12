




#include <iostream>
#include <vector>
#include <algorithm>

class Product {
public:
    std::string name;
    int quantity;
    double price;

    Product(const std::string& n, int q, double p) : name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    std::vector<Product> products;

public:
    void addProduct(const std::string& name, int quantity, double price) {
        if (products.size() < 100) {
            products.emplace_back(name, quantity, price);
        }
    }

    void updateQuantity(const std::string& name, int newQuantity) {
        auto it = std::find_if(products.begin(), products.end(),
                               [&name](const Product& product) { return product.name == name; });

        if (it == products.end()) {
            std::cout << "Product not found in inventory." << std::endl;
        } else {
            it->quantity = newQuantity;
        }
    }

    void displayInventory() {
        std::cout << "Inventory Details:" << std::endl;
        for (const auto& product : products) {
            std::cout << "Name: " << product.name << ", Quantity: " << product.quantity << ", Price: $" << product.price << std::endl;
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    while (true) {
        std::cin >> choice;
        if (choice == 4) {
            break;
        }

        switch (choice) {
            case 1: {
                std::string name;
                int quantity;
                double price;
                std::cin >> name >> quantity >> price;
                inventory.addProduct(name, quantity, price);
                break;
            }
            case 2: {
                std::string name;
                int quantity;
                std::cin >> name >> quantity;
                inventory.updateQuantity(name, quantity);
                break;
            }
            case 3: {
                inventory.displayInventory();
                break;
            }
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}
