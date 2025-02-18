#include <iostream>
using namespace std;

class Example {
private:
    int* data;  // Pointer to an integer

public:
    // Constructor
    Example(int value) {
        data = new int(value);  // Allocate memory and set value
        cout << "Constructor called\n";
    }

    // Move Assignment Operator
    Example& operator=(Example&& obj) {
        cout << "Move Assignment Operator Called\n";
        if (this != &obj) {  // Check for self-assignment
            delete data;  // Free current object's data
            data = obj.data;  // Steal data
            obj.data = nullptr;  // Nullify the temporary object
        }
        return *this;  // Return current object (for chaining)
    }

    void display() {
        cout << "Data: " << (data ? *data : 0) << endl;  // Safely display data
    }

    // Destructor
    ~Example() {
        if (data) {
            delete data;  // Free memory if data exists
            cout << "Destructor called\n";
        }
    }
};

int main() {
    Example obj1(10);   // obj1 owns data
    Example obj2(20);   // obj2 owns data

    obj2 = std::move(obj1);  // Move data from obj1 to obj2

    obj1.display();  // Output: Data: 0 (obj1 no longer owns data)
    obj2.display();  // Output: Data: 10 (obj2 now owns data)

    return 0;
}
