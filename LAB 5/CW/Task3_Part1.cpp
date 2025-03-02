/*Garage and Cars (Aggregation with Raw Pointers)
Description
Implement a Garage class that stores pointers to one or more Car objects. This setup is
aggregation:
 The Garage does not own the lifetime of the cars.
 Cars can exist independently of the Garage.

Requirements

1. Car
o Can reuse the Car class from the previous example, or create a simplified
version (just a name and an ID).

2. Garage
o Has a std::vector&lt;Car*&gt; cars; (raw pointers) or a
std::vector&lt;std::reference_wrapper&lt;Car&gt;&gt; to store references to external cars.
o A parkCar(Car* car) method that adds a Car pointer to its collection.
o A listCars() method that prints the IDs/names of all parked cars.
3. In main() (or a test function):
o Create several Car objects on the stack.
o Create one Garage object.
o Call garage.parkCar(&amp;car1) etc.
o Observe that when main() ends, the cars (stack objects) are destroyed first or
last? (Note that if the Garage tries to delete these pointers, it leads to undefined
behavior.)*/


#include <iostream>
#include <vector>

using namespace std;

class Car {
private:
    string name;
    int id;

public:
    Car(string name, int id) : name(name), id(id) {}

    string getName() const { return name; }
    int getID() const { return id; }

    void display() const {
        cout << "Car Name: " << name << ", ID: " << id << endl;
    }

    ~Car() {
        cout << "Car " << name << " (ID: " << id << ") destroyed.\n"; //Destructor added to confirm the destruction order of stack-allocated Cars.
    }
};

//Aggregation:It Stores pointers to Car objects, but does not own them
class Garage {
private:
    vector<Car*> cars; 

public:
    void parkCar(Car* car) {
        if (car) { //Checks if that car has null pointer
            cars.push_back(car);
            cout << "Car parked: " << car->getName() << " (ID: " << car->getID() << ")\n";
        } else {
            cout << "null car\n";
        }
    }

    void listCars() const {
        cout << "Cars in the garage:\n";
        for (size_t i = 0; i < cars.size(); i++) { // Normal for loop (no auto)
            if (cars[i]) {
                cars[i]->display();
            } else {
                cout << "Warning: Null car detected!\n";
            }
        }
    }

    ~Garage() {
        cout << "Garage object destroyed.\n"; //The Garage only stores raw pointers to Cars but does not own them, so it does not delete cars.
    }
};

int main() {
    cout << "Creating cars on the stack.\n";
    Car car1("Toyota", 101);
    Car car2("Honda", 202);
    Car car3("Ford", 303);

    cout << "\nCreating a garage...\n";
    Garage garage;

    cout << "\nParking cars in the garage...\n";
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    cout << "\nListing parked cars...\n";
    garage.listCars();

    return 0; // Stack objects (cars) will be destroyed first, then garage
}


/*Observe that when main() ends, the cars (stack objects) are destroyed first or
last? (Note that if the Garage tries to delete these pointers, it leads to undefined
behavior.)*/

/*Ans:  Cars (stack objects) are destroyed first, before the Garage.Cars are stack-allocated, meaning they are destroyed automatically when main() ends.
The Garage only stores raw pointers to Cars but does not own them, so it does not delete them.
When main() ends:
Cars go out of scope first → Their destructors run.
Garage goes out of scope last → Its destructor runs, but it does not delete the car pointers.*/

