











#include <iostream>
#include <stdexcept>
using namespace std;

void processWithdrawal(double balance, double withdrawalAmount) {
    if (withdrawalAmount > balance) {
        throw underflow_error("Insufficient money for withdrawal.");
    }
    balance -= withdrawalAmount;
    cout << "Withdrawal successful." << endl;
    cout << "New balance: " << balance << endl;
}

int main() {
    double balance, withdrawalAmount;

    cin >> balance >> withdrawalAmount;

    try {
        processWithdrawal(balance, withdrawalAmount);
    } catch (const underflow_error& e) {
        cout << "Exception caught." << endl;
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
