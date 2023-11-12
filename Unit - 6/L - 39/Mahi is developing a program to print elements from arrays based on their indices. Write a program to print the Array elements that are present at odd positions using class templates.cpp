












#include <iostream>
#include <vector>

using namespace std;

template <class T>
class OddPositionElements {
private:
    vector<T> array;

public:
    void readArray(int n) {
        array.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
    }

    void printOddPositionElements() {
        for (int i = 0; i < array.size(); i += 2) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// Specialization for string type
template <>
class OddPositionElements<string> {
private:
    vector<string> array;

public:
    void readArray(int n) {
        array.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
    }

    void printOddPositionElements() {
        for (int i = 0; i < array.size(); i += 2) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    OddPositionElements<int> intArray;
    intArray.readArray(n);
    intArray.printOddPositionElements();

    OddPositionElements<string> stringArray;
    stringArray.readArray(n);
    stringArray.printOddPositionElements();

    return 0;
}
