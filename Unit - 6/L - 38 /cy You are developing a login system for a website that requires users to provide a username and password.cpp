








#include <iostream>
#include <string>
#include <exception>

class InvalidPasswordException : public std::exception {
private:
    std::string message;
public:
    InvalidPasswordException(const std::string& msg) : message(msg) {}
    const char* what() const throw() {
        return message.c_str();
    }
};

bool containsDigit(const std::string& str) {
    for (char ch : str) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string username, password;
    
    std::getline(std::cin, username);
    std::getline(std::cin, password);

    try {
        if (password.length() < 6) {
            throw InvalidPasswordException("Password must be at least 6 characters long");
        }

        if (!containsDigit(password)) {
            throw InvalidPasswordException("Password must have at least one digit");
        }

        std::cout << "Password is Correct\n";
    }
    catch (const InvalidPasswordException& e) {
        std::cout << e.what() << "\nCaught by Exception\nInvalid Password Format!\n";
    }

    return 0;
}
