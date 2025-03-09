#include <iostream>
using namespace std;

// Base Class: Vehicles
class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}
    virtual void display() const = 0; // Pure virtual function
    virtual ~Vehicles() {}
};

// Derived Class: Car
class Car : public Vehicles {
protected:
    int seatingCapacity, numDoors;
    string fuelType;
public:
    Car(double p, int seatCap, int doors, string fuel) 
        : Vehicles(p), seatingCapacity(seatCap), numDoors(doors), fuelType(fuel) {}
};

// Derived Class: Motorcycle
class Motorcycle : public Vehicles {
protected:
    int numCylinders, numGears, numWheels;
public:
    Motorcycle(double p, int cyl, int gears, int wheels) 
        : Vehicles(p), numCylinders(cyl), numGears(gears), numWheels(wheels) {}
};

// Subclass of Car: Audi
class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int seatCap, int doors, string fuel, string model) 
        : Car(p, seatCap, doors, fuel), modelType(model) {}

    void display() const override {
        cout << "Audi Car Details:\n";
        cout << "Price: $" << price << "\nSeating Capacity: " << seatingCapacity 
             << "\nNumber of Doors: " << numDoors << "\nFuel Type: " << fuelType 
             << "\nModel Type: " << modelType << endl;
    }
};

// Subclass of Motorcycle: Yamaha
class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int cyl, int gears, int wheels, string make) 
        : Motorcycle(p, cyl, gears, wheels), makeType(make) {}

    void display() const override {
        cout << "Yamaha Motorcycle Details:\n";
        cout << "Price: $" << price << "\nCylinders: " << numCylinders 
             << "\nGears: " << numGears << "\nWheels: " << numWheels 
             << "\nMake Type: " << makeType << endl;
    }
};


int main() {
    // Creating an Audi object dynamically
    Vehicles* myCar = new Audi(50000, 5, 4, "Petrol", "A6");

    // Display details
    myCar->display();  

    // Cleanup
    delete myCar;

    return 0;
}
