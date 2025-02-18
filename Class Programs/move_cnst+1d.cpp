#include <iostream>
using namespace std;

class MoveArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    MoveArray(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
        cout << "Constructor called\n";
    }

    // Copy Constructor (Deep Copy)
    MoveArray(const MoveArray &obj) {
        size = obj.size;
        arr = new int[size]; 
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }
        cout << "Copy Constructor called\n";
    }

    // Move Constructor
    MoveArray(MoveArray &&obj) noexcept {
        size = obj.size;
        arr = obj.arr; // Move ownership of the pointer
        obj.arr = nullptr; // Nullify the source object
        obj.size = 0;
        cout << "Move Constructor called\n";
    }

    // Display Function
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~MoveArray() {
        delete[] arr;
        cout << "Destructor called\n";
    }
};

int main() {
    MoveArray obj1(5); // Constructor is called
    obj1.display();

    MoveArray obj2 = move(obj1); // Move Constructor is called
    obj2.display();

    return 0;
}
