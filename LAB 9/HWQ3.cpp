#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string position;

public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter position: ";
        cin >> position;
    }

    virtual void displayData() const {
        cout << "Name: " << name << ", Age: " << age << ", Position: " << position << endl;
    }

    virtual double bonus() const = 0;  // Pure virtual function for bonus calculation
};

class Admin : virtual public Person {
protected:
    double salary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter salary for admin: ";
        cin >> salary;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Salary: " << salary << endl;
    }

    double bonus() const override {
        return salary * 0.1;  // 10% bonus for admin
    }
};

class Account : virtual public Person {
protected:
    double salary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter salary for account: ";
        cin >> salary;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Salary: " << salary << endl;
    }

    double bonus() const override {
        return salary * 0.15;  // 15% bonus for account
    }
};

class Master : public Admin, public Account {
private:
    double bonusAmount;

public:
    void getData() override {
        Admin::getData();
        Account::getData();
    }

    void displayData() const override {
        Admin::displayData();
        Account::displayData();
    }

    double bonus() const override {
        return Admin::bonus() + Account::bonus();  // Sum of both bonuses
    }
};

int main() {
    Person *employee;

    Master masterEmployee;
    employee = &masterEmployee;

    employee->getData();
    employee->displayData();
    cout << "Total Bonus: " << employee->bonus() << endl;

    return 0;
}
