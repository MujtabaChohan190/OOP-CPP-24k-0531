/*Create a class called Matrix containing a constructor that initializes the number of rows and number of columns
of a new Matrix object. The Matrix class has the following information.
1. Number of rows of matrix
2. Number of columns of matrix
3. Elements of matrix in the form of 2D array
The Matrix class has methods for each of the following
1. Get the number of rows
2. Get the number of columns
3. Set the elements of the matrix at the given position (i,j)
4. Adding two matrices. If the matrices are not addable, “Matrices cannot be added” will be displayed
5. Multiplying the two matrices*/

#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;      
    int cols;       
    int **elements; // 2D array to hold matrix elements

public:
    // Constructor that initializes rows and columns and allocates the 2D array.
    Matrix(int r, int c) : rows(r), cols(c) {
        elements = new int*[rows];
        for (int i = 0; i < rows; i++) {
            elements[i] = new int[cols];
            // Initialize each element to zero.
            for (int j = 0; j < cols; j++) {
                elements[i][j] = 0;
            }
        }
    }

    // Destructor to free the allocated memory.
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete [] elements[i];
        }
        delete [] elements;
    }

    // Method to get the number of rows.
    int getRows() const {
        return rows;
    }

    // Method to get the number of columns.
    int getCols() const {
        return cols;
    }

    // Method to set the element at position (i, j) with a given value.
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
            elements[i][j] = value;
        else
            cout << "Invalid index (" << i << ", " << j << ")" << endl;
    }

    // Method to add two matrices.
    // If dimensions differ, an error message is displayed 
    Matrix add(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);  // Return an "empty" matrix.
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }


    // If the number of columns in the first matrix is not equal to the number of rows in the second,
    // an error message is displayed and a 0x0 matrix is returned.
    Matrix multiply(const Matrix &other) const {  
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);  // Return an "empty" matrix.
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.elements[i][j] = 0; // Ensure the result element is zero before accumulation.
                for (int k = 0; k < cols; k++) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    

    // Create two matrices A and B of the same dimensions (2x3)
    Matrix A(2, 3);
    Matrix B(2, 3);

    // Set elements for Matrix A
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(0, 2, 3);
    A.setElement(1, 0, 4);
    A.setElement(1, 1, 5);
    A.setElement(1, 2, 6);

    // Set elements for Matrix B
    B.setElement(0, 0, 6);
    B.setElement(0, 1, 5);
    B.setElement(0, 2, 4);
    B.setElement(1, 0, 3);
    B.setElement(1, 1, 2);
    B.setElement(1, 2, 1);

    cout << "Matrix A:" << endl;
    A.display();

    cout << "\nMatrix B:" << endl;
    B.display();

    // Add matrices A and B.
    Matrix C = A.add(B);
    if (C.getRows() != 0 && C.getCols() != 0) { 
        cout << "\nMatrix C (A + B):" << endl;
        C.display();
    }

    // For multiplication, creating  a matrix D such that A (2x3) can be multiplied by D (3x2).
    Matrix D(3, 2);
    D.setElement(0, 0, 1);
    D.setElement(0, 1, 2);
    D.setElement(1, 0, 3);
    D.setElement(1, 1, 4);
    D.setElement(2, 0, 5);
    D.setElement(2, 1, 6);

    cout << "\nMatrix D:" << endl;
    D.display();

    // Multiplying  Matrix A and Matrix D.
    Matrix E = A.multiply(D);
    if (E.getRows() != 0 && E.getCols() != 0) { // Check if valid result.
        cout << "\nMatrix E (A * D):" << endl;
        E.display();
    }

    return 0;
}
