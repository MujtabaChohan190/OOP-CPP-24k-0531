#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool available;

public:
    // Constructor to set book details
    Book(int id, string t, string a, bool avail) {
        bookID = id;
        title = t;
        author = a;
        available = avail;
    }

    // Display book details
    void display() {
        cout << "Book ID: " << bookID << "\nTitle: " << title << "\nAuthor: " << author << "\nAvailability: ";
        if (available) {
            cout << "Available";
        } else {
            cout << "Checked Out";
        }
        cout << "\n\n";
    }

    // Get book ID
    int getID() {
        return bookID;
    }

    // Toggle availability status
    void toggleAvailability() {
        available = !available;
    }
};

class Library {
private:
    vector<Book*> books;

public:
    Library() {}

    // Add a book to the library
    void addBook(int id, string title, string author, bool avail) {
        books.push_back(new Book(id, title, author, avail));
    }

    // Display all books
    void displayAllBooks() {
        for (auto book : books) {
            book->display();
        }
    }

    // Find a book by ID
    Book* findBook(int id) {
        for (auto book : books) {
            if (book->getID() == id) {
                return book;
            }
        }
        return nullptr;
    }

    // Destructor to free allocated memory
    ~Library() {
        for (auto book : books) {
            delete book;
        }
    }
};

int main() {
    Library lib;

    // Adding books
    lib.addBook(201, "Clean Code", "Robert C. Martin", true);
    lib.addBook(202, "The Pragmatic Programmer", "Andrew Hunt & David Thomas", true);
    lib.addBook(203, "Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", true);

    // Display catalog
    cout << "Library Catalog:\n";
    lib.displayAllBooks();

    // Search for a book
    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    Book* foundBook = lib.findBook(searchID);
    if (foundBook) {
        cout << "Book found:\n";
        foundBook->display();

        // Toggle availability
        foundBook->toggleAvailability();
        cout << "Book is now checked out.\n\nUpdated Status:\n";
        foundBook->display();
    } else {
        cout << "Book not found!" << endl;
    }

    return 0;
}
