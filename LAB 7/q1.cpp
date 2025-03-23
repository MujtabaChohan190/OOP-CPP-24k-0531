#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    Account(int accNum, double bal, string name) 
        : accountNumber(accNum), balance(bal), accountHolderName(name) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " successfully. New Balance: $" << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully. New Balance: $" << balance << endl;
        }
    }

    virtual void calculateInterest() = 0;

    virtual void printStatement() {
        cout << "\nAccount Statement for: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    virtual void getAccountInfo() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, double bal, string name, double intRate, double minBal)
        : Account(accNum, bal, name), interestRate(intRate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "Interest of $" << interest << " added. New Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if ((balance - amount) < minimumBalance) {
            cout << "Withdrawal failed! Balance cannot fall below $" << minimumBalance << endl;
        } else {
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, string name, double overdraft)
        : Account(accNum, bal, name), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount > (balance + overdraftLimit)) {
            cout << "Overdraft limit exceeded! Cannot withdraw $" << amount << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully. New Balance: $" << balance << endl;
        }
    }

    void calculateInterest() override {
        cout << "Checking accounts do not earn interest." << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(int accNum, double bal, string name, string maturity, double intRate)
        : Account(accNum, bal, name), maturityDate(maturity), fixedInterestRate(intRate) {}

    void calculateInterest() override {
        double interest = (balance * fixedInterestRate) / 100;
        cout << "Fixed Deposit Interest Amount: $" << interest << " (will be available on " << maturityDate << ")\n";
    }

    void withdraw(double amount) override {
        cout << "Withdrawals are not allowed before maturity date: " << maturityDate << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%\n";
    }
};

int main() {
    cout << "***** Banking System Simulation (Using Runtime Polymorphism & DMA) *****\n\n";

    Account* accounts[3];
    accounts[0] = new SavingsAccount(1001, 5000, "Alice", 4.0, 1000);
    accounts[1] = new CheckingAccount(1002, 2000, "Bob", 500);
    accounts[2] = new FixedDepositAccount(1003, 10000, "Charlie", "31-12-2025", 5.5);

    cout << "\n--- Depositing Money ---\n";
    for (int i = 0; i < 3; i++) {
        accounts[i]->deposit(1000);
    }

    cout << "\n--- Withdrawing Money ---\n";
    accounts[0]->withdraw(4500);
    accounts[1]->withdraw(2500);
    accounts[2]->withdraw(5000);

    cout << "\n--- Calculating Interest ---\n";
    for (int i = 0; i < 3; i++) {
        accounts[i]->calculateInterest();
    }

    cout << "\n--- Account Statements ---\n";
    for (int i = 0; i < 3; i++) {
        accounts[i]->printStatement();
    }

    for (int i = 0; i < 3; i++) {
        delete accounts[i];
    }

    return 0;
}
