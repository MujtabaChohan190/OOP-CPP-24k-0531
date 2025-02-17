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
#include <string>
using namespace std;

class MenuItem {
  public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) {
        name = n;
        type = t;
        price = p;
    }
};

class CoffeeShop {
  private:
    string name;
    MenuItem* menu;
    string orders[10];
    int orderCount;
    int menuSize;

  public:
    CoffeeShop(string shopName, MenuItem menuItems[], int mSize) {
        name = shopName;
        menu = menuItems;
        menuSize = mSize;
        orderCount = 0;
    }

    void addOrder(string itemName) {
        bool found = false;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                orders[orderCount++] = itemName;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "This item is currently unavailable" << endl;
        }
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders yet" << endl;
        } else {
            for (int i = 0; i < orderCount; i++) {
                cout << orders[i] << endl;
            }
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = menu[0].price;
        string itemName = menu[0].name;
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < minPrice) {
                minPrice = menu[i].price;
                itemName = menu[i].name;
            }
        }
        return itemName;
    }

    void drinksOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << endl;
            }
        }
    }

    void foodOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << endl;
            }
        }
    }
};

int main() {
    MenuItem menu[] = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Tea", "drink", 1.5),
        MenuItem("Cake", "food", 3.0),
        MenuItem("Sandwich", "food", 4.0),
        MenuItem("Juice", "drink", 2.0)
    };

    CoffeeShop shop("Best Coffee", menu, 5);
    shop.addOrder("Coffee");
    shop.addOrder("Sandwich");
    shop.addOrder("Juice");
    shop.addOrder("Burger");

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    shop.listOrders();
    cout << "Total due: " << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    cout << "Drinks menu:" << endl;
    shop.drinksOnly();
    cout << "Food menu:" << endl;
    shop.foodOnly();

    return 0;
}
