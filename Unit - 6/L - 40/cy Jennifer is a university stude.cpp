







// You are using GCC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <limits>    

struct Student {
    std::string name;
    int rollNumber;
    int grades[3];
};

class StudentDatabase {
private:
    std::vector<Student> students;
public:
    void addStudent(const std::string& name, int rollNumber) {
        students.push_back({name, rollNumber, {0, 0, 0}}); 
    }
    void updateGrades(int rollNumber, const int newGrades[3]) {
        auto it = std::find_if(students.begin(), students.end(), [rollNumber](const Student& s) {
            return s.rollNumber == rollNumber;
        });
        if (it != students.end()) {
            std::copy(newGrades, newGrades + 3, it->grades);
        }
    }

    void displayStudentDetails(int rollNumber) {
        auto it = std::find_if(students.begin(), students.end(), [rollNumber](const Student& s) {
            return s.rollNumber == rollNumber;
        });
        if (it != students.end()) {
            std::cout << "Name: " << it->name << std::endl;
            std::cout << "Roll Number: " << it->rollNumber << std::endl;
            std::cout << "Grades: ";
            for (int i = 0; i < 3; ++i) {
                std::cout << it->grades[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Student with Roll Number " << rollNumber << " not found." << std::endl;
        }
    }
};

int main() {
    StudentDatabase db;
    std::string name;
    int rollNumber;
    int grades[3]; 
    char choice;
    do {
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cin.ignore();
                std::getline(std::cin, name);

                std::cin >> rollNumber;

                db.addStudent(name, rollNumber);
                break;

            case '2':
                std::cin >> rollNumber;
                for (int i = 0; i < 3; ++i) {
                    std::cin >> grades[i];
                }
                db.updateGrades(rollNumber, grades);
                break;

            case '3':
                std::cin >> rollNumber;
                db.displayStudentDetails(rollNumber);
                break;

            case '4':
                std::cout << "Exiting the program.";
                break;

            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != '4');
    return 0;
}

