#include <iostream>
using namespace std;

class MoveMatrix {
private:
    int** arr;
    int rows, cols;

public:
    // Constructor
    MoveMatrix(int r, int c) {
        rows = r;
        cols = c;
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = (i + 1) * (j + 1);
            }
        }
        cout << "Constructor called\n";
    }

    // Copy Constructor (Deep Copy)
    MoveMatrix(const MoveMatrix &obj) {
        rows = obj.rows;
        cols = obj.cols;
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = obj.arr[i][j];
            }
        }
        cout << "Copy Constructor called\n";
    }

    // Move Constructor
    MoveMatrix(MoveMatrix &&obj) noexcept {
        rows = obj.rows;
        cols = obj.cols;
        arr = obj.arr;

        obj.arr = nullptr; // Nullify source object
        obj.rows = obj.cols = 0;

        cout << "Move Constructor called\n";
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

    // Destructor
    ~MoveMatrix() {
        if (arr != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] arr[i];
            }
            delete[] arr;
        }
        cout << "Destructor called\n";
    }
};

int main() {
    MoveMatrix mat1(3, 3); // Constructor is called
    cout << "Original Matrix:\n";
    mat1.display();

    MoveMatrix mat2 = move(mat1); // Move Constructor is called
    cout << "Moved Matrix:\n";
    mat2.display();

    return 0;
}
