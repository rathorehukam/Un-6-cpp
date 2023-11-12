









// You are using GCC
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MedicalCollege {
public:
    MedicalCollege(const string& name, int year, T totalSeats)
        : name(name), year(year), totalSeats(totalSeats), availableSeats(totalSeats) {}

    void displayDetails() const {
        cout << name <<" "<< year << " " << totalSeats << " " << availableSeats << endl;
    }

    void admitStudents(T numStudents) {
        if (numStudents <= availableSeats) {
            availableSeats -= numStudents;
            cout << numStudents << " students admitted to " << name << "\nAvailable Seats: " << availableSeats;
        } else {
            cout << "Not enough seats available in " << name << "\nCannot admit " << numStudents << " students.";
        }
    }

    T getTotalSeats() const { 
        return totalSeats;
    }

private:
    string name;
    int year;
    T totalSeats;
    T availableSeats;
};

template <typename T>
class MBBSMedicalCollege : public MedicalCollege<T> {
public:
    MBBSMedicalCollege(const string& name, int year, T totalSeats, T totalMBBSSeats)
        : MedicalCollege<T>(name, year, totalSeats), totalMBBSSeats(totalMBBSSeats) {}

    void displayDetails() const {
        MedicalCollege<T>::displayDetails();
    }

private:
    T totalMBBSSeats;
};

int main() {
    string college1Name, college2Name, college3Name;
    int college1Year, college2Year, college3Year;
    int college1TotalSeats, college2TotalSeats, college3TotalSeats;
    int college1TotalMBBSSeats, college2TotalMBBSSeats, college3TotalMBBSSeats;
    getline(cin, college1Name);
    cin >> college1Year;
    cin >> college1TotalSeats;
    cin >> college1TotalMBBSSeats;
    cin.ignore();
    getline(cin, college2Name);
    cin >> college2Year;
    cin >> college2TotalSeats;
    cin >> college2TotalMBBSSeats;
    cin.ignore();
    getline(cin, college3Name);
    cin >> college3Year;
    cin >> college3TotalSeats;
    cin >> college3TotalMBBSSeats;
    MBBSMedicalCollege<int> college1(college1Name, college1Year, college1TotalSeats, college1TotalMBBSSeats);
    MBBSMedicalCollege<int> college2(college2Name, college2Year, college2TotalSeats, college2TotalMBBSSeats);
    MBBSMedicalCollege<int> college3(college3Name, college3Year, college3TotalSeats, college3TotalMBBSSeats);
    while (true) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Medical College Details:" << endl;
            college1.displayDetails();
            college2.displayDetails();
            college3.displayDetails();
            return 0;
        } else if (choice == 2) {
            int numStudents;
            cin >> numStudents;
            college1.admitStudents(numStudents);
            return 0;
        } else if (choice == 3) {
            cout << "Exiting the program";
            return 0;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

