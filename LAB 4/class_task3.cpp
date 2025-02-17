/*Task - 03: Implement a DynamicArray Class with the “Rule of Five”
1. Overview:
Create a class called DynamicArray that manages a dynamic array of integers.
o The class should allocate and deallocate its own memory.
o It must correctly handle copy and move operations.
2. Details:
o Provide these constructors and operators:
1. Default constructor: Initializes an empty array or an array of size zero.
2. Parameterized constructor: Accept an integer n that indicates the array size, allocate an
array of that size, and default-initialize all elements to 0.
3. Copy constructor: Performs a deep copy of the array.
4. Move constructor: Efficiently transfers ownership of the dynamic array from an rvalue
object (leaving the source in a valid but empty state).
5. Copy assignment operator (operator=): Deep copies the array from one object to another,
properly handling self-assignment.
6. Move assignment operator (operator=): Transfers ownership from an rvalue object,
deallocating any previously held memory.
7. Destructor: Deallocates the dynamic array.
o Provide additional member functions:
 size(): returns the current size of the array.
 at(int index): returns a reference to the element at index (and possibly a const version for
read-only).
 resize(int newSize): resizes the dynamic array to a new size, copying old data if newSize &gt;
0.*/

#include<iostream>
using namespace std;

class DynamicArray {
    int *data;
    int capacity;

public:
    DynamicArray() : data(nullptr), capacity(0) {}

    DynamicArray(int size) : capacity(size), data(new int[size]{0}) {}

    DynamicArray(const DynamicArray &other) : capacity(other.capacity), data(new int[other.capacity]) {
        cout << "Copy Constructor Called" << endl;
        for (int i = 0; i < capacity; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray &&other) noexcept : capacity(other.capacity), data(other.data) {
        cout << "Move Constructor Called" << endl;
        other.data = nullptr;
        other.capacity = 0;
    }

    DynamicArray &operator=(const DynamicArray &other) {
        cout << "Copy Assignment Operator Called" << endl;
        if (this == &other) return *this;
        delete[] data;

        capacity = other.capacity;
        data = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    DynamicArray &operator=(DynamicArray &&other) noexcept {
        cout << "Move Assignment Operator Called" << endl;
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        capacity = other.capacity;

        other.data = nullptr;
        other.capacity = 0;

        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    int size() const {
        return capacity;
    }

    int &at(int index) {
        if (index < 0 || index >= capacity) {
            cout << "Index out of bounds" << endl;
        }
        return data[index];
    }

    void resize(int newSize) {
        while (true) {
            if (newSize <= 0) {
                cout << "Not a valid size" << endl;
                cout << "Enter the size again" << endl;
                cin >> newSize;
                continue;
            }
            if (newSize > 0) {
                int *newData = new int[newSize]();
                for (int i = 0; i < min(capacity, newSize); i++) {
                    newData[i] = data[i];
                }
                capacity = newSize;
                delete[] data;
                data = newData;
            }
            break;
        }
    }

    void print() const {
        for (int i = 0; i < capacity; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr(5);
    cout << "Initial array: ";
    arr.print();

    arr.at(2) = 10;
    cout << "After modification: ";
    arr.print();

    arr.resize(-1);
    cout << "After resizing to 8: ";
    arr.print();

    arr.resize(3);
    cout << "After resizing to 3: ";
    arr.print();

    return 0;
}
