#include<iostream>
using namespace std;

class ArrayOutofBounds : public exception {
    string str;
public:
    ArrayOutofBounds(string s) : str(s) {}
    const char* what() const noexcept override {
        return str.c_str();
    }
};

template<typename T>
class SafeArray {
    T* array;
    int size;

public:
    SafeArray(int size, T values[]) : size(size) {
        array = new T[size];
        for (int i = 0; i < size; i++) {
            array[i] = values[i];
        }
    }

    ~SafeArray() {
        delete[] array;
    }

    T& operator[](int x) {
        if (x < 0 || x >= size) throw ArrayOutofBounds("Array out of Bounds!");
        return array[x];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        int values[] = {1, 2, 3};
        SafeArray<int> arr(3, values);
        cout << "Array contents after initialization: ";
        arr.display();
        arr[0] = 10;
        cout << "arr[0] after modification: " << arr[0] << endl;
    }
    catch (const ArrayOutofBounds& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
