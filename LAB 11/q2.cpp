#include <iostream>
#include <string>
using namespace std;

// Custom exception for dimension mismatch
class DimensionMismatchException {
public:
    string message;
    DimensionMismatchException(string msg) : message(msg) {}
    string what() const { return message; }
};

// Template Matrix class
template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = 0;
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) { 
// Copy constructor is defined to perform a deep copy.
// This is necessary because the Matrix class uses dynamic memory (new/delete).
// Without this, returning a Matrix by value (like in operator+ or operator*) would use a shallow copy,
// leading to shared pointers and potential memory issues (double deletion, dangling pointers).
        rows = other.rows;
        cols = other.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    // Access operator with bounds checking
    T& operator()(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw DimensionMismatchException("Index out of bounds");
        return data[r][c];
    }

    // Addition operator
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException("Addition: Matrix dimensions must match");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Multiplication operator
    Matrix operator*(const Matrix& other) {
        if (cols != other.rows)
            throw DimensionMismatchException("Multiplication: Incompatible matrix dimensions");

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    // Display matrix
    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

// Demo in main
int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A(0, 0) = 1; A(0, 1) = 2;
        A(1, 0) = 3; A(1, 1) = 4;

        B(0, 0) = 5; B(0, 1) = 6;
        B(1, 0) = 7; B(1, 1) = 8;

        cout << "Matrix A:\n";
        A.display();

        cout << "\nMatrix B:\n";
        B.display();

        Matrix<int> C = A + B;
        cout << "\nA + B:\n";
        C.display();

        Matrix<int> D = A * B;
        cout << "\nA * B:\n";
        D.display();

        cout << "\nTrying out-of-bounds access:\n";
        cout << A(10, 10); // Should throw exception
    }
    catch (DimensionMismatchException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
