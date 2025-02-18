#include <iostream>
using namespace std;

class Example {
private:
    int* data;

public:
    // Constructor
    Example(int value) {
        data = new int(value);  // Allocate memory and set value
        cout << "Constructor called\n";
    }

    // Move Constructor (called during object creation from rvalue)
    Example(Example&& obj) {
        cout << "Move Constructor Called\n";
        data = obj.data;  // Steal data from temporary object
        obj.data = nullptr;  // Nullify the source object's pointer
    }

    // Move Assignment Operator (called during assignment from rvalue)
    Example& operator=(Example&& obj) {
        cout << "Move Assignment Operator Called\n";
        if (this != &obj) {  // Check for self-assignment
            delete data;  // Free current object's data
            data = obj.data;  // Steal data
            obj.data = nullptr;  // Nullify the temporary object
        }
        return *this;
    }

    void display() {
        cout << "Data: " << (data ? *data : 0) << endl;
    }

    // Destructor
    ~Example() {
        if (data) {
            delete data;  // Free memory
            cout << "Destructor called\n";
        }
    }
};

int main() {
    // Move Constructor: obj1 is created from a temporary object
    Example obj1 = Example(10);  // Move Constructor Called

    // Move Assignment Operator: obj2 is assigned a temporary object
    Example obj2(20);  // Constructor Called
    obj2 = Example(30);  // Move Assignment Operator Called

    obj1.display();  // Data: 10
    obj2.display();  // Data: 30

    return 0;
}
