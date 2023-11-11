



#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class InvalidBookIDException {};
class BookNotAvailableException {};
class MaximumBooksReachedException {};

const int MAX_BOOKS = 20;

class Library {
private:
    unordered_map<string, bool> books; // Tracks book availability
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const string& bookID) {
        if (bookCount >= MAX_BOOKS) {
            throw MaximumBooksReachedException();
        }

        books[bookID] = true; // Book is available
        bookCount++;
        cout << "Book with ID " << bookID << " added to the library." << endl;
    }

    void borrowBook(const string& bookID) {
        if (books.find(bookID) == books.end()) {
            throw InvalidBookIDException();
        }

        if (!books[bookID]) {
            throw BookNotAvailableException();
        }

        books[bookID] = false; // Mark book as borrowed
        cout << "Book with ID " << bookID << " borrowed successfully." << endl;
    }

    void returnBook(const string& bookID) {
        if (books.find(bookID) == books.end()) {
            throw InvalidBookIDException();
        }

        books[bookID] = true; // Mark book as returned
        cout << "Book with ID " << bookID << " returned to the library." << endl;
    }
};

int main() {
    Library library;
    int numBooks;
    string bookID, borrowID, returnID;

    cin >> numBooks;
    try {
        for (int i = 0; i < numBooks; ++i) {
            cin >> bookID;
            library.addBook(bookID);
        }

        cin >> borrowID >> returnID;
        library.borrowBook(borrowID);
        library.returnBook(returnID);
    } catch (const InvalidBookIDException&) {
        cout << "Exception caught. Error: Invalid book ID." << endl;
    } catch (const BookNotAvailableException&) {
        cout << "Exception caught. Error: Book not available." << endl;
    } catch (const MaximumBooksReachedException&) {
        cout << "Exception caught. Error: Maximum number of books reached." << endl;
    }

    return 0;
}
