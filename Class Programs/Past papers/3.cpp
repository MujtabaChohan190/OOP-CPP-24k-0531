/*Q3: K-Electric, the primary electricity distribution company in Karachi, operates a fleet of vehicles to support various operations, including maintenance, emergency response, and meter inspections. To efficiently manage these vehicles, the company requires a Vehicle Management System that keeps track of each vehicle's details, such as brand, model, purchase cost, rental cost, and unique specifications.

Each vehicle type shares some common characteristics, but they also have distinct attributes. The company wants an efficient inheritance structure that prevents redundancy while ensuring proper functionality.

The Vehicle Management System follows a structured inheritance model. The base class Vehicle contains:

brand (string) for the manufacturer,
model (string) for the specific name, and
purchaseCost (float) representing the cost of the vehicle.
It has a constructor for initialization and a displayDetails() function to show vehicle information.
Two intermediate classes, Rentable and OperationalVehicle, extend from Vehicle:

Rentable introduces rentalCost (float) to specify the daily rental rate and provides a constructor along with calculateRentalCost() to return the rental cost.
OperationalVehicle adds operationalZone (string) to define the area where the vehicle operates, with a constructor and displayOperationalDetails() for zone information.
Three derived classes, MaintenanceTruck, EmergencyResponseVan, and MeterInspectionBike, extend from these intermediate classes:

MaintenanceTruck includes liftHeight (float) to specify the hydraulic lift height and loadCapacity (float) for the truck’s weight limit.
EmergencyResponseVan introduces emergencyEquipmentCount (int) to track available emergency tools and responseSpeed (float) for the vehicle’s speed.
MeterInspectionBike features fuelEfficiency (float) to measure fuel consumption per kilometer and storageCapacity (float) for onboard storage.*/

#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string brand;
    string model;
    float purchaseCost;

public:
    Vehicle(string b, string m, float p) : brand(b), model(m), purchaseCost(p) {}

    virtual void displayDetails() {
        cout << "Brand: " << brand << "\nModel: " << model << "\nPurchase Cost: $" << purchaseCost << endl;
    }
};

// Intermediate class: Rentable (inherits from Vehicle)
class Rentable : public Vehicle {
protected:
    float rentalCost;

public:
    Rentable(string b, string m, float p, float r) : Vehicle(b, m, p), rentalCost(r) {}

    float calculateRentalCost() {
        return rentalCost;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Rental Cost per day: $" << rentalCost << endl;
    }
};

// Intermediate class: OperationalVehicle (inherits from Vehicle)
class OperationalVehicle : public Vehicle {
protected:
    string operationalZone;

public:
    OperationalVehicle(string b, string m, float p, string zone) : Vehicle(b, m, p), operationalZone(zone) {}

    void displayOperationalDetails() {
        cout << "Operational Zone: " << operationalZone << endl;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        displayOperationalDetails();
    }
};

// Derived class: MaintenanceTruck (inherits from OperationalVehicle)
class MaintenanceTruck : public OperationalVehicle {
private:
    float liftHeight;
    float loadCapacity;

public:
    MaintenanceTruck(string b, string m, float p, string zone, float lh, float lc)
        : OperationalVehicle(b, m, p, zone), liftHeight(lh), loadCapacity(lc) {}

    void displayDetails() override {
        OperationalVehicle::displayDetails();
        cout << "Hydraulic Lift Height: " << liftHeight << " meters\n"
             << "Load Capacity: " << loadCapacity << " kg" << endl;
    }
};

// Derived class: EmergencyResponseVan (inherits from OperationalVehicle)
class EmergencyResponseVan : public OperationalVehicle {
private:
    int emergencyEquipmentCount;
    float responseSpeed;

public:
    EmergencyResponseVan(string b, string m, float p, string zone, int eqCount, float speed)
        : OperationalVehicle(b, m, p, zone), emergencyEquipmentCount(eqCount), responseSpeed(speed) {}

    void displayDetails() override {
        OperationalVehicle::displayDetails();
        cout << "Emergency Equipment Count: " << emergencyEquipmentCount << "\n"
             << "Response Speed: " << responseSpeed << " km/h" << endl;
    }
};

// Derived class: MeterInspectionBike (inherits from Rentable)
class MeterInspectionBike : public Rentable {
private:
    float fuelEfficiency;
    float storageCapacity;

public:
    MeterInspectionBike(string b, string m, float p, float r, float fe, float sc)
        : Rentable(b, m, p, r), fuelEfficiency(fe), storageCapacity(sc) {}

    void displayDetails() override {
        Rentable::displayDetails();
        cout << "Fuel Efficiency: " << fuelEfficiency << " km/l\n"
             << "Storage Capacity: " << storageCapacity << " liters" << endl;
    }
};

int main() {
    MaintenanceTruck truck("Ford", "F750", 50000, "City Zone", 5.5, 12000);
    EmergencyResponseVan van("Mercedes", "Sprinter", 60000, "Emergency Area", 10, 120);
    MeterInspectionBike bike("Honda", "CBR500", 7000, 50, 30, 20);

    cout << "\n=== Maintenance Truck ===" << endl;
    truck.displayDetails();

    cout << "\n=== Emergency Response Van ===" << endl;
    van.displayDetails();

    cout << "\n=== Meter Inspection Bike ===" << endl;
    bike.displayDetails();

    return 0;
}
