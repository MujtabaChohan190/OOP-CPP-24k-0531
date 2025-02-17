/*Task - 04:
A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as
author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the
title and author and the system searches the list and displays whether it is available or not. If it is not, an
appropriate message is displayed. If it is, then the system displays the book details and requests for the number
of copies required. If the requested copies are available, the total cost of the requested copies is displayed;
otherwise “Required copies not in stock” is displayed. Design a system using a class called books with suitable
member functions and constructors.*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
    string title, author, publisher;
    double price;
    int stock;

    string toLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    Book(string t, string a, string p, double pr, int s) : title(t), author(a), publisher(p), price(pr), stock(s) {}

    bool isAvailable(string t, string a) {
        return (toLower(title) == toLower(t) && toLower(author) == toLower(a));
    }

    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << " copies" << endl;
    }

    void sellBook(int copies) {
        if (copies <= stock) {
            cout << "Total Cost: $" << copies * price << endl;
            stock -= copies;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main() {
    vector<Book> inventory = {
        Book("C++ Programming", "Bjarne Stroustrup", "Pearson", 49.99, 10),
        Book("The Art of Computer Programming", "Donald Knuth", "Addison-Wesley", 99.99, 5),
        Book("Clean Code", "Robert C. Martin", "Prentice Hall", 39.99, 7)
    };

    string title, author;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);

    bool found = false;
    for (Book &b : inventory) {
        if (b.isAvailable(title, author)) {
            found = true;
            b.displayDetails();
            int copies;
            cout << "Enter number of copies required: ";
            cin >> copies;
            b.sellBook(copies);
            break;
        }
    }

    if (!found) {
        cout << "Book not available" << endl;
    }

    return 0;
}
