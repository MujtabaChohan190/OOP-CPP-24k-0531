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
    int rows;
    int cols;
    vector<vector<double>> matrix;

public:
    Matrix() : rows(0), cols(0), matrix(0, vector<double>(0, 0)) {}

    Matrix(int r, int c) : rows(r), cols(c), matrix(r, vector<double>(c, 0)) {}

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), matrix(other.matrix) {}

    Matrix(Matrix &&other) noexcept : rows(other.rows), cols(other.cols), matrix(move(other.matrix)) {
        other.rows = 0;
        other.cols = 0;
    }

    ~Matrix() {}

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    double &at(int r, int c) {
        return matrix[r][c];
    }

    void fill(double value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = value;
            }
        }
    }

    Matrix transpose() {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed.matrix[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }

    void print() const {
        for (const auto &row : matrix) {
            for (double value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix mtx(3, 3); 
    mtx.fill(5.5); 

    mtx.at(1, 1) = 10;

    cout << "Original Matrix:\n";
    mtx.print();

    Matrix transposedMtx = mtx.transpose();
    cout << "Transposed Matrix:\n";
    transposedMtx.print();

    return 0;
}
