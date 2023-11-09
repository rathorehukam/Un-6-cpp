












#include <iostream>

class NegativeDepositException : public std::exception {
public:
    const char* what() const noexcept {
        return "Error: Cannot deposit a negative amount or zero.";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial_balance) : balance(initial_balance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            throw NegativeDepositException();
        }
        balance += amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    double depositAmount;
    std::cin >> depositAmount;

    try {
        BankAccount account(0);
        account.deposit(depositAmount);
        std::cout << "Deposit successful. Balance: " << account.getBalance() << std::endl;
    } catch (const NegativeDepositException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
