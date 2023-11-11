








#include <iostream>
#include <list>
#include <unordered_set>

int main() {
    int numElements;
    std::cin >> numElements;

    if (numElements > 15) {
        std::cout << -1;
        return 0;
    }

    std::list<int> startingBids;
    std::unordered_set<int> uniqueBids;

    for (int i = 0; i < numElements; ++i) {
        int bid;
        std::cin >> bid;
        startingBids.push_back(bid);
        uniqueBids.insert(bid);
    }

    int sum = 0;
    for (int uniqueBid : uniqueBids) {
        sum += uniqueBid;
    }

    std::cout << "Sum of unique elements: " << sum;

    return 0;
}
