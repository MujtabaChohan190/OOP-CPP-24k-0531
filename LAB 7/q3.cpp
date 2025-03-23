#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    int currencyCode;
    string currencySymbol;
    double exchangeRate; // Exchange rate relative to a base currency (e.g., USD)

public:
    Currency(double amt, int curcode, string symb, double rate)
        : amount(amt), currencyCode(curcode), currencySymbol(symb), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual double convertTo(double targetExchangeRate) const {
        return convertToBase() / targetExchangeRate;
    }

    double getExchangeRate() const {
        return exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }

    virtual ~Currency() {}
};

// Derived Classes
class Dollar : public Currency {
public:
    Dollar(double amt)
        : Currency(amt, 840, "$", 1.0) {} 

    double convertToBase() const override {
        return amount; // USD is already the base currency
    }

    void displayCurrency() const override {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Euro : public Currency {
public:
    Euro(double amt)
        : Currency(amt, 978, "€", 0.91) {} // 1 USD = 0.91 EUR 

    double convertToBase() const override {
        return amount * exchangeRate; // Convert EUR to base currency (USD)
    }

    void displayCurrency() const override {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt)
        : Currency(amt, 356, "₹", 74.85) {} // 1 USD = 74.85 INR 

    double convertToBase() const override {
        return amount * exchangeRate; // Convert INR to base currency (USD)
    }

    void displayCurrency() const override {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

// Main Function
int main() {
    Dollar usd(100); // 100 USD
    Euro eur(0);     
    Rupee inr(0);    

    double convertedToEUR = usd.convertTo(eur.getExchangeRate());
    double convertedToINR = usd.convertTo(inr.getExchangeRate());

    cout << "100 USD to EUR: " << convertedToEUR << " EUR\n";
    cout << "100 USD to INR: " << convertedToINR << " INR\n";

    return 0;
}
