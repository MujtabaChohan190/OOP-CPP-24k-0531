/*Mark is a software developer working on a project to create a program that manages a library system. As part of the
project, he needs to implement a class to represent a book. The book class should have member variables to store the title,
author, publication year, and ISBN number. Mark wants to ensure that when a book object is created, the necessary
information is initialized properly. He also wants to implement a copy constructor to make it easier to create copies of
existing book objects.
Write a detailed C++ code snippet for the book class that includes a default constructor, a parameterized constructor, and a
copy constructor. Do provide an example scenario where Mark creates a new book object based on an existing book
object, modifies some attributes of the new book object, and verifies that the original book object remains unchanged.
Note: In the scenario, assume that Mark has a book with the following details: &quot;The Great Gatsby&quot; by F. Scott Fitzgerald,
published in 1925, with the ISBN number 9780743273565. Mark wants to create a copy of this book and change the title
of the new book to &quot;Pride and Prejudice&quot; by Jane Austen, while keeping the other attributes intact.*/

#include <iostream>
#include <string>

using namespace std;

// 📚 Book Class Definition
class Book {
private:
    string title;
    string author;
    int publicationYear;
    string isbn;

public:
    // ✅ Default Constructor
    Book() : title("Unknown"), author("Unknown"), publicationYear(0), isbn("N/A") {}

    // ✅ Parameterized Constructor
    Book(string t, string a, int year, string i) 
        : title(t), author(a), publicationYear(year), isbn(i) {}

    // ✅ Copy Constructor
    Book(const Book& other) {
        title = other.title;
        author = other.author;
        publicationYear = other.publicationYear;
        isbn = other.isbn;
        cout << "📖 Copy Constructor Called: Copying book '" << title << "'\n";
    }

    // ✅ Function to modify book details
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }

    // ✅ Function to display book details
    void displayBook() const {
        cout << "📘 Title: " << title << "\n";
        cout << "✍️  Author: " << author << "\n";
        cout << "📅 Year: " << publicationYear << "\n";
        cout << "🔖 ISBN: " << isbn << "\n";
        cout << "----------------------\n";
    }
};

// 📌 **Main Function (Demonstration)**
int main() {
    // 🎓 Mark creates an original book
    Book originalBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, "9780743273565");
    
    // 📢 Display Original Book
    cout << "📌 Original Book:\n";
    originalBook.displayBook();

    // 📝 Mark creates a copy of the original book
    Book copiedBook = originalBook; // Copy constructor is invoked

    // ✏ Mark modifies the copied book's title and author
    copiedBook.setTitle("Pride and Prejudice");
    copiedBook.setAuthor("Jane Austen");

    // 🔍 Verify that the original book remains unchanged
    cout << "✅ Modified Copied Book:\n";
    copiedBook.displayBook();

    cout << "🔄 Original Book After Copying (Should be Unchanged):\n";
    originalBook.displayBook();

    return 0;
}
