











#include <iostream>
#include <queue>

template <typename T>
class Queue {
private:
    std::queue<T> q;

public:
    void enqueue(T element) {
        q.push(element);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    void display() {
        std::queue<T> tempQueue = q;
        while (!tempQueue.empty()) {
            std::cout << tempQueue.front();
            tempQueue.pop();
            if (!tempQueue.empty()) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> integerQueue;
    Queue<double> doubleQueue;
    int n, m;
    int intElement;
    double doubleElement;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> intElement;
        integerQueue.enqueue(intElement);
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> doubleElement;
        doubleQueue.enqueue(doubleElement);
    }

    std::cout << "Queue elements: ";
    integerQueue.display();

    std::cout << "Dequeueing an element from the integer queue" << std::endl;
    integerQueue.dequeue();
    std::cout << "Queue elements: ";
    integerQueue.display();

    std::cout << "Queue elements: ";
    doubleQueue.display();

    std::cout << "Dequeueing an element from the double queue" << std::endl;
    doubleQueue.dequeue();
    std::cout << "Queue elements: ";
    doubleQueue.display();

    return 0;
}
