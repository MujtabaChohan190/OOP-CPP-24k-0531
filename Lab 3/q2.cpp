/*Create a class called Date that includes three pieces of information as instance variables—a month (typeint), a day
(typeint) and a year (typeint). Provide a method displayDate that displays the month, day and year separated by
forward slashes(/). Write a test application named DateTest that demonstrates classDate’s capabilities.*/

#include<iostream>
using namespace std;

class Date {
    public:
    int month;
    int day;
    int year;

    // Constructor
    Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    // Method to display the date (no return value, so return type is void)
    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }

};

int main() {
    // Creating an object of the Date class and initializing with values
    Date DateTest(6, 4, 2005);
    DateTest.displayDate();  // Display the date
    return 0;
    
    // IN CASE OF MANUAL WORK WITH NO CONSTRUCTOR
    // myDate.month = 2;   
    // myDate.day = 4;    
    // myDate.year = 2025;
}
