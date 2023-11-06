









template <class T>
class BankAccount {
private:
    T balance;
    T interestRate;

public:
    BankAccount() : balance(0), interestRate(0) {}

    void setBalance(T b) {
        balance = b;
    }

    void setInterestRate(T r) {
        interestRate = r;
    }

    T getBalance() {
        return balance;
    }

    T getInterestRate() {
        return interestRate;
    }

    T calculateInterest() {
        return (balance * interestRate) / 100;
    }
};

#include <iostream>
using namespace std;

int main() {
    BankAccount<int> savingsAccount;
    int initialBalance, interestRate;

    cin >> initialBalance;
    cin >> interestRate;

    savingsAccount.setBalance(initialBalance);
    savingsAccount.setInterestRate(interestRate);

    int balanceAfterOneYear = savingsAccount.getBalance() + savingsAccount.calculateInterest();
    int interestEarned = savingsAccount.calculateInterest();

    cout << "Balance after one year: " << balanceAfterOneYear << endl;
    cout << "Interest earned after one year: " << interestEarned << endl;

    return 0;
}
