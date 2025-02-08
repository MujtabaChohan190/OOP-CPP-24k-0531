/*Create a class called Employee that includes three pieces of information as instance variables—a first name (type
String), a last name (type String) and a monthly salary (double). If the monthly salary is not positive, set it to 0.0.
Write a test application named EmployeeTest that demonstrates class Employee’s capabilities. Create two
Employee objects and display each object’s yearly salary. Then give each Employee a 10% raise and display each
Employee’s yearly salary again.*/

#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
    double monthlySalary;

    public:
    string first_name;
    string last_name;

    //Constructor to make objects member initialization easy + initiliazing monthlysalary to 0.0 in certain case 
    Employee(string first, string last, double salary){
        first_name = first;
        last_name = last;
        if(salary > 0){   //CHECK BY SALARY NOT MONTHLYSALARY..
            monthlySalary = salary;
        } else{
            monthlySalary = 0.0;
        }
    }

    // Getter method for monthlySalary
    double getMonthlySalary() {
        return monthlySalary;
    }


    // Method to give a 10% raise
    void giveRaise() {
        monthlySalary = monthlySalary * 1.10;
    }
};

// EmployeeTest function to demonstrate Employee class
void EmployeeTest() {
    // Creating two Employee objects
    Employee emp1("John", "peter", 5000);
    Employee emp2("Jane", "Smith", 6000);

    // Displaying initial yearly salaries
    cout << "Initial Yearly Salaries:\n";
    cout << emp1.first_name << " " << emp1.last_name << ": $" << emp1.getMonthlySalary()<< endl;
    cout << emp2.first_name << " " << emp2.last_name << ": $" << emp2.getMonthlySalary()<< endl;

    emp1.giveRaise();
    emp2.giveRaise();

    // Displaying updated yearly salaries after raise
    cout << "Initial Yearly Salaries:\n";
    cout << emp1.first_name << " " << emp1.last_name << ": $" << emp1.getMonthlySalary() * 12<< endl;
    cout << emp2.first_name << " " << emp2.last_name << ": $" << emp2.getMonthlySalary() * 12<< endl;

}

int main(){
    //Demonstrating class employee functionalities
    EmployeeTest();
    return 0;
}
