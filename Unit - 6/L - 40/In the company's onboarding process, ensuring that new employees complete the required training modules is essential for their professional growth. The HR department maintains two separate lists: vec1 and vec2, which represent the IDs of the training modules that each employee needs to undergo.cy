










#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> mergeAndSortVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    // Merge both vectors
    std::vector<int> mergedVec;
    mergedVec.reserve(vec1.size() + vec2.size());
    mergedVec.insert(mergedVec.end(), vec1.begin(), vec1.end());
    mergedVec.insert(mergedVec.end(), vec2.begin(), vec2.end());

    // Sort the merged vector
    std::sort(mergedVec.begin(), mergedVec.end());

    return mergedVec;
}

int main() {
    // Input vectors
    int M, N;
    std::cin >> M;
    std::vector<int> vec1(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> vec1[i];
    }

    std::cin >> N;
    std::vector<int> vec2(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec2[i];
    }

    // Call the function to merge and sort vectors
    std::vector<int> result = mergeAndSortVectors(vec1, vec2);

    // Output the merged and sorted vector
    for (int i : result) {
        std::cout << i << " ";
    }

    return 0;
}
