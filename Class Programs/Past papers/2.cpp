/*FAST University's library wants to automate its book management system. The librarian needs a program that allows them to maintain a small catalog of books, search for books by their unique ID, and update their availability when a book is borrowed or returned. As a developer, your task is to create a Library Management System using C++.

Your program should include a Book class that stores information about a book, including:

Book ID
Title
Author
Availability Status (available or checked out)
A Library class should manage books and provide functions to:

Add new books
Display all books
Search for a book by ID
Toggle availability when a book is borrowed or returned.
1. Define the Book class
Private members:

Book ID (a unique identifier for each book)
Title (the book's name)
Author (the author of the book)
Availability Status (a boolean indicating if the book is available)
Public methods:

Set book details: Assigns values to the book's attributes.
Display book details: Prints book information to the console.
Get Book ID: Returns the book's unique ID.
Toggle availability: Changes the book's status when borrowed or returned.
2. Define the Library class
Use an integer variable numBooks to track the number of books in the library.
Public methods:
addBook() → Adds a new book to the library (if space is available).
displayAllBooks() → Displays details of all books currently in the library.
findBook(int id) → Searches for a book by its ID.
Returns a pointer to the Book object if found.
3. In the main() function:
Create a Library object.
Add 3 books to the library.
Display the catalog of books.
Prompt the user to enter a Book ID to search.
If the book exists:
Display the book details.
Toggle availability (borrow the book).
Display the updated book details.
If the book does not exist, display an error message.
*/


#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool available;

public:
    // Constructor to set book details
    void setDetails(int id, string t, string a, bool avail) {
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
        available = !available; /*If available is true, !available becomes false, so available is set to false (Checked Out).
                                 If available is false, !available becomes true, so available is set to true (Available).*/
      /*if (available) {
    available = false; //when the book is availble , user takes it and then available is set to false  and vice versa for returned 
} else {
    available = true;
}
*/
      
    }
};

class Library {
private:
    Book books[10]; // Maximum 10 books - vector<Book*> we used  a fixed-size array as it was stated that space was limited , if i wnated flexibile memory , i could use vectors 
    int numBooks;

public:
    Library() { numBooks = 0; }

    // Add a book to the library
    void addBook(int id, string title, string author, bool avail) {
        if (numBooks < 10) {
            books[numBooks].setDetails(id, title, author, avail);
            numBooks++;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    // Display all books
    void displayAllBooks() {
        for (int i = 0; i < numBooks; i++) {
            books[i].display();
        }
    }

    // Find a book by ID - returns a pointer to book object if found 
    Book* findBook(int id) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].getID() == id) {
                return &books[i];
            }
        }
        return nullptr;
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
