








#include <iostream>
#include <list>
#include <algorithm>

std::list<int> getUniqueElements(const std::list<int>& songsList) {
    std::list<int> uniqueList;

    for (const auto& song : songsList) {
        if (std::find(uniqueList.begin(), uniqueList.end(), song) == uniqueList.end()) {
            uniqueList.push_back(song);
        }
    }

    uniqueList.sort();

    return uniqueList;
}

int main() {
    int N;
    std::cin >> N;

    std::list<int> songsList;
    for (int i = 0; i < N; ++i) {
        int songID;
        std::cin >> songID;
        songsList.push_back(songID);
    }

    std::list<int> result = getUniqueElements(songsList);

    for (const auto& song : result) {
        std::cout << song << " ";
    }

    return 0;
}
