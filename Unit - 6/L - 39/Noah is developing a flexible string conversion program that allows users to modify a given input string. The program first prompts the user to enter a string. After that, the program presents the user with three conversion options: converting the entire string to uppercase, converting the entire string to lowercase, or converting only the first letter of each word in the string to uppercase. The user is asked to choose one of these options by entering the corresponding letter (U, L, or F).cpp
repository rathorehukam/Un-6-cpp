















#include <iostream>
#include <sstream>

using namespace std;

// Function to convert the entire string to uppercase
template <typename T>
T convertStringToUpper(const T &str) {
    T result = str;
    for (char &c : result) {
        c = toupper(c);
    }
    return result;
}

// Function to convert the entire string to lowercase
template <typename T>
T convertStringToLower(const T &str) {
    T result = str;
    for (char &c : result) {
        c = tolower(c);
    }
    return result;
}

// Function to convert the first letter of each word to uppercase
template <typename T>
T convertFirstLetterToUpper(const T &str) {
    T result = str;
    bool newWord = true;
    for (char &c : result) {
        if (newWord && isalpha(c)) {
            c = toupper(c);
            newWord = false;
        } else if (isspace(c)) {
            newWord = true;
        }
    }
    return result;
}

// Main function to handle user input and display output
int main() {
    string inputString;
    char choice;

    // Read input string
    getline(cin, inputString);

    // Read choice
    cin >> choice;

    switch (choice) {
        case 'U':
            cout << "Uppercase string: " << convertStringToUpper(inputString) << endl;
            break;
        case 'L':
            cout << "Lowercase string: " << convertStringToLower(inputString) << endl;
            break;
        case 'F':
            cout << "String with first letter of each word capitalized: " << convertFirstLetterToUpper(inputString) << endl;
            break;
        default:
            cout << "Invalid choice. Please enter U, L, or F." << endl;
    }

    return 0;
}
