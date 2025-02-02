/*Task 2: You are required to pass a single dimension array to a function (type of the array can be your
choice) and perform add operations to each element. Return the array to the main function after
completion. One small catch is that the arguments and the return type should be void*. (Create an array
via the main arguments). */


//Simplifying this code : I am required to make one array with the type of my choice dynamically , get the add value to perform add operations for each element.
//After creating the array dynamically , i would fill up the array and then pass that array to the modify function . The function is obligated to have void pointer as its argument
//and return type. Conversion is necessary here . After modifying , i will display the updated array and in the last free the array.

#include <iostream>
#include <cstdlib>  // For atoi()
using namespace std;

// Function to add value to each element
void* addToArray(void* arr, int size, int addValue) {
    int* intArr = static_cast<int*>(arr);  // Convert void* to int* by the format : target_type* pointer_variable = static_cast<target_type*>(expression);
    for (int i = 0; i < size; i++) {
        intArr[i] += addValue;  // Modify elements - intArr contains the address and is infact in form of *(intArr + i) here accessing the values through address
    }    
    return arr; 
}
   
int main(int argc, char* argv[]) {

    //Checking if there are enough arguments
    if (argc < 3) {
        cout << "Error: You provided only " << argc - 1 << " argument(s). At least 2 numbers are required for the array and add value!\n";
        return 1;
    }
    //Dynamically creating the array and extracting add element

    int size = argc - 2;  // Exclude program name and addValue
    int* arr = new int[size]; 
    int addValue = atoi(argv[argc - 1]);  // Last argument is addValue

    //After creating the array , now filling the array with the help of argv

    for (int i = 1; i <= size; i++) { //Starting from 1 bcs argv[0] is the program name
        arr[i - 1] = atoi(argv[i]);   //The atoi function  converts a string (const char*) to an integer and hence stores it in the array
    
    } 
    //Displaying the original Array before modification
  
    cout << "Original array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl; 

    // Modify array
    addToArray(arr, size, addValue);

    // Displaying modified array
    cout << "Modified array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;  
    return 0;  
}


    


