









#include <iostream>
#include <unordered_set>

class DuplicateIDException : public std::exception {
public:
    const char* what() const throw() {
        return "Exception caught. Error: Student ID already exists.";
    }
};

class FullDatabaseException : public std::exception {
public:
    const char* what() const throw() {
        return "Exception caught. Error: Student database is full.";
    }
};

class StudentDatabase {
private:
    std::unordered_set<int> studentIDs;
    const int MAX_CAPACITY = 30;

public:
    void addStudent(int id, const std::string& name) {
        if (studentIDs.size() >= MAX_CAPACITY) {
            throw FullDatabaseException();
        }

        auto result = studentIDs.insert(id);
        if (!result.second) {
            throw DuplicateIDException();
        }

        std::cout << "Student with ID " << id << " added to the database." << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    StudentDatabase database;

    for (int i = 0; i < n; ++i) {
        int id;
        std::string name;
        std::cin >> id >> name;

        try {
            database.addStudent(id, name);
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
