#include <iostream>
#include <cstring> // For std::memcpy
using namespace std;

int main() {
    // Step 1: Allocate initial array
   
    int* arr = new int[5]{1, 2, 3, 4, 5};//Yes you can do this as well

    // Step 2: Print the original array
    cout << "Original array: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Step 3: Resize the array
    int* newArr = new int[8]; // Allocate new memory

    // Copy old data to new array
    memcpy(newArr, arr, 5 * sizeof(int));
	
    // Initialize additional elements
    for (int i = 4; i < 8; ++i) {
        newArr[i] = 0; // Set to 0 or any default value
    }

    // Free the old array memory
    delete[] arr;

    // Update the pointer
    arr = newArr;

    // Step 4: Print the resized array
    cout << "Resized array: ";
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Step 5: Clean up memory
    delete[] arr;

    return 0;
}

