







// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

// Base class template
template <class T>
class QueueBase {
protected:
    vector<T> q;

public:
    void enqueue(T x) {
        q.push_back(x);
    }

    void dequeue() {
        if (q.empty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        q.erase(q.begin());
    }

    void display() {
        cout << "Queue elements: ";
        for (int i = 0; i < q.size(); i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

// Derived class template
template <class T>
class QueueDerived : public QueueBase<T> {
public:
    using QueueBase<T>::QueueBase;
};

int main() {
    QueueDerived<int> q1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q1.enqueue(x);
    }

    QueueDerived<double> q2;

    cin >> n;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        q2.enqueue(x);
    }

    q1.display();
    cout << "Dequeueing an element from the integer queue" << endl;
    q1.dequeue();
    q1.display();

    q2.display();
    cout << "Dequeueing an element from the double queue" << endl;
    q2.dequeue();
    q2.display();

    return 0;
}
