













#include <iostream>
#include <string>
#include <unordered_map>

template <typename T>
void bookTestDrive(std::unordered_map<std::string, T>& testDriveSlots, const std::string& preferredDate) {
    if (testDriveSlots.find(preferredDate) != testDriveSlots.end() && testDriveSlots[preferredDate] == 1) {
        std::cout << "Test Drive Booked Successfully on " << preferredDate << std::endl;
    } else {
        std::cout << "Test Drive Slot not available on " << preferredDate << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> testDriveSlots;

    for (int i = 0; i < n; i++) {
        std::string date;
        int availability;
        std::cin >> date >> availability;
        testDriveSlots[date] = availability;
    }
    std::string preferredDate;
    std::cin >> preferredDate;

    bookTestDrive(testDriveSlots, preferredDate);

    return 0;
}
