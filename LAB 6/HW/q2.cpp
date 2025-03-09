#include <iostream>
using namespace std;


class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}
    virtual void display() const = 0; // Pure virtual function
    virtual ~Vehicles() {}
};


class Car : public Vehicles {
protected:
    int seatingCapacity, numDoors;
    string fuelType;
public:
    Car(double p, int seatCap, int doors, string fuel) 
        : Vehicles(p), seatingCapacity(seatCap), numDoors(doors), fuelType(fuel) {}
};


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
        cout << "=== Audi Car Details ===\n";
        cout << "Price: $" << price << "\nSeating Capacity: " << seatingCapacity 
             << "\nNumber of Doors: " << numDoors << "\nFuel Type: " << fuelType 
             << "\nModel Type: " << modelType << "\n\n";
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
        cout << "=== Yamaha Motorcycle Details ===\n";
        cout << "Price: $" << price << "\nCylinders: " << numCylinders 
             << "\nGears: " << numGears << "\nWheels: " << numWheels 
             << "\nMake Type: " << makeType << "\n\n";
    }
};

int main() {
    
    Vehicles* myCar = new Audi(50000, 5, 4, "Petrol", "A6"); //A new object is created and its address is stored in  my car 
    Vehicles* myBike = new Yamaha(15000, 2, 6, 2, "YZF-R6");


    myCar->display();  
    myBike->display();

    // Cleanup
    delete myCar;
    delete myBike;

    return 0;
}

