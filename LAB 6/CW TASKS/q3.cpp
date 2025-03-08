#include <iostream>
#include <vector>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int id, string name) : id(id), name(name) {}
    virtual void showInfo() {
        cout << "Employee ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() {}
};

// Abstract Interfaces ( Pure virtual classe) for different employee roles
class IOrderTaker {
public:
    virtual void takeOrder(string order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(string order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

// Employee Roles
class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int id, string name) : Employee(id, name) {}
    void takeOrder(string order) override {
        cout << name << " (Waiter) is taking order: " << order << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int id, string name) : Employee(id, name) {}
    void prepareOrder(string order) override {
        cout << name << " (Chef) is preparing: " << order << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int id, string name) : Employee(id, name) {}
    void generateBill(double amount) override {
        cout << name << " (Cashier) generated bill: $" << amount << endl;
    }
};

// Manager has multiple roles (Waiter + Cashier)
class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int id, string name) : Employee(id, name) {}
    void takeOrder(string order) override {
        cout << name << " (Manager) is taking order: " << order << endl;
    }
    void generateBill(double amount) override {
        cout << name << " (Manager) generated bill: $" << amount << endl;
    }
};

// Base Menu Class
class Menu {
protected:
    string itemName;
    double price;
public:
    Menu(string item, double price) : itemName(item), price(price) {}
    virtual double calculatePrice() = 0;
    virtual void showItem() {
        cout << itemName << ": $" << calculatePrice() << endl;
    }
    virtual ~Menu() {}
};

// Food Menu (No extra tax)
class FoodMenu : public Menu {
public:
    FoodMenu(string item, double price) : Menu(item, price) {}
    double calculatePrice() override {
        return price;
    }
};

// Beverage Menu (Applies a 10% beverage tax)
class BeverageMenu : public Menu {
public:
    BeverageMenu(string item, double price) : Menu(item, price) {}
    double calculatePrice() override {
        return price * 1.10; // 10% tax
    }
};

// Main function demonstrating polymorphism
int main() {
    // Dynamic array of employees
    Employee* employees[] = {
        new Waiter(1, "Alice"),
        new Chef(2, "Bob"),
        new Cashier(3, "Charlie"),
        new Manager(4, "David")
    };

    // Demonstrate employees performing tasks dynamically
    cout << "\n=== Employee Tasks ===\n";
    for (int i = 0; i < 4; i++) {
        employees[i]->showInfo();
    }

    // Order handling using polymorphism
    IOrderTaker* orderTakers[] = { new Waiter(5, "Eve"), new Manager(6, "Frank") };
    cout << "\n=== Taking Orders ===\n";
    for (int i = 0; i < 2; i++) {
        orderTakers[i]->takeOrder("Burger & Coke");
    }

    // Preparing order
    IOrderPreparer* chef = new Chef(7, "Grace");
    cout << "\n=== Preparing Orders ===\n";
    chef->prepareOrder("Burger & Coke");

    // Generating bill using polymorphism
    IBiller* billers[] = { new Cashier(8, "Henry"), new Manager(9, "Ivy") };
    cout << "\n=== Generating Bills ===\n";
    for (int i = 0; i < 2; i++) {
        billers[i]->generateBill(15.99);
    }

    // Menu demonstration
    Menu* menuItems[] = {
        new FoodMenu("Pizza", 12.99),
        new BeverageMenu("Orange Juice", 3.50)
    };

    cout << "\n=== Menu Items ===\n";
    for (int i = 0; i < 2; i++) {
        menuItems[i]->showItem();
    }

    // Cleanup
    for (int i = 0; i < 4; i++) delete employees[i];
    for (int i = 0; i < 2; i++) delete orderTakers[i];
    delete chef;
    for (int i = 0; i < 2; i++) delete billers[i];
    for (int i = 0; i < 2; i++) delete menuItems[i];

    return 0;
}
