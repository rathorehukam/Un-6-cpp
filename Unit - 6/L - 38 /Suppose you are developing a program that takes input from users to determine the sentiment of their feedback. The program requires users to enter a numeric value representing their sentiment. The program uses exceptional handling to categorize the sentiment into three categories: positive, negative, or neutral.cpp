







#include <iostream>
using namespace std;

class ZeroException {};
class NegativeException {};

int main() {
    int number;
    cin >> number;
    try {
        if (number > 0) {
            cout << "You Entered Positive number";
        } else if (number < 0) {
            throw NegativeException();
        } else {
            throw ZeroException();
        }
    } catch (NegativeException&) {
        cout << "You Entered Negative number";
    } catch (ZeroException&) {
        cout << "You Entered Zero";
    }

    return 0;
}
