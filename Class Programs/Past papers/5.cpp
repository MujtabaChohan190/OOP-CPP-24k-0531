/*Emily is developing a banking system and needs to create a class to represent a bank account. The account class should
have member variables to store the account number, account holder&#39;s name, account balance, and account type (e.g.,
savings or checking). Emily wants to ensure that when an account object is created, the necessary information is
initialized properly. She also wants to implement a copy constructor to make it easier to create copies of existing account
objects. Additionally, she wants to provide a way to deposit and withdraw funds from the account while keeping track of
the account balance.
Write a Program for the account class that includes a default constructor, a parameterized constructor, a copy constructor,
and member functions (Such as withdraw, deposit, check balance, print mini statement) to deposit and withdraw funds,
check balance, and print a small mini balance statement. Ensure that the account balance is updated accordingly when
funds are deposited or withdrawn. Additionally, provide an example usage of the copy constructor in a scenario where
Emily creates a new account object based on an existing account object and performs some transactions on both accounts.*/


#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;
    string accountType;

public:
    // Default Constructor
    Account() : accountNumber(0), accountHolder("Unknown"), balance(0.0), accountType("Unknown") {}

    // Parameterized Constructor
    Account(int accNum, string holder, double bal, string type) 
        : accountNumber(accNum), accountHolder(holder), balance(bal), accountType(type) {}

    // Copy Constructor
    Account(const Account& other) {
        accountNumber = other.accountNumber;
        accountHolder = other.accountHolder;
        balance = other.balance;
        accountType = other.accountType;
        cout << "Copy constructor called! A copy of " << accountHolder << "'s account has been created.\n";
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    // Check Balance function
    void checkBalance() const {
        cout << "Account Balance: $" << balance << endl;
    }

    // Mini Statement function
    void printMiniStatement() const {
        cout << "\n----- Mini Statement -----\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-------------------------\n";
    }
};

// Main function to test the implementation
int main() {
    // Creating an account using parameterized constructor
    Account acc1(101, "Emily", 1000.0, "Savings");

    // Performing transactions
    acc1.deposit(500);
    acc1.withdraw(200);
    acc1.checkBalance();
    acc1.printMiniStatement();

    // Using the copy constructor
    Account acc2 = acc1;  // Copy constructor is called here

    // Performing transactions on copied account
    acc2.deposit(300);
    acc2.withdraw(100);
    acc2.printMiniStatement();

    return 0;
}
