// C++ program to demonstrate how to create dynamic variable
// using new
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // pointer to store the address returned by the new
    int* ptr;
    // allocating memory for integer
    ptr = new int;

    // assigning value using dereference operator
    *ptr = 10;

    // printing value and address
    cout << "Address: " << ptr << endl;
    cout << "Value: " << *ptr;

    return 0;
}
