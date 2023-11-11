




#include <iostream>

template <typename T>
bool checkWeather(T weather) {
    if (weather >= 0 && weather <= 69) {
        std::cout << "Weather conditions are favorable for the launch." << std::endl;
        return true;
    } else {
        std::cout << "Weather conditions are not suitable for the launch. Launch postponed." << std::endl;
        return false;
    }
}

template <typename T>
bool runPreLaunchTests() {
    std::cout << "Pre-launch tests are successful." << std::endl;
    return true;
}

template <typename T>
void fuelRocket() {
    std::cout << "Rocket has been fueled up." << std::endl;
}

template <typename T>
bool performFinalChecks() {
    std::cout << "Final checks are complete." << std::endl;
    return true;
}

template <typename T>
void launchSatellite() {
    std::cout << "Satellite launch successful!" << std::endl;
}

int main() {
    int weather;
    std::cin >> weather;

    if (checkWeather(weather)) {
        // If weather is favorable, proceed with the launch process
        runPreLaunchTests<int>();
        fuelRocket<int>();
        performFinalChecks<int>();
        launchSatellite<int>();
    }

    return 0;
}
