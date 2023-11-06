







#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_ARRAY_SIZE = 1000;

int main() {
    int arraySize;
    cin >> arraySize;

    try {
        if (arraySize <= 0) {
            throw invalid_argument("Error: Array size must be a positive integer.");
        }
        if (arraySize > MAX_ARRAY_SIZE) {
            throw length_error("Error: Array size exceeds the maximum limit.");
        }

        int* myArray = new int[arraySize];  
        cout << "Array allocated successfully.";

        delete[] myArray;  

    } catch (const invalid_argument& e) {
        cout << "Invalid argument caught." << endl;
        cout << e.what();
    } catch (const length_error& e) {
        cout << "Length error caught." << endl;
        cout << e.what();
    } catch (const exception& e) {
        cout << "Exception caught." << endl;
        cout << e.what();
    }

    return 0;
}
