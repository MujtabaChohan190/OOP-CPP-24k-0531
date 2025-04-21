#include <iostream>
#include <string>

using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(string flightNumber, string departure, string arrival, int capacity)
        : flightNumber(flightNumber), departure(departure), arrival(arrival), capacity(capacity), bookedSeats(0) {}

    bool bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    bool cancelSeat() {
        if (bookedSeats > 0) {
            bookedSeats--;
            return true;
        }
        return false;
    }

    bool upgradeSeat() {
        if (bookedSeats > 0) {
            return true;
        }
        return false;
    }

    int getAvailableSeats() const {
        return capacity - bookedSeats;
    }

    void displayFlightDetails() const {
        cout << "Flight: " << flightNumber << ", Departure: " << departure
             << ", Arrival: " << arrival << ", Capacity: " << capacity
             << ", Booked: " << bookedSeats << ", Available: " << getAvailableSeats() << "\n";
    }

    string getFlightNumber() const {
        return flightNumber;
    }
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string id, string name) : id(id), name(name) {}

    bool requestBooking(Flight& flight) {
        if (flight.bookSeat()) {
            cout << name << " successfully booked a seat on flight " << flight.getFlightNumber() << ".\n";
            return true;
        }
        cout << "No available seats on flight " << flight.getFlightNumber() << ".\n";
        return false;
    }

    bool cancelBooking(Flight& flight) {
        if (flight.cancelSeat()) {
            cout << name << " successfully canceled the seat on flight " << flight.getFlightNumber() << ".\n";
            return true;
        }
        cout << "No booking found to cancel on flight " << flight.getFlightNumber() << ".\n";
        return false;
    }

    bool upgradeBooking(Flight& flight) {
        if (flight.upgradeSeat()) {
            cout << name << " successfully upgraded their seat on flight " << flight.getFlightNumber() << ".\n";
            return true;
        }
        cout << "No booking found to upgrade on flight " << flight.getFlightNumber() << ".\n";
        return false;
    }
};

int main() {
    Flight flight1("AA123", "New York", "London", 5);
    Flight flight2("BB456", "Los Angeles", "Tokyo", 3);

    Passenger passenger1("P001", "Alice");
    Passenger passenger2("P002", "Bob");

    flight1.displayFlightDetails();
    flight2.displayFlightDetails();

    passenger1.requestBooking(flight1);
    passenger2.requestBooking(flight1);
    passenger1.requestBooking(flight2);
    passenger2.requestBooking(flight2);
    passenger1.requestBooking(flight1);

    passenger1.requestBooking(flight1);

    flight1.displayFlightDetails();
    flight2.displayFlightDetails();

    passenger1.cancelBooking(flight1);
    passenger2.upgradeBooking(flight2);

    flight1.displayFlightDetails();
    flight2.displayFlightDetails();

    return 0;
}
