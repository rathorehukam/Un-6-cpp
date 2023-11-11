







#include<iostream>

template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b) {}

    void swap() {
        T1 temp = first;
        first = second;
        second = temp;
    }

    void displayBeforeSwap() const {
        std::cout << "Values before swap:\nFirst: " << first << "\nSecond: " << second << "\n";
    }

    void displayAfterSwap() const {
        std::cout << "Values after swap:\nFirst: " << first << "\nSecond: " << second << "\n";
    }
};

int main() {
    float floatValue;
    double doubleValue;

    std::cin >> floatValue;
    std::cin >> doubleValue;

    Pair<float, double> myPair(floatValue, doubleValue);

    myPair.displayBeforeSwap();

    myPair.swap();

    myPair.displayAfterSwap();

    return 0;
}
