









#include <iostream>
template <typename T1, typename T2>
class PairBase {
protected:
    T1 first;
    T2 second;

public:
    PairBase(T1 f, T2 s) : first(f), second(s) {}

    void swap() {
        T1 temp = first;
        first = static_cast<T1>(second);
        second = static_cast<T2>(temp);
    }

    void display() {
        std::cout << "Values before swap:" << std::endl;
        std::cout << "First: " << first << std::endl;
        std::cout << "Second: " << second << std::endl;
    }
};

template <typename T1, typename T2>
class PairDerived : public PairBase<T1, T2> {
public:
    PairDerived(T1 f, T2 s) : PairBase<T1, T2>(f, s) {}

    void swap() {
        PairBase<T1, T2>::swap();
        std::cout << "Values after swap:" << std::endl;
        std::cout << "First: " << this->first << std::endl;
        std::cout << "Second: " << this->second << std::endl;
    }
};

int main() {
    float f;
    double d;
    std::cin >> f >> d;

    PairDerived<float, double> pair(f, d);

    pair.display();

    pair.swap();

    return 0;
}
