#include <iostream>
#include <vector>
using namespace std;

struct MenuItem {
    string name;
    double price;
    string type;
};

class CoffeeShop {
private:
    const string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> shopMenu) : name(shopName), menu(shopMenu) {}

    string addOrder(string itemName) {
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i].name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string readyItem = orders[0];
            orders.erase(orders.begin());
            return "The " + readyItem + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (size_t i = 0; i < orders.size(); i++) {
            for (size_t j = 0; j < menu.size(); j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items available!";
        MenuItem cheapest = menu[0];
        for (size_t i = 1; i < menu.size(); i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i].type == "drink") {
                drinks.push_back(menu[i].name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i].type == "food") {
                foods.push_back(menu[i].name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"Coffee", 2.5, "drink"},
        {"Tea", 1.8, "drink"},
        {"Sandwich", 4.5, "food"},
        {"Muffin", 3.0, "food"},
        {"Juice", 3.2, "drink"}
    };

    CoffeeShop shop("Java Beans", menu);

    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Muffin") << endl;
    cout << shop.addOrder("Pizza") << endl;
    cout << shop.fulfillOrder() << endl;

    vector<string> currentOrders = shop.listOrders();
    cout << "Current Orders: ";
    for (size_t i = 0; i < currentOrders.size(); i++) {
        cout << currentOrders[i] << " ";
    }
    cout << endl;

    cout << "Total Due Amount: $" << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks: ";
    for (size_t i = 0; i < drinks.size(); i++) {
        cout << drinks[i] << " ";
    }
    cout << endl;

    vector<string> foods = shop.foodOnly();
    cout << "Food: ";
    for (size_t i = 0; i < foods.size(); i++) {
        cout << foods[i] << " ";
    }
    cout << endl;

    return 0;
}
