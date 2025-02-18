#include <iostream>
using namespace std;

class Array1D {
private:
    int *arr;
    int size;

public:
    // Constructor for dynamic allocation
    Array1D(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1; // Initializing with values 1, 2, 3, ...
        }
    }

    // Copy Constructor
    Array1D(const Array1D &obj) {
        size = obj.size;
        arr = new int[size]; // Allocate new memory for copy
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i]; // Copy values
        }
    }

    // Display Function
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Array1D() {
        delete[] arr;
    }
};

int main() {
    Array1D obj1(5);  // Creating first object
    cout << "Original Array: ";
    obj1.display();

    Array1D obj2 = obj1;  // Calling copy constructor
    cout << "Copied Array: ";
    obj2.display();

    return 0;
}
