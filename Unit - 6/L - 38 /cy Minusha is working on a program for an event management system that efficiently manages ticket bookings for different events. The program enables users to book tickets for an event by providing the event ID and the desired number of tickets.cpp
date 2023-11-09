







#include <iostream>
#include <vector>
#include <string>

const int MAX_EVENTS = 20;

class InvalidEventIDException : public std::exception {
public:
    const char* what() const throw() {
        return "Exception caught: Error: Invalid event ID.";
    }
};

class InsufficientSeatsException : public std::exception {
public:
    const char* what() const throw() {
        return "Exception caught: Error: Insufficient seats available for booking.";
    }
};

class EventManagementSystem {
public:
    EventManagementSystem() : events(MAX_EVENTS), numEvents(0) {}

    void addEvent(const std::string& eventID, int totalSeats) {
        if (numEvents >= MAX_EVENTS) {
            std::cout << "Exception caught: Error: Maximum number of events reached." << std::endl;
            return;
        }

        events[numEvents] = {eventID, totalSeats};
        std::cout << "Event with ID " << eventID << " added with " << totalSeats << " seats." << std::endl;
        numEvents++;
    }

    void bookTickets(const std::string& eventID, int numTickets) {
        bool eventFound = false;
        int remainingSeats = 0;

        for (int i = 0; i < numEvents; i++) {
            if (events[i].eventID == eventID) {
                eventFound = true;
                if (events[i].totalSeats >= numTickets) {
                    events[i].totalSeats -= numTickets;
                    remainingSeats = events[i].totalSeats;
                } else {
                    throw InsufficientSeatsException();
                }
            }
        }

        if (!eventFound) {
            throw InvalidEventIDException();
        }

        std::cout << numTickets << " tickets booked for event with ID " << eventID << ". Remaining seats: " << remainingSeats << std::endl;
    }

private:
    struct Event {
        std::string eventID;
        int totalSeats;
    };

    std::vector<Event> events;
    int numEvents;
};

int main() {
    int n;
    std::cin >> n;

    EventManagementSystem system;

    for (int i = 0; i < n; i++) {
        std::string eventID;
        int totalSeats;
        std::cin >> eventID >> totalSeats;
        system.addEvent(eventID, totalSeats);
    }

    std::string eventID;
    int numTickets;
    std::cin >> eventID >> numTickets;

    try {
        system.bookTickets(eventID, numTickets);
    } catch (const InvalidEventIDException& e) {
        std::cout << e.what() << std::endl;
    } catch (const InsufficientSeatsException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
