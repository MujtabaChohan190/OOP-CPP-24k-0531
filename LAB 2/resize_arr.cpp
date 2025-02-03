/*Write a program that can resize a single dimension int array if the elements exceed the total size.
Consider an int array of size 5 (uninitialized), you start adding items to the array and if the quantity of
the elements exceeds double the array size. Once finished resizing the array again to the max quantity of
the elements present in the array.*/

#include <iostream>  
using namespace std;

void resizeArray(int*& arr, int& capacity, int newSize) { //*& Bcs the function will recive the pointer to array and since pointer needs to be modified , we do this in case of resizing
    int* newArr = new int[newSize];  // Allocate new array with the new size
    for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];  // Copy old array elements to the new array
    }
    delete[] arr;  // Free old array memory
    arr = newArr;   // Now copy the address of new arr to arr making the resized array
    capacity = newSize;
}

int main() {
    int capacity = 5;  
    int size = 0;     
    int* arr = new int[capacity];  // Dynamically allocated array

    int input;
    cout << "Enter numbers to add to the array (enter -1 to stop): \n";
    
    while (true) {
        cout << "Enter a number: ";
        cin >> input;

        if (input == -1) {
            break;  // Stop the input when -1 is entered
        }

        // Before adding elements to the array , program checks if the array is full, if its full then resize it
        if (size == capacity) {
            resizeArray(arr, capacity, capacity * 2);  // Double the size of the array
            cout << "Array resized to capacity: " << capacity << endl;
        }

        arr[size] = input;  // Add the input to the array
        size++;  // Increment the size
    }

    // Now resize the array to exactly fit the number of elements present
    resizeArray(arr, capacity, size);
    cout << "Array resized to fit the number of elements: " << size << endl;

    
    cout << "Final array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; 
    return 0;
}
