




#include <iostream>
#include <vector>
using namespace std;

class NegativeNumberException {
public:
    int index;
    NegativeNumberException(int idx) : index(idx) {}
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int sum = 0;
    try {
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                throw NegativeNumberException(i);
            }
            sum += arr[i];
        }
        cout << "The sum is : " << sum;
    } catch (NegativeNumberException& e) {
        cout << "Negative number found at index " << e.index << endl;
        cout << "The sum is : " << sum;
    }

    return 0;
}
