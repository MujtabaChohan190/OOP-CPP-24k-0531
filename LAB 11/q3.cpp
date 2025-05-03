#include <iostream>
#include <string>
using namespace std;

// Custom Exception
class ArrayIndexOutOfBounds {
    string message;
public:
    ArrayIndexOutOfBounds(int index, int size) {
        message = "Index " + to_string(index) + " is out of bounds (size = " + to_string(size) + ")";
    }
    string what() const {
        return message;
    }
};

// Template SafeArray class
template <typename T>
class SafeArray {
private:
    T* data;
    int size;

public:
    SafeArray(int s) {
        size = s;
        data = new T[size];
    }

    // Destructor
    ~SafeArray() {
        delete[] data;
    }

    // Overloaded [] with bounds checking
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw ArrayIndexOutOfBounds(index, size);
        }
        return data[index];
    }

    int getSize() const { return size; }
};

// Demo in main()
int main() {
    try {
        SafeArray<int> arr(5);

        cout << "Storing values in SafeArray:\n";
        for (int i = 0; i < arr.getSize(); i++) {
            arr[i] = (i + 1) * 10;
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }

        cout << "\nTrying to access out-of-bounds index:\n";
        cout << arr[10] << endl; // This should throw exception

    } catch (const ArrayIndexOutOfBounds& ex) {
        cout << "Exception: " << ex.what() << endl;
    }

    return 0;
}
