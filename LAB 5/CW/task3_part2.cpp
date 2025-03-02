/*Potential pitfalls if the cars go out of scope while the Garage still holds pointers.
(Demonstrate this ability)*/

/* ANSWER:Since Garage only stores raw pointers (Car*), it does not manage the lifetime of Car objects.
If a Car object goes out of scope, Garage still holds a dangling pointer to it.
Accessing this dangling pointer results in undefined behavior, which may cause crashes or garbage output.*/

//CODE:

#include <iostream>
#include <vector>

using namespace std;

class Car {
private:
    string name;
    int id;

public:
    Car(string carName, int carID) : name(carName), id(carID) {}

    void display() const {
        cout << "Car ID: " << id << ", Name: " << name << endl;
    }

    int getID() const { return id; }
    string getName() const { return name; }
};

class Garage {
private:
    vector<Car*> cars; 

public:
    void parkCar(Car* car) {
        if (car) {
            cars.push_back(car);
            cout << "Car parked: " << car->getName() << " (ID: " << car->getID() << ")\n";
        }
    }

    void listCars() const {
        cout << "\nListing cars in the garage:\n";
        for (const auto& car : cars) {
            if (car) {
                car->display();
            } else {
                cout << "invalid car reference!\n";
            }
        }
    }
};

int main() {
    cout << "Creating Cars on the stack...\n";
    Car car1("Toyota", 101);
    Car car2("Ford", 102);

    cout << "Creating Garage...\n";
    Garage myGarage;

    cout << "Parking cars in Garage...\n";
    myGarage.parkCar(&car1);
    myGarage.parkCar(&car2);

    cout << "\nListing cars inside Garage before any go out of scope:\n";
    myGarage.listCars(); //  No issue here

    cout << "\nDemonstrating a issue...\n";
    {
        Car tempCar("TemporaryCar", 999); // Created in a local scope
        myGarage.parkCar(&tempCar);
        cout << "Temporary car parked inside Garage.\n";
    } //  tempCar goes out of scope and is destroyed here

    cout << "\nListing cars again after tempCar is out of scope:\n";
    myGarage.listCars(); // Undefined behavior (tempCar is destroyed).Since myGarage still holds a pointer to tempCar, this pointer now points to invalid memory, leading to undefined behavior.

    cout << "\nEnd of main, stack-allocated cars will now be destroyed.\n";
    return 0;
}
