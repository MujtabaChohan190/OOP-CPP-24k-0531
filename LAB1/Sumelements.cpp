// Write a program that calculates the sum of all the elements in array using pointers

#include <iostream>
using namespace std;

int main(){
    int n;

    //Getting the user input for size 
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    int *ptr = arr; //Pointer to the array holding array address 

    //Input the values of elements
    for(int i = 0; i<n; i++){
        cout<<"Enter "<<n<<"elements: ";
        cin>>*(ptr+i);
    }

    //Calculating sum through pointer
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+= *(ptr +i);
    }
    cout<<"Sum of array elements is "<<sum<<endl;
    return 0;
}


