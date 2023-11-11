











#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_BOOKS = 20;

class InvalidBookIDException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid book ID.";
    }
};

class BookNotAvailableException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Book not available.";
    }
};

class Library {
private:
    std::vector<std::string> books;

public:
    void addBook(const std::string& bookID) {
        if (books.size() >= MAX_BOOKS) {
            throw BookNotAvailableException();
        }
        books.push_back(bookID);
        std::cout << "Book with ID " << bookID << " added to the library." << std::endl;
    }

    void borrowBook(const std::string& bookID) {
        auto it = std::find(books.begin(), books.end(), bookID);
        if (it == books.end()) {
            throw InvalidBookIDException();
        }
        books.erase(it);
        std::cout << "Book with ID " << bookID << " borrowed successfully." << std::endl;
    }

    void returnBook(const std::string& bookID) {
        books.push_back(bookID);
        std::cout << "Book with ID " << bookID << " returned to the library." << std::endl;
    }
};

int main() {
    int numBooks;
    std::cin >> numBooks;

    Library library;

    for (int i = 0; i < numBooks; i++) {
        std::string bookID;
        std::cin >> bookID;
        library.addBook(bookID);
    }

    std::string borrowID, returnID;
    std::cin >> borrowID >> returnID;

    try {
        library.borrowBook(borrowID);
        library.returnBook(returnID);
    } catch (const InvalidBookIDException& e) {
        std::cout << "Exception caught. Error: " << e.what() << std::endl;
    } catch (const BookNotAvailableException& e) {
        std::cout << "Exception caught. Error: " << e.what() << std::endl;
    }

    return 0;
}
