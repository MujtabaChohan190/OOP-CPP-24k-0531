#include <iostream>
using namespace std;

class Array2D {
private:
    int **arr;
    int rows, cols;

public:
    // Constructor for dynamic allocation
    Array2D(int r, int c) {
        rows = r;
        cols = c;
        arr = new int*[rows]; // Allocate row pointers
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols]; // Allocate each row
            for (int j = 0; j < cols; j++) {
                arr[i][j] = (i + 1) * (j + 1); // Initializing with some values
            }
        }
    }

    // Copy Constructor (Deep Copy)
    Array2D(const Array2D &obj) {
        rows = obj.rows;
        cols = obj.cols;
        
        arr = new int*[rows]; // Allocate new memory
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = obj.arr[i][j]; // Copy values
            }
        }
    }

    // Display Function
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~Array2D() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i]; // Free each row
        }
        delete[] arr; // Free row pointers
    }
};

int main() {
    Array2D obj1(3, 3);  // Creating first object
    cout << "Original 2D Array:\n";
    obj1.display();

    Array2D obj2 = obj1;  // Calling copy constructor
    cout << "Copied 2D Array:\n";
    obj2.display();

    return 0;
}
