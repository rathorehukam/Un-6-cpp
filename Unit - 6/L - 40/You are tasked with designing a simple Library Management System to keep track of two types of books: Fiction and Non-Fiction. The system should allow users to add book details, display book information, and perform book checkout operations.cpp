





#include <iostream>
#include <string>
#include <vector>

// Base class template
template <typename T>
class Book {
public:
    std::string title;
    std::string author;
    bool available;

    Book() : title(""), author(""), available(false) {}

    Book(const std::string& title, const std::string& author, bool available)
        : title(title), author(author), available(available) {}

    virtual void displayDetails() const = 0;  // Making it a pure virtual function

    void checkout() {
        if (available) {
            std::cout << "Book \"" << title << "\" is available for checkout." << std::endl;
        } else {
            std::cout << "Book \"" << title << "\" is not available for checkout." << std::endl;
        }
    }
};

// Derived class for Fiction Books
class FictionBook : public Book<FictionBook> {
public:
    std::string genre;

    FictionBook(const std::string& title, const std::string& author, bool available, const std::string& genre)
        : Book(title, author, available), genre(genre) {}

    void displayDetails() const override {
        std::cout << "Fiction Book Details: \n";
        std::cout << title << " " << author << "  " << (available ? "Available" : "Not Available") << " " << genre << std::endl;
    }
};

// Derived class for Non-Fiction Books
class NonFictionBook : public Book<NonFictionBook> {
public:
    std::string subject;

    NonFictionBook(const std::string& title, const std::string& author, bool available, const std::string& subject)
        : Book(title, author, available), subject(subject) {}

    void displayDetails() const override {
        std::cout << "Non-Fiction Book Details: \n";
        std::cout << title << " " << author << "  " << (available ? "Available" : "Not Available") << " " << subject << std::endl;
    }
};

// Main function to handle dynamic input/output
int main() {
    std::vector<Book<FictionBook>*> fictionBooks;
    std::vector<Book<NonFictionBook>*> nonFictionBooks;

    std::string title, author, genre, subject;
    bool available;

    // Reading Fiction Book details
    std::cin >> title >> author >> available >> genre;
    fictionBooks.push_back(new FictionBook(title, author, available, genre));

    // Reading Non-Fiction Book details
    std::cin >> title >> author >> available >> subject;
    nonFictionBooks.push_back(new NonFictionBook(title, author, available, subject));

    // Displaying details
    for (const auto& book : fictionBooks) {
        book->displayDetails();
    }
    for (const auto& book : nonFictionBooks) {
        book->displayDetails();
    }

    // Checking out books
    std::cout << "Checking out books details: \n";
    for (const auto& book : fictionBooks) {
        book->checkout();
    }
    for (const auto& book : nonFictionBooks) {
        book->checkout();
    }

    // Clean up
    for (auto& book : fictionBooks) {
        delete book;
    }
    for (auto& book : nonFictionBooks) {
        delete book;
    }

    return 0;
}
