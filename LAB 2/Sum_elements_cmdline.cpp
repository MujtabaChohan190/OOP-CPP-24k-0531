/*Task 1: Write a program that calculates the sum of all the elements in array using pointers
(Note: Generate the array via user in the main function use argv)*/

#include <iostream>
#include <cstdlib>  // For atoi()
using namespace std;

int main(int argc, char* argv[]) {
  //This is done to check if the user entered enough arguments
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <num1> <num2> ..." << endl;
        return 1;
    }

    int size = argc - 1;
    int* arr = new int[size]; 
    int sum = 0;

    // Store values and calculate sum - we started from 1 bcs argv[0] contains the program name 
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
        sum += arr[i - 1];
    }

    // Display array elements
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display sum
    cout << "Sum of array elements: " << sum << endl;

    delete[] arr;
    return 0;
}
