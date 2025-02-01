#include <iostream>
using namespace std;

int main() {
    int n;        // Size of the 1D array
    int rows, cols; // Dimensions of the 2D array

    // *** Single-dimensional dynamic array ***
    cout << "Enter the size of the 1D array: ";
    cin >> n;

    // Allocate memory for the 1D array
    int* arr1D = new int[n];

    // Input values for the 1D array
    cout << "Enter " << n << " elements for the 1D array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1D[i];
    }

    // Print the 1D array
    cout << "1D array elements are:\n";
    for (int i = 0; i < n; i++) {
        cout << arr1D[i] << " ";
    }
    cout << endl;

    // Deallocate memory for the 1D array
    delete[] arr1D;

    // *** Two-dimensional dynamic array ***
    cout << "\nEnter the number of rows and columns for the 2D array: ";
    cin >> rows >> cols;

    // Allocate memory for the 2D array
    int** arr2D = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr2D[i] = new int[cols];
    }

    // Input values for the 2D array
    cout << "Enter " << rows * cols << " elements for the 2D array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr2D[i][j];
        }
    }

    // Print the 2D array
    cout << "2D array elements are:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory for the 2D array
    for (int i = 0; i < rows; i++) {
        delete[] arr2D[i]; // Free each row
    }
    delete[] arr2D; // Free the row pointers

    return 0;
}
