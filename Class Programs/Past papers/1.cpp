/*Question:
A well-known Pakistani car dealership is developing an automated inventory management system to keep track of the cars available for sale.

You need to design a C++ class named Car that meets the following requirements:

1. Data Members
A data member to store the Car ID, which should be set at creation and must never change.
A string data member to store the model name.
A double data member to store the price of the car in Rs.
A pointer (char*) for dynamically storing the manufacturer’s name.
A counter that keeps track of the total number of cars in the inventory.
2. Member Functions
Constructor:
Accepts car details as parameters and initializes all data members.
Copy Constructor:
Implements a copy mechanism to create a new Car object as a copy of an existing one.
Ensures that the manufacturer details are copied separately, so that changes to one object do not affect another.
3. Additional Functionalities
Accessor Functions:
Functions to retrieve the Car ID, Model Name, Price, and Manufacturer Details.
These functions should not modify any data members.
Inventory Count Function:
A function to return the total number of cars in inventory.
4. Main Function Requirements
Create an array of 2 Car objects with different car models available in Pakistan (e.g., Suzuki Alto, Honda City).
Display the total number of cars in inventory.
Prompt the user to enter a Car ID and search for the car in inventory.
If a car with the given ID exists, display its Model Name, Price, and Manufacturer.
If no car is found, display "Car not found."
Demonstrate the copy constructor by creating a copy of one of the cars and displaying its details.*/


#include <iostream>
#include <cstring> // For strcpy and strlen
using namespace std;

class Car {
private:
    const int carID;       // Car ID (constant, cannot be changed)
    string modelName;      // Model Name
    double price;          // Price in Rs.
    char* manufacturer;    // Dynamically allocated manufacturer name
    static int inventoryCount; // Counter for total cars

public:
    // Constructor
    Car(int id, string model, double carPrice, const char* maker)
        : carID(id), modelName(model), price(carPrice) {
        manufacturer = new char[strlen(maker) + 1];
        strcpy(manufacturer, maker);
        inventoryCount++;
    }

    // Copy Constructor (Deep Copy)
    Car(const Car& other) : carID(other.carID), modelName(other.modelName), price(other.price) {
        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);
        inventoryCount++;
    }

    // Destructor
    ~Car() {
        delete[] manufacturer;
        inventoryCount--;
    }

    // Accessor Functions
    int getCarID() const { return carID; }
    string getModelName() const { return modelName; }
    double getPrice() const { return price; }
    const char* getManufacturer() const { return manufacturer; }

    // Static function to get inventory count
    static int getInventoryCount() { return inventoryCount; }
    
    // Display Car Details
    void display() const {
        cout << "Model: " << modelName << endl;
        cout << "Price: Rs. " << price << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

// Initialize static variable
int Car::inventoryCount = 0;

int main() {
    // Create an array of 2 car objects
    Car car1(101, "Suzuki Alto", 2500, "Suzuki");
    Car car2(102, "Honda City", 4589, "Honda");

    cout << "Total cars in inventory: " << Car::getInventoryCount() << endl;

    // Copy constructor demonstration
    Car copiedCar = car2;
    cout << "\nCopied Car Details:\n";
    copiedCar.display();

    // Search for a car by ID
    int searchID;
    cout << "\nEnter a Car ID to search: ";
    cin >> searchID;

    if (searchID == car1.getCarID()) {
        cout << "\nCar found:\n";
        car1.display();
    } else if (searchID == car2.getCarID()) {
        cout << "\nCar found:\n";
        car2.display();
    } else {
        cout << "\nCar not found." << endl;
    }

    return 0;
}
