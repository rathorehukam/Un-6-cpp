





#include <iostream>
#include <cmath> 
using namespace std;

class NegativeExponentException : public exception {
public:
    const char * what () const throw () {
        return "Negative exponents are not supported.";
    }
};

double power(double base, int exponent) {
    if (exponent < 0) {
        throw NegativeExponentException();
    }
    return pow(base, exponent);
}

int main() {
    double base;
    int exponent;
    cin >> base;
    cin >> exponent;

    try {
        double result = power(base, exponent);
        cout << result;
    } catch (NegativeExponentException& e) {
        cout << "Exception caught. Error: " << e.what();
    }

    return 0;
}
