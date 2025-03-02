/*Task 3: Library System (Composition for Catalog, Aggregation for Books)
Description (Multi-Class Project)
Design a mini library system that contains a Catalog and Library, where:
1. Catalog (composition)
o The Library has exactly one Catalog object that is integral to its function.
o The Catalog might store or manage indexes for quick search (like a map of
ISBN -&gt; Book location).

2. Book
o Stored externally (on the heap or as a shared resource).
o Each Book can belong to multiple libraries, or at least can be “loaned”
between them.

3. Library
o Has-a Catalog catalog; (composition).
o Also has-a collection of Book* or std::shared_ptr&lt;Book&gt; (aggregation) to
represent the books it currently owns or references.
o Provide functions like addBook(...), removeBook(...),
findBookInCatalog(isbn).
o Possibly store the library’s address, name, etc.
4. Demonstrate usage in main():
o Create a Library object.
o Create some Book objects, add them to the library.
o Show that the library’s Catalog is automatically constructed inside the
Library.
o Searching the catalog for a book by ISBN, etc.

Key Points
 Hybrid approach:
o The Library is composed of exactly one Catalog.
o The Library aggregates multiple Book objects, each possibly existing
outside the Library.*/

#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << '\n';
    }
};

class Catalog {
private:
    vector<Book*> books;
public:
    void addBook(Book* book) {
        books.push_back(book);
    }
    void removeBook(const string& isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i]->isbn == isbn) {
                books.erase(books.begin() + i);
                break;
            }
        }
    }
    Book* findBook(const string& isbn) {
        for (Book* book : books) {
            if (book->isbn == isbn) {
                return book;
            }
        }
        return nullptr;
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;
    vector<Book*> books;

public:
    Library(string n, string addr) : name(n), address(addr) {}
    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book);
    }
    void removeBook(const string& isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i]->isbn == isbn) {
                books.erase(books.begin() + i);
                break;
            }
        }
        catalog.removeBook(isbn);
    }
    void findBookInCatalog(const string& isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            cout << "Book found in catalog: ";
            book->display();
        } else {
            cout << "Book not found in catalog.\n";
        }
    }
    void displayBooks() {
        cout << "Library: " << name << " (" << address << ")\nBooks:\n";
        for (Book* book : books) book->display();
    }
};

int main() {
    Library lib("Central Library", "123 Library St.");

    Book book1("The C++ Programming Language", "Bjarne Stroustrup", "123456789");
    Book book2("Effective Modern C++", "Scott Meyers", "987654321");

    lib.addBook(&book1);
    lib.addBook(&book2);

    lib.displayBooks();
    lib.findBookInCatalog("123456789");
    lib.findBookInCatalog("000000000");

    lib.removeBook("123456789");
    lib.displayBooks();
    
    return 0;
}
