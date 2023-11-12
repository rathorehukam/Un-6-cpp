









#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

// Custom exceptions for the class roster system
class InvalidGradeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid grade. Grade should be between A and E.";
    }
};

class StudentNotFoundException : public exception {
public:
    const char* what() const noexcept override {
        return "Student not found in the class roster.";
    }
};

// Class roster management
class ClassRoster {
private:
    vector<pair<string, char>> students; // Pair of student name and grade
    const int MAX_STUDENTS = 20;

public:
    void addStudent(const string& studentName) {
        if (students.size() >= MAX_STUDENTS) {
            throw runtime_error("Class roster is full. Cannot add more students.");
        }
        students.emplace_back(studentName, ' '); // Initial grade is blank
        cout << "Student " << studentName << " added to the class roster." << endl;
    }

    void updateGrade(const string& studentName, char grade) {
        if (grade < 'A' || grade > 'E') {
            throw InvalidGradeException();
        }

        for (auto& student : students) {
            if (student.first == studentName) {
                student.second = grade;
                cout << "Grade for student " << studentName << " updated to " << grade << "." << endl;
                return;
            }
        }

        throw StudentNotFoundException();
    }
};

int main() {
    ClassRoster classRoster;
    int numStudents;
    cin >> numStudents;

    string studentName;
    for (int i = 0; i < numStudents; ++i) {
        cin >> studentName;
        try {
            classRoster.addStudent(studentName);
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    string nameToUpdate;
    char gradeToUpdate;
    cin >> nameToUpdate >> gradeToUpdate;

    try {
        classRoster.updateGrade(nameToUpdate, gradeToUpdate);
    } catch (const InvalidGradeException& e) {
        cout << "Exception caught. Error: " << e.what() << endl;
    } catch (const StudentNotFoundException& e) {
        cout << "Exception caught. Error: " << e.what() << endl;
    }

    return 0;
}
