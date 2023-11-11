










#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
template <typename T>
double calculateDistance(T x1, T y1, T x2, T y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
template <typename T>
double calculateDistance(T x1, T y1, T z1, T x2, T y2, T z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
    int choice;
    cin >> choice;

    if (choice == 2) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double distance = calculateDistance(x1, y1, x2, y2);
        cout << fixed << setprecision(2) << "Distance between the points in two-dimensional space: " << distance << endl;
    } else if (choice == 3) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        double distance = calculateDistance(x1, y1, z1, x2, y2, z2);
        cout << fixed << setprecision(2) << "Distance between the points in three-dimensional space: " << distance << endl;
    } else {
        cout << "Invalid choice. Please enter 2 or 3." << endl;
    }

    return 0;
}
