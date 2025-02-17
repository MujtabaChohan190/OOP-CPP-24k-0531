/*Task - 05:
Write a class called CoffeeShop, which has three instance variables: 
Name: a string (basically, of the shop)
Menu: an array of items (of type MenuItem), with each item containing the item (name of the item), type
(whether a food or a drink) and price.
Orders: an empty array and seven methods:
addOrder: adds the name of the item to the end of the orders array if it exists on the menu. Otherwise, return
“This item is currently unavailable”
fulfillOrder: if the orders array is not empty, return “The {item} is ready” . If the orders array is empty, return
“All orders have been fulfilled”
listOrders: returns the list of orders taken, otherwise, an empty array.
dueAmount: returns the total amount due for the orders taken.
cheapestItem: returns the name of the cheapest item on the menu.
drinksOnly: returns only the item names of type drink from the menu.
foodOnly: returns only the item names of type food from the menu.*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class MenuItem {
public:
    string type_name;
    string itemType;
    double price;

    MenuItem(string name, string type, double price) : type_name(name), itemType(type), price(price) {}
};

class CoffeeShop {
    string Shopname;
    vector<MenuItem> menu;
    vector<string> Order;

public:
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
    CoffeeShop(string name) : Shopname(name) {}

    void addMenuItem(string name, string type, double price) {
        menu.push_back(MenuItem(name, type, price));
    }

    void addOrder(string item) {
        bool found = false;
        for (auto &menuItem : menu) {
            if (toLowerCase(menuItem.type_name) == toLowerCase(item)) {
                Order.push_back(item);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "This item is currently unavailable" << endl;
        }
    }

    string fullfillorder() {
        if (!Order.empty()) {
            string item = Order.front();
            Order.erase(Order.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return Order;
    }

    double dueamount() {
        double total = 0;
        for (int i = 0; i < Order.size(); i++) {
            for (int j = 0; j < menu.size(); j++) {
                if (toLowerCase(Order[i]) == toLowerCase(menu[j].type_name)) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double cheapestPrice = menu[0].price;
        int cheapestIndex = 0;
        for (int i = 1; i < menu.size(); i++) {
            if (menu[i].price < cheapestPrice) {
                cheapestPrice = menu[i].price;
                cheapestIndex = i;
            }
        }
        return menu[cheapestIndex].type_name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].itemType == "drink") {
                drinks.push_back(menu[i].type_name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].itemType == "food") {
                food.push_back(menu[i].type_name);
            }
        }
        return food;
    }

    void displayMenu() {
        cout << "=== MENU ===\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << menu[i].type_name << " (" << menu[i].itemType << ") - $ " << menu[i].price << endl;
        }
    }
};

int main() {
    CoffeeShop shop("Cafe Java");
    shop.addMenuItem("Latte", "drink", 4.50);
    shop.addMenuItem("Espresso", "drink", 3.00);
    shop.addMenuItem("Sandwich", "food", 5.00);
    shop.addMenuItem("Cake", "food", 3.50);

    shop.displayMenu();

    string item;
    char choice;
    do {
        cout << "Enter item to order: ";
        cin >> item;
        shop.addOrder(item);
        cout << "Do you want to add another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    vector<string> orders = shop.listOrders();
    cout << "\nOrders: ";
    for (int i = 0; i < orders.size(); i++) {
        cout << orders[i] << " ";
    }
    cout << endl;

    cout << shop.fullfillorder() << endl;
    cout << "Total due amount: $" << shop.dueamount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks only: ";
    for (int i = 0; i < drinks.size(); i++) {
        cout << drinks[i] << " ";
    }
    cout << endl;

    vector<string> food = shop.foodOnly();
    cout << "Food only: ";
    for (int i = 0; i < food.size(); i++) {
        cout << food[i] << " ";
    }
    cout << endl;

    return 0;
}
