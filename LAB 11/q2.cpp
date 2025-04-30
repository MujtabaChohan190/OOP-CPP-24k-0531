#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class DimensionMismatch : public exception {
    string str;
public:
    DimensionMismatch(string s) : str(s) {}
    const char* what() const noexcept override {
        return str.c_str();
    }
};

template <typename T>
class Matrix {
    int rows;
    int columns;
    vector<vector<T>> matrix;

public:
    Matrix() : rows(0), columns(0) {}

    Matrix(int r, int c) : rows(r), columns(c), matrix(r, vector<T>(c, 0)) {
        Initialize_matrix();
    }

    void Initialize_matrix() {
        cout << "Enter values for " << rows << "x" << columns << " matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void checkBounds(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= columns)
            throw out_of_range("Index out of Bounds");
    }

    Matrix<T> operator+(Matrix<T>& other) {
        if (rows != other.rows || columns != other.columns)
            throw DimensionMismatch("Dimension Mismatch for Addition!");
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(Matrix<T>& other) {
        if (rows != other.rows || columns != other.columns)
            throw DimensionMismatch("Dimension Mismatch for Subtraction!");
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(Matrix<T>& other) {
        if (columns != other.rows)
            throw DimensionMismatch("Dimension Mismatch for Multiplication!");
        Matrix<T> result(rows, other.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < columns; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        int choice;
        cout << "Select Operation:\n";
        cout << "1. Addition (A + B)\n";
        cout << "2. Subtraction (A - B)\n";
        cout << "3. Multiplication (A * B)\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int r1, c1, r2, c2;
                cout << "Enter number of rows and columns for Matrix A: ";
                cin >> r1 >> c1;
                Matrix<int> A(r1, c1);

                cout << "Enter number of rows and columns for Matrix B: ";
                cin >> r2 >> c2;
                Matrix<int> B(r2, c2);

                Matrix<int> C = A + B;
                cout << "Result of A + B:\n";
                C.display();
                break;
            }
            case 2: {
                int r1, c1, r2, c2;
                cout << "Enter number of rows and columns for Matrix A: ";
                cin >> r1 >> c1;
                Matrix<int> A(r1, c1);

                cout << "Enter number of rows and columns for Matrix B: ";
                cin >> r2 >> c2;
                Matrix<int> B(r2, c2);

                Matrix<int> C = A - B;
                cout << "Result of A - B:\n";
                C.display();
                break;
            }
            case 3: {
                int r1, c1, r2, c2;
                cout << "Enter number of rows and columns for Matrix A: ";
                cin >> r1 >> c1;
                Matrix<int> A(r1, c1);

                cout << "Enter number of rows and columns for Matrix B: ";
                cin >> r2 >> c2;
                Matrix<int> B(r2, c2);

                Matrix<int> C = A * B;
                cout << "Result of A * B:\n";
                C.display();
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    catch (const DimensionMismatch& e) {
        cout << "DimensionMismatch Exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Standard Exception: " << e.what() << endl;
    }

    return 0;
}
