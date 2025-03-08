#include <iostream>
#include <vector>
using namespace std;

// Base Class
class Book {
protected:
    string genre;
public:
    Book(string genre) : genre(genre) {}
    virtual void display() const = 0;  // Pure virtual function for displaying book details becuase the functionality needs to be modified in each derived class.
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
    vector<Book*> library;

    // Adding books dynamically
    library.push_back(new FictionBook("Rich dad poor dad", "F. Scott Fitzgerald"));
    library.push_back(new ScienceBook("A Brief History of Time", "Stephen Hawking"));

    cout << "\n=== Library Book Details ===\n";
    for (Book* book : library) {
        book->display();  // Dynamic dispatch
    }

    for (Book* book : library) {  
        delete book;
    }

    return 0;
}
