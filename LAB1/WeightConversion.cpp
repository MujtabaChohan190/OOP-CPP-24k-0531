/*4. Write a program that prompts the user to enter the weight of a person in kilograms and outputs the
equivalent weight in pounds. Output both the weights rounded to two decimal places. (Note that 1
kilogram = 2.2 pounds.) Format your output with two decimal places.*/

#include <iostream>
#include <iomanip>  // Required for setprecision and fixed
using namespace std;

int main() {
    float kg, lb;

    cout << "Enter weight in kilograms: ";
    cin >> kg;

    // Convert the weight to pounds
    lb = kg * 2.2;

    // Output both the weights rounded to two decimal places
    cout << fixed << setprecision(2);
    cout << "Weight in kilograms: " << kg << " kg" << endl;
    cout << "Equivalent weight in pounds: " << lb << " lb" << endl;

    return 0;
}
