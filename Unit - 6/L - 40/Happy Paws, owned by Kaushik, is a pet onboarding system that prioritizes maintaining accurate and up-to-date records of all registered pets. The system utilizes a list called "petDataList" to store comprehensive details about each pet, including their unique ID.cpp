









#include <iostream>
#include <list>

void removeElement(std::list<int>& petDataList, int target) {
    petDataList.remove(target);
}

int main() {
    int N;
    std::cin >> N;

    std::list<int> petDataList;
    for (int i = 0; i < N; ++i) {
        int petID;
        std::cin >> petID;
        petDataList.push_back(petID);
    }

    int M;
    std::cin >> M;

    // Call the removeElement function to remove occurrences of the specified pet ID
    removeElement(petDataList, M);

    // Print the updated petDataList
    for (const auto& petID : petDataList) {
        std::cout << petID << " ";
    }

    return 0;
}
