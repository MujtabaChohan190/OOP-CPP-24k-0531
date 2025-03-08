#include <iostream>
using namespace std;

// Base Class
class Book {
protected:
    string genre;
public:
    Book(string genre) : genre(genre) {}
    virtual void display() const = 0;  // Pure virtual function for displaying book details
    virtual ~Book() {}
};

// Derived Class: Fiction Books
class FictionBook : public Book {
private:
    string title, author;
public:
    FictionBook(string title, string author) : Book("Fiction"), title(title), author(author) {}
    void display() const override {
        cout << "Genre: " << genre << ", Title: " << title << ", Author: " << author << endl;
    }
};

// Derived Class: Science Books
class ScienceBook : public Book {
private:
    string title, author;
public:
    ScienceBook(string title, string author) : Book("Science"), title(title), author(author) {}
    void display() const override {
        cout << "Genre: " << genre << ", Title: " << title << ", Author: " << author << endl;
    }
};

// Main Function demonstrating Polymorphism
int main() {
    // Dynamic array of books
    Book* library[] = {
        new FictionBook("The Great Gatsby", "F. Scott Fitzgerald"),
        new ScienceBook("A Brief History of Time", "Stephen Hawking")
    };

    cout << "\n=== Library Book Details ===\n";
    for (int i = 0; i < 2; i++) {
        library[i]->display();  // Dynamic dispatch
    }

    // Cleanup
    for (int i = 0; i < 2; i++) {
        delete library[i];
    }

    return 0;
}
