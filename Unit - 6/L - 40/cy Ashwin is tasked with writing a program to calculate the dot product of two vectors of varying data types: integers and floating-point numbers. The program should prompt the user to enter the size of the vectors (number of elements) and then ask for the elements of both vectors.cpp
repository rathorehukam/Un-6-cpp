






#include <iostream>
#include <vector>
using namespace std;

template<class T>
T dotProduct(const vector<T>& v1, const vector<T>& v2) {
    T result = 0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> intVec1(n), intVec2(n);
    vector<float> floatVec1(n), floatVec2(n);

    for (int i = 0; i < n; ++i) {
        cin >> intVec1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> intVec2[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> floatVec1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> floatVec2[i];
    }

    cout << "Dot product of integer vectors: " << dotProduct(intVec1, intVec2) << endl;
    cout << "Dot product of floating-point vectors: " << dotProduct(floatVec1, floatVec2) << endl;

    return 0;
}
