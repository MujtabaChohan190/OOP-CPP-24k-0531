#include <iostream>
using namespace std;

const int MAX_PASTRIES = 10;

class Pastry {
protected:
    char name[50];
    char ingredients[100];
    double baseCost;
    double markup; // 10% markup
    double taxRate;
    static constexpr double gst = 0.06; // 6% GST
public:
    Pastry(const char* n = "", const char* ing = "", double cost = 0.0) {
        strcpy(name, n);
        strcpy(ingredients, ing);
        baseCost = cost;
        markup = 0.10 * baseCost;
    }

    virtual double calculateTotalCost() const {
        return baseCost + markup;
    }

    virtual double calculateRetailPrice() const = 0;
    virtual double calculateProfit() const = 0;
    virtual void display() const = 0;

    friend class PastryReport;
    friend double PastryCalculator(const Pastry* p);
};

class SweetPastry : public Pastry {
public:
    SweetPastry(const char* n = "", const char* ing = "", double cost = 0.0) : Pastry(n, ing, cost) {
        taxRate = 0.08;
    }

    double calculateRetailPrice() const override {
        double total = calculateTotalCost();
        return total + (total * (taxRate + gst));
    }

    double calculateProfit() const override {
        double retail = calculateRetailPrice();
        return 0.70 * (retail - calculateTotalCost());
    }

    void display() const override {
        cout << "Sweet Pastry: " << name << endl;
        cout << "Ingredients: " << ingredients << endl;
        cout << "Base Cost: " << baseCost << endl;
        cout << "Retail Price: " << calculateRetailPrice() << endl;
        cout << "Profit: " << calculateProfit() << endl << endl;
    }
};

class SavoryPastry : public Pastry {
public:
    SavoryPastry(const char* n = "", const char* ing = "", double cost = 0.0) : Pastry(n, ing, cost) {
        taxRate = 0.05;
    }

    double calculateRetailPrice() const override {
        double total = calculateTotalCost();
        return total + (total * (taxRate + gst));
    }

    double calculateProfit() const override {
        double retail = calculateRetailPrice();
        return 0.70 * (retail - calculateTotalCost());
    }

    void display() const override {
        cout << "Savory Pastry: " << name << endl;
        cout << "Ingredients: " << ingredients << endl;
        cout << "Base Cost: " << baseCost << endl;
        cout << "Retail Price: " << calculateRetailPrice() << endl;
        cout << "Profit: " << calculateProfit() << endl << endl;
    }
};

// Friend Function
double PastryCalculator(const Pastry* p) {
    return p->calculateRetailPrice();
}

// Friend Class
class PastryReport {
public:
    void generateReport(Pastry* pastries[], int count) {
        double totalProfit = 0;
        for (int i = 0; i < count; ++i) {
            pastries[i]->display();
            totalProfit += pastries[i]->calculateProfit();
        }
        cout << "Total Profit from all pastries: " << totalProfit << endl;
    }
};

// PastryShop Class
class PastryShop {
private:
    Pastry* pastries[MAX_PASTRIES];
    int count;
public:
    PastryShop() {
        count = 0;
    }

    void addPastry(Pastry* p) {
        if (count < MAX_PASTRIES) {
            pastries[count++] = p;
        } else {
            cout << "Pastry limit reached!" << endl;
        }
    }

    void calculateTotalProfit() {
        PastryReport report;
        report.generateReport(pastries, count);
    }

    ~PastryShop() {
        for (int i = 0; i < count; ++i) {
            delete pastries[i];
        }
    }
};

// Main Function
int main() {
    PastryShop shop;

    shop.addPastry(new SweetPastry("Chocolate Cake", "Flour, Eggs, Cocoa", 20));
    shop.addPastry(new SavoryPastry("Cheese Pie", "Cheese, Flour, Herbs", 15));
    shop.addPastry(new SweetPastry("Strawberry Tart", "Strawberries, Cream", 18));

    shop.calculateTotalProfit();

    return 0;
}
