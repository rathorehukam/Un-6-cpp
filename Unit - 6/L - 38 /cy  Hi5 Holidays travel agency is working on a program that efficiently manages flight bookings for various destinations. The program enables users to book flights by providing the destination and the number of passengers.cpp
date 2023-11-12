











// You are using GCC
#include <iostream>
#include <stdexcept>
#include <string>

const int MAX_STUDENTS = 20;

class InvalidGradeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid grade. Grade should be between A and E.";
    }
};

class StudentNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Student not found in the class roster.\n";
    }
};

class StudentGradeManagement {
private:
    struct Student {
        std::string name;
        std::string grade;
    };

    Student roster[MAX_STUDENTS];
    int numStudents;

public:
    StudentGradeManagement() : numStudents(0) {}

    void addStudent(const std::string& name) {
        if (numStudents >= MAX_STUDENTS) {
            std::cout << "Class roster is full. Cannot add more students.";
            return;
        }

        roster[numStudents].name = name;
        roster[numStudents].grade = "N/A";
        numStudents++;

        std::cout << "Student " << name << " added to the class roster.\n";
    }

    void updateGrade(const std::string& name, const std::string& letterGrade) {
        int studentIndex = -1;
        for (int i = 0; i < numStudents; i++) {
            if (roster[i].name == name) {
                studentIndex = i;
                break;
            }
        }

        if (studentIndex == -1) {
            throw StudentNotFoundException();
        }

        if (letterGrade != "A" && letterGrade != "B" && letterGrade != "C" && letterGrade != "D" && letterGrade != "E") {
            throw InvalidGradeException();
        }

        roster[studentIndex].grade = letterGrade;
        std::cout << "Grade for student " << name << " updated to " << letterGrade << ".\n";
    }
};

int main() {
    StudentGradeManagement gradeManager;
    int numStudents;
    std::string name, letterGrade;

    std::cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        std::cin >> name;
        gradeManager.addStudent(name);
    }

    if (numStudents >= MAX_STUDENTS) {
        return 0;
    }

    std::cin >> name >> letterGrade;

    try {
        gradeManager.updateGrade(name, letterGrade);
    } 
    catch (const InvalidGradeException& e) {
        std::cout << "Exception caught. " << e.what();
    } 
    catch (const StudentNotFoundException& e) {
        std::cout << "Exception caught. " << e.what();
    }

    return 0;
}
