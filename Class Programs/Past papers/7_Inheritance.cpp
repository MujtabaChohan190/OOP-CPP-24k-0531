#include <iostream>
#include <string>

using namespace std;

// Base Class: Employee
class Employee {
protected:
    int employeeID;
    string name;
    double salary;

public:
    Employee(int id, string n, double s) : employeeID(id), name(n), salary(s) {}

    // Constant function to calculate bonus (10% of salary)
    double calculateBonus() const {
        return salary * 0.1;
    }

    // Function to display employee details
    void displayDetails() const {
        cout << "Employee ID: " << employeeID << ", Name: " << name 
             << ", Salary: $" << salary << ", Bonus: $" << calculateBonus() << endl;
    }
};

// Derived Class: Staff (Inherits from Employee)
class Staff : public Employee {
public:
    static int staffCount;  // Static variable to track staff members

    Staff(int id, string n, double s) : Employee(id, n, s) {
        staffCount++; // Increment count when a new staff is created
    }

    // Static function to display total staff count
    static void displayStaffCount() {
        cout << "Total Staff Members: " << staffCount << endl;
    }

    // Function to simulate hiring a staff member
    void hireStaff() {
        cout << name << " has been hired as a staff member.\n";
    }
};

// Initialize static variable
int Staff::staffCount = 0;

// Derived Class: Faculty (Inherits from Staff)
class Faculty : public Staff {
public:
    static const int MAX_COURSES = 5;  // Constant variable for max courses

    Faculty(int id, string n, double s) : Staff(id, n, s) {}

    // Function to assign courses (checks against MAX_COURSES)
    void assignCourses(int numCourses) const {
        if (numCourses > MAX_COURSES) {
            cout << name << " cannot be assigned more than " << MAX_COURSES << " courses!\n";
        } else {
            cout << name << " is assigned " << numCourses << " courses.\n";
        }
    }
};

// Main function to demonstrate functionality
int main() {
    // Creating Staff members
    Staff staff1(101, "Alice", 50000);
    Staff staff2(102, "Bob", 55000);

    // Creating Faculty members
    Faculty faculty1(201, "Dr. Smith", 70000);
    Faculty faculty2(202, "Dr. Johnson", 75000);

    // Display details
    staff1.displayDetails();
    staff2.displayDetails();
    faculty1.displayDetails();
    faculty2.displayDetails();

    // Staff actions
    staff1.hireStaff();
    staff2.hireStaff();
    Staff::displayStaffCount();  // Calling static function

    // Faculty actions
    faculty1.assignCourses(4);
    faculty2.assignCourses(7);  // Exceeds MAX_COURSES

    return 0;
}
