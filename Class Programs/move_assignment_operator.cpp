#include <iostream>
using namespace std;

class Example {
private:
    int data;  // Simple integer data

public:
    // Constructor
    Example(int value) : data(value) {
        cout << "Constructor called with value: " << value << endl;
    }

    // Move Assignment Operator
    Example& operator=(Example&& obj) {
        cout << "Move Assignment Operator Called\n";
        if (this != &obj) {  // Check for self-assignment
            data = obj.data;  // Move data from the temporary object
            obj.data = 0;     // Nullify the temporary object's data
        }
        return *this;  // Return the current object to allow chaining
    }

    void display() {
        cout << "Data: " << data << endl;
    }

    // Destructor
    ~Example() {
        cout << "Destructor called\n";
    }
};

int main() {
    // Create an object with a value (oldObject)
    Example oldObject(10);  // Constructor Called with value 10
    oldObject.display();    // Data: 10

    // Move the value from oldObject to a new object using move assignment
    Example newObject(20);  // Constructor Called with value 20
    newObject = std::move(oldObject);  // Move Assignment Operator Called

    newObject.display();    // Data: 10 (moved from oldObject)
    oldObject.display();    // Data: 0 (oldObject's data is nullified)

    return 0;
}
