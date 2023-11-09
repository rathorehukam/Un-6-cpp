












#include <iostream>
#include <string>
#include <map>

class InvalidFlightNumberException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid flight number.";
    }
};

class NoAvailableSeatsException : public std::exception {
public:
    const char* what() const throw() {
        return "No available seats on the selected flight.";
    }
};

class FlightReservationSystem {
private:
    std::map<std::string, int> flights;

public:
    void addFlight(const std::string& flightNumber, int totalSeats) {
        if (flights.size() == 1) {
            throw std::runtime_error("Flight reservation system is full.");
        }
        flights[flightNumber] = totalSeats;
        std::cout << "Flight " << flightNumber << " added with " << totalSeats << " seats." << std::endl;
    }

    void bookSeats(const std::string& selectedFlight, int numSeats) {
        auto flightIt = flights.find(selectedFlight);
        if (flightIt == flights.end()) {
            throw InvalidFlightNumberException();
        }

        if (flightIt->second < numSeats) {
            throw NoAvailableSeatsException();
        }

        flightIt->second -= numSeats;
        std::cout << numSeats << " seats booked for flight " << selectedFlight << ". Remaining seats: " << flightIt->second << std::endl;
    }
};

int main() {
    FlightReservationSystem system;
    int n;
    std::cin >> n;
    try {
        for (int i = 0; i < n; ++i) {
            std::string flightNumber;
            int totalSeats;
            std::cin >> flightNumber >> totalSeats;
            system.addFlight(flightNumber, totalSeats);
        }

        std::string selectedFlight;
        int numSeats;
        std::cin >> selectedFlight >> numSeats;
        system.bookSeats(selectedFlight, numSeats);
    }
    catch (const InvalidFlightNumberException& e) {
        std::cout << "Exception caught: Error: " << e.what() << std::endl;
    }
    catch (const NoAvailableSeatsException& e) {
        std::cout << "Exception caught: Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: Error: " << e.what() << std::endl;
    }

    return 0;
}
