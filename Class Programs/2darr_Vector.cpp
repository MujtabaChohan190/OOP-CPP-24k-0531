#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;

    // Step 1: Input dimensions of the 2D array
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Step 2: Declare a 2D vector
    vector< vector<int> > matrix(rows, vector<int>(cols));

    // Step 3: Input values into the 2D vector
    cout << "Enter elements for the 2D array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Step 4: Display the 2D vector
    cout << "The 2D array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Step 5: Modify an element
    cout << "\nModifying matrix[0][0] to 42.\n";
    matrix[0][0] = 42;

    // Display the modified matrix
    cout << "The modified 2D array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
