


#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    double initial_balance, withdrawal_amount;
    cin >> initial_balance >> withdrawal_amount;

    try {
        if (withdrawal_amount > initial_balance) {
            throw underflow_error("Insufficient money for withdrawal.");
        }
        else {
            cout << "Withdrawal successful." << endl;
            cout << "New balance: " << initial_balance - withdrawal_amount << endl;
        }
    }
    catch (const underflow_error& e) {
        cout << "Exception caught." << endl;
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

