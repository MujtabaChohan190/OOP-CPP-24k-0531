#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double* data; // 1D array storing elements in row-major order

public:

    Matrix() : rows(0), cols(0), data(nullptr) {}


    Matrix(int r, int c) : rows(r), cols(c) {
        data = new double[rows * cols](); // Initialize all elements to 0 () ensures that the array is initialized to 0.0 for every element, which is particularly useful when you need a clean starting state for your matrix.
    }

    // 🔹 Copy Constructor (Deep Copy)
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        cout << "Copy Constructor Called\n";
        data = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = other.data[i];
        }
    }


    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
        cout << "Move Constructor Called\n"; 
        other.data = nullptr;
        other.rows = other.cols = 0;
    }

    // 🔹 Destructor (Free Memory)
    ~Matrix() {
        delete[] data;
    }

    // 🔹 Get Row & Column Count
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // 🔹 Access Element at (r, c)
    double& at(int r, int c) {
        return data[r * cols + c]; // Row-major access
    }

    // 🔹 Fill the Matrix with a Value
    void fill(double value) {
        for (int i = 0; i < rows * cols; i++) {
            data[i] = value;
        }
    }

    // 🔹 Transpose the Matrix (New Object)
    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                transposed.at(c, r) = at(r, c);
            }
        }
        return transposed;
    }

    // 🔹 Print Matrix
    void print() const {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << at(r, c) << " ";
            }
            cout << endl;
        }
    }
};

// 🔹 Main Function to Test
int main() {
    // ✅ Create a Matrix
    Matrix m(3, 2); // Create a 3x2 matrix
    m.fill(5.0);    // Fill with 5.0
    m.at(1, 1) = 10.0; // Modify element

    cout << "Original Matrix:\n";
    m.print();

    // ✅ Copy Constructor Test
    cout << "\n🔹 Creating a Copy of the Matrix...\n";
    Matrix copyMatrix = m; // Calls Copy Constructor
    cout << "Copied Matrix:\n";
    copyMatrix.print();

    // ✅ Move Constructor Test
    cout << "\n🔹 Moving a Matrix...\n";
    Matrix movedMatrix = std::move(m); // Calls Move Constructor
    cout << "Moved Matrix:\n";
    movedMatrix.print();

    cout << "\n🔹 Original Matrix After Move (Should Be Empty):\n";
    m.print(); // Should print nothing or a 0x0 matrix

    return 0;
}

