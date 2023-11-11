












#include <iostream>
#include <vector>

std::vector<int> removeElement(const std::vector<int>& patients, int target) {
    std::vector<int> result;

    for (int patient : patients) {
        if (patient != target) {
            result.push_back(patient);
        }
    }

    return result;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> patients(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> patients[i];
    }

    int M;
    std::cin >> M;

    std::vector<int> updatedPatients = removeElement(patients, M);

    for (int patient : updatedPatients) {
        std::cout << patient << " ";
    }

    return 0;
}
