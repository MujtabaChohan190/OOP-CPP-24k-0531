#include <iostream>
#include <vector>
using namespace std;

// Base class for all bank accounts
class BankAccount {
protected:
    int accountNumber;
    double balance;
    bool isFrozen;   //variable to track if account is frozen

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal), isFrozen(false) {}

    virtual void deposit(double amount) {
        if (isFrozen) {
            cout << "Account " << accountNumber << " is frozen. Cannot deposit.\n";
            return;
        }
        balance += amount;
        cout << "Deposited $" << amount << " into Account " << accountNumber << ".\n";
    }

    virtual bool withdraw(double amount) {
        if (isFrozen) {
            cout << "Account " << accountNumber << " is frozen. Cannot withdraw.\n";
            return false;
        }

        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Account " << accountNumber << ".\n";
            return true;
        }

        cout << "Insufficient funds in Account " << accountNumber << "!\n";
        return false;
    }

    void freezeAccount() {
        isFrozen = true;
        cout << "Account " << accountNumber << " has been frozen.\n";
    }

    void unfreezeAccount() {
        isFrozen = false;
        cout << "Account " << accountNumber << " has been unfrozen.\n";
    }

    virtual void displayBalance() const {
        cout << "Account " << accountNumber << " Balance: $" << balance;
        if (isFrozen) cout << " (Frozen)";
        cout << endl;
    }

    virtual ~BankAccount() {}  // It Ensures proper cleanup of derived class objects when deleted via base class pointer otherwise only base destructor would be called
};

// Savings Account - Applies interest
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int accNum, double bal) : BankAccount(accNum, bal) {}

    void applyInterest() {
        if (isFrozen) {
            cout << "Account " << accountNumber << " is frozen. Cannot apply interest.\n";
            return;
        }
        double interest = balance * 0.03;
        balance += interest;
        cout << "Interest of $" << interest << " applied to Savings Account " << accountNumber << ".\n";
    }
};

// Checking Account - Allows overdraft
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(int accNum, double bal) : BankAccount(accNum, bal) {}

    bool withdraw(double amount) override {
        if (isFrozen) {
            cout << "Account " << accountNumber << " is frozen. Cannot withdraw.\n";
            return false;
        }

        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Checking Account " << accountNumber << ".\n";
            return true;
        } else {
            cout << "Overdraft Warning! Attempted withdrawal of $" << amount << " from Account " << accountNumber << ".\n";
            return false;
        }
    }
};

// Business Account - Deducts tax on deposit
class BusinessAccount : public BankAccount {
public:
    BusinessAccount(int accNum, double bal) : BankAccount(accNum, bal) {}

    void deposit(double amount) override {
        if (isFrozen) {
            cout << "Account " << accountNumber << " is frozen. Cannot deposit.\n";
            return;
        }
        double tax = amount * 0.02;  
        balance += (amount - tax);
        cout << "Deposited $" << amount << " into Business Account " << accountNumber << " (Tax: $" << tax << ").\n";
    }
};

// Base class for employees (Teller, Manager)
class Employee {
public:
    virtual void performTransaction(BankAccount& account, double amount, string type) = 0;  // It Enforces derived classes to implement transaction logic, enabling polymorphism
    virtual ~Employee() {}
};

// Teller - Can deposit, withdraw, and freeze accounts
class Teller : public Employee {
public:
    void performTransaction(BankAccount& account, double amount, string type) override {
        if (type == "deposit") account.deposit(amount);
        else if (type == "withdraw") account.withdraw(amount);
        else cout << "Invalid transaction type.\n";
    }

    void freezeAccount(BankAccount& account) {
        account.freezeAccount();
    }

    void unfreezeAccount(BankAccount& account) {
        account.unfreezeAccount();
    }
};

// Manager - Can do everything Teller does + adjust limits
class Manager : public Teller {
public:
    void overrideLimit(CheckingAccount& account) {
        cout << "Manager overriding overdraft limits for Checking Account " << accountNumber << ".\n";
    }
};

// Main Function (Demonstrating Polymorphism)
int main() {
    
    vector<BankAccount*> accounts;
    accounts.push_back(new SavingsAccount(101, 5000));
    accounts.push_back(new CheckingAccount(102, 2000));
    accounts.push_back(new BusinessAccount(103, 10000));

    Teller teller;
    Manager manager;

    cout << "\n=== Teller Performing Transactions ===\n";
    
    for (size_t i = 0; i < accounts.size(); i++) {
        teller.performTransaction(*accounts[i], 1000, "deposit");  // Using polymorphism
        accounts[i]->displayBalance();
    }

    cout << "\n=== Teller Freezing an Account ===\n";
    teller.freezeAccount(*accounts[1]);  // Freezing Checking Account

    cout << "\n=== Attempting to Withdraw from Frozen Account ===\n";
    accounts[1]->withdraw(500);  // Should fail

    cout << "\n=== Manager Unfreezing the Account ===\n";
    manager.unfreezeAccount(*accounts[1]);

    cout << "\n=== Attempting to Withdraw Again After Unfreezing ===\n";
    accounts[1]->withdraw(500);  // Should succeed

    cout << "\n=== Manager Performing Transactions ===\n";
    for (size_t i = 0; i < accounts.size(); i++) {
        manager.performTransaction(*accounts[i], 500, "withdraw");  // Using polymorphism
        accounts[i]->displayBalance();
    }

    for (size_t i = 0; i < accounts.size(); i++) {
        delete accounts[i];  //If there was only one bank account then one delete could work.
    }

    return 0;
}
