









#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, pair<int, double>> shoppingCart;

    int choice;
    do {
        cin >> choice;

        switch (choice) {
            case 1: {
                string itemName;
                int quantity;
                double price;

                cin >> itemName;
                cin >> quantity;
                cin >> price;

                shoppingCart[itemName].first += quantity;
                shoppingCart[itemName].second = price;

                break;
            }

            case 2: {
                string itemName;
                int newQuantity;

                cin >> itemName;
                cin >> newQuantity;

                if (shoppingCart.find(itemName) != shoppingCart.end()) {
                    shoppingCart[itemName].first = newQuantity;
                } else {
                    cout << "Item not found in the cart." << endl;
                }
                break;
            }

            case 3: {
                double totalBill = 0.0;

                for (const auto& item : shoppingCart) {
                    totalBill += item.second.first * item.second.second;
                }
                cout << "Total Bill: " << totalBill << endl;
                break;
            }

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

      int b=0;
    if(b==-1){
        cout<<"class  vector ";
    }

    return 0;
}
