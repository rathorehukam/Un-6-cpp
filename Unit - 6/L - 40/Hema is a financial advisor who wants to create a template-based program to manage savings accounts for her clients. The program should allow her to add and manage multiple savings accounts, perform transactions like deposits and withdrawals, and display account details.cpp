







#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SavingsAccount {
private:
    string accountNumber;
    string accountHolder;
    T balance;
    T interestRate;

public:
    SavingsAccount(const string &accNumber, const string &accHolder, T initialBalance, T intRate)
        : accountNumber(accNumber), accountHolder(accHolder), balance(initialBalance), interestRate(intRate) {}

    void deposit(T amount) {
        balance += amount;
    }

    bool withdraw(T amount) {
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    void display() const {
        cout << "Savings Account Details: " << endl;
        cout << accountNumber << " " << accountHolder << " " << balance << endl;
        cout << interestRate << "%" << endl;
    }

    T getBalance() const {
        return balance;
    }
};

int main() {
    string accountNumber, accountHolder;
    double initialBalance, interestRate;
    double depositAmount, withdrawAmount;

    // Input for Savings Account
    getline(cin, accountNumber);
    getline(cin, accountHolder);
    cin >> initialBalance;
    cin >> interestRate;

    SavingsAccount<double> account(accountNumber, accountHolder, initialBalance, interestRate);
    account.display();

    // Input for Transactions
    cin >> depositAmount;
    account.deposit(depositAmount);
    cout << account.getBalance() << endl;

    cin >> withdrawAmount;
    if (!account.withdraw(withdrawAmount)) {
        cout << "Insufficient balance" << endl;
    } else {
        cout << account.getBalance() << endl;
    }

    return 0;
}
