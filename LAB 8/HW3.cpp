#include <iostream>

using namespace std;

// Base class Person (Abstract class)
class Person {
protected:
    int empID;
public:

    Person(int id = 0) : empID(id) {}

    int getEmpID() const {
        return empID;
    }

    virtual double bonus() const = 0;

    virtual void displayData() const {
        cout << "Employee ID: " << empID << endl;
    }

    virtual ~Person() {}
};

// Derived class Admin
class Admin : public Person {
protected:
    string name;
    double monthlyIncome;
public:

    Admin(int id, string empName, double income) : Person(id), name(empName), monthlyIncome(income) {}


    double bonus() const override {
        return monthlyIncome * 0.05 * 12; // 5% annual bonus
    }


    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

// Derived class Accounts
class Accounts : public Person {
protected:
    string name;
    double monthlyIncome;
public:

    Accounts(int id, string empName, double income) : Person(id), name(empName), monthlyIncome(income) {}


    double bonus() const override {
        return monthlyIncome * 0.05 * 12; // 5% annual bonus
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

int main() {
    // Taking input dynamically
    int id;
    string name;
    double income;

    cout << "Enter details for Admin Employee:\n";
    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore(); // Clear buffer
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Monthly Income: ";
    cin >> income;
    Admin admin(id, name, income);

    cout << "\nEnter details for Accounts Employee:\n";
    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Monthly Income: ";
    cin >> income;
    Accounts accounts(id, name, income);

    // Display results using base class pointers (demonstrating polymorphism)
    Person* employees[2] = { &admin, &accounts };

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < 2; i++) {
        employees[i]->displayData();
        cout << "-------------------------\n";
    }

    return 0;
}
