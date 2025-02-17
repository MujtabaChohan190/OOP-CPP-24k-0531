/*Task - 02:
Create an Account class that a bank might use to represent customers bank accounts. Include a data member to
represent the account balance. Provide three member functions. Member function credit should add an amount
to the current balance. Member function debits should withdraw money from the Account. Member function get
Balance should return the current balance.*/

#include <iostream>
#include<iomanip>
using namespace std;

class Account {
    double balance;

public:
    double credit(double amount) {
        balance += amount;
        return balance;
    }

    double debit(double withdraw) {
        if (withdraw > balance) {
            cout << "Invalid Amount" << endl;
            return balance;
        }
        balance -= withdraw;
        return balance;
    }

    void setbalance(double amount) {
        balance = amount;
    }

    double getbalance() {
        return balance;
    }
};

int main() {
    Account customer;
    customer.setbalance(1000000);
    int option;

    while (true) {
        cout << "====BANK DETAILS====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Add Amount" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Option: ";
        cin >> option;

        if (option == 4) break;

        switch (option) {
            case 1: {
                double balance = customer.getbalance();
                cout<<fixed<<setprecision(2);
                cout << "Current Balance: " << balance << endl;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to Credit: ";
                cin >> amount;
                double balance = customer.getbalance();
                cout<<fixed<<setprecision(2);
                cout << "Balance Before: " << balance << endl;
                customer.credit(amount);
                balance = customer.getbalance();
                cout << "Current Balance: " << balance << endl;
                break;
            }
            case 3: {
                double debit;
                cout << "Enter Amount to Debit: ";
                cin >> debit;
                double balance = customer.getbalance();
                cout<<fixed<<setprecision(2);
                cout << "Balance Before: " << balance << endl;
                balance = customer.debit(debit);
                cout << "Current Balance: " << balance << endl;
                break;
            }
            default:
                cout << "Invalid Option" << endl;
        }
    }
    return 0;
}
