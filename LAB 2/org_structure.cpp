#include <iostream>
#include <cstring>  // For strcpy 

using namespace std;

// Define Employee structure (nested inside Organization)
struct Employee {
    int employee_id;
    char name[50];  // Using char array for demonstration (string can be used)
    double salary;
};

// Define Organization structure (contains Employee)
struct Organization {
    char organisation_name[50];
    char organisation_number[20];
    Employee emp;  // Nested structure
};

int main() {
    Organization org;  // Structure variable

    // Assigning values
    strcpy(org.organisation_name, "NU-Fast");
    strcpy(org.organisation_number, "NUFAST123ABC");

    org.emp.employee_id = 127;
    strcpy(org.emp.name, "Linus Sebastian");
    org.emp.salary = 400000;

    // Display output
    cout << "The size of structure Organization: " << sizeof(Organization) << endl;
    cout << "Organisation Name: " << org.organisation_name << endl;
    cout << "Organisation Number: " << org.organisation_number << endl;
    cout << "Employee ID: " << org.emp.employee_id << endl;
    cout << "Employee Name: " << org.emp.name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;

    return 0;
}
