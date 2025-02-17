/*Task - 01: Design a Matrix Class with Multiple Constructors
Create a class Matrix that represents a 2D matrix of double values. It must handle row-major dynamic
allocation internally.
Details:

o Constructors:
1. Default constructor: Initializes a 0x0 matrix (rows = 0, cols = 0) or a nullptr-managed
array.
2. Parameterized constructor (rows, cols): Allocates a 2D matrix of size rows x cols.
Initialize elements to 0.
3. Copy constructor: Deep copy.
4. Move constructor: Transfers ownership of the matrix data.
5. Destructor: Deallocates the dynamic memory.
o Member functions:
 getRows() and getCols() to return the dimensions.
 at(int r, int c): returns a reference to the element at row r, column c.
 fill(double value): fills the entire matrix with the provided value.
 transpose(): returns a new Matrix object that is the transpose of the current matrix. Make
sure to print it as well.*/

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    int *numRows;
    int numCols;
    vector<vector<int>> mat;

public:
    Matrix(int rows, int cols) : numRows(new int(rows)), numCols(cols), mat(*numRows, vector<int>(numCols, 0)) {}

    Matrix() : numRows(nullptr), numCols(0), mat(0, vector<int>(0, 0)) {}

    Matrix(const Matrix &other) {
        numRows = new int(*other.numRows);
        numCols = other.numCols;
        mat = other.mat;
    }

    Matrix(Matrix &&other) noexcept : numRows(other.numRows), numCols(other.numCols), mat(move(other.mat)) {
        other.numRows = nullptr;
        other.numCols = 0;
    }

    ~Matrix() { delete numRows; }

    int &at(int row, int col) {
        return mat[row][col];
    }

    void fill(int value) {
        for (int i = 0; i < *numRows; i++)
            for (int j = 0; j < numCols; j++)
                mat[i][j] = value;
    }

    Matrix transpose() {
        Matrix transposed(numCols, *numRows);
        for (int i = 0; i < *numRows; i++)
            for (int j = 0; j < numCols; j++)
                transposed.mat[j][i] = mat[i][j];
        return transposed;
    }

    void print() const {
        if (!numRows || *numRows == 0) {
            cout << "Empty Matrix" << endl;
            return;
        }
        for (int i = 0; i < *numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix matrix1(3, 3);
    matrix1.fill(5);
    matrix1.at(1, 1) = 10;

    cout << "Original Matrix:" << endl;
    matrix1.print();

    Matrix matrix2(matrix1);
    cout << "Matrix 2 (Copied):" << endl;
    matrix2.print();

    Matrix matrix3 = move(matrix1);
    cout << "Matrix 3 (Moved):" << endl;
    matrix3.print();

    Matrix transposedMatrix = matrix2.transpose();
    cout << "Transposed Matrix:" << endl;
    transposedMatrix.print();

    return 0;
}
