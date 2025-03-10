/*Suppose you are developing a software application to manage a library system. The system consists of several classes,
including Library, Book, and Member. The Library class represents a library and has a list of Book objects and a list of
Member objects. The Book class represents a book in the library and has attributes like title, author, and availability. The
Member class represents a library member and has attributes like name, ID, and a list of borrowed books.
a) Implement the Library class with appropriate data members and member functions to add books to the library, add
members to the library, and associate a book with a member when it is borrowed. 2 points

b) Implement the Book class with appropriate data members and member functions to track the availability of the book,
update the availability when it is borrowed or returned, and provide information about the book. 2 points
c) Implement the Member class with appropriate data members and member functions to borrow a book, return a book,
and provide information about the member&#39;s borrowed books. 2 points
d) Define an aggregation relationship between the Library and Book classes, where the Library class contains a collection
of Book objects. 3 points
e) Define a composition relationship between the Library and Member classes, where the Library class owns and manages
a collection of Member objects. 3 points
Now, consider the following scenario. The library system is set up with a Library object named &quot;Central Library.&quot; It has
two books registered: &quot;Introduction to Programming&quot; by John Smith and &quot;Data Structures and Algorithms&quot; by Jane Doe.
The library also has three members registered: John, Sarah, and Michael.
John wants to borrow &quot;Introduction to Programming&quot; from the library. Implement the necessary steps to associate the
book with John, update its availability, and display relevant information about the borrowed book and John&#39;s membership
status. Lastly, assume that Sarah and Michael also borrow books from the library. Calculate the total number of borrowed
books in the library and display the count. 8 points*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class (Aggregation with Library)
class Book {
private:
    string title;
    string author;
    bool isAvailable;

public:
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }

    void borrowBook() { isAvailable = false; }
    void returnBook() { isAvailable = true; }

    void displayInfo() const {
        cout << "Title: " << title << ", Author: " << author;
        cout << ", Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

// Member class (Composition with Library)
class Member {
private:
    string name;
    int id;
    vector<Book*> borrowedBooks;

public:
    Member(string n, int i) : name(n), id(i) {}

    string getName() const { return name; }
    int getID() const { return id; }

    void borrowBook(Book* book) {
        if (book->getAvailability()) {
            borrowedBooks.push_back(book);
            book->borrowBook();
            cout << name << " borrowed " << book->getTitle() << endl;
        } else {
            cout << "Book is already borrowed!\n";
        }
    }

    void returnBook(Book* book) {
        for (int i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i] == book) {
                book->returnBook();
                borrowedBooks.erase(borrowedBooks.begin() + i);
                cout << name << " returned " << book->getTitle() << endl;
                return;
            }
        }
        cout << "Book not found in borrowed list!\n";
    }

    void displayBorrowedBooks() const {
        cout << name << "'s Borrowed Books:\n";
        for (int i = 0; i < borrowedBooks.size(); i++) {
            cout << "- " << borrowedBooks[i]->getTitle() << endl;
        }
    }

    int getBorrowedCount() const { return borrowedBooks.size(); }
};

// Library class (Aggregation for Books, Composition for Members)
class Library {
private:
    string name;
    vector<Book*> books;
    vector<Member> members;

public:
    Library(string n) : name(n) {}

    void addBook(Book* book) {
        books.push_back(book);
    }

    void addMember(Member member) {
        members.push_back(member);
    }

    Book* findBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getTitle() == title) {
                return books[i];
            }
        }
        return nullptr;
    }

    Member* findMember(string name) {
        for (int i = 0; i < members.size(); i++) {
            if (members[i].getName() == name) {
                return &members[i];
            }
        }
        return nullptr;
    }

    int totalBorrowedBooks() {
        int count = 0;
        for (int i = 0; i < members.size(); i++) {
            count += members[i].getBorrowedCount();
        }
        return count;
    }

    void displayLibraryInfo() {
        cout << "Library: " << name << "\nBooks:\n";
        for (int i = 0; i < books.size(); i++) {
            books[i]->displayInfo();
        }
        cout << "Members:\n";
        for (int i = 0; i < members.size(); i++) {
            cout << members[i].getName() << " (ID: " << members[i].getID() << ")\n";
        }
    }
};

// Main function to test the implementation
int main() {
    // Create library
    Library centralLibrary("Central Library");

    // Create books
    Book book1("Introduction to Programming", "John Smith");
    Book book2("Data Structures and Algorithms", "Jane Doe");

    // Add books to library
    centralLibrary.addBook(&book1);
    centralLibrary.addBook(&book2);

    // Add members to library
    centralLibrary.addMember(Member("John", 101));
    centralLibrary.addMember(Member("Sarah", 102));
    centralLibrary.addMember(Member("Michael", 103));

    // Borrow books
    Member* john = centralLibrary.findMember("John");
    Book* bookToBorrow = centralLibrary.findBook("Introduction to Programming");

    if (john && bookToBorrow) {
        john->borrowBook(bookToBorrow);
    }

    // Borrow books for Sarah and Michael
    Member* sarah = centralLibrary.findMember("Sarah");
    Book* bookToBorrow2 = centralLibrary.findBook("Data Structures and Algorithms");

    if (sarah && bookToBorrow2) {
        sarah->borrowBook(bookToBorrow2);
    }

    // Display borrowed books and total borrowed count
    john->displayBorrowedBooks();
    sarah->displayBorrowedBooks();
    cout << "Total borrowed books in library: " << centralLibrary.totalBorrowedBooks() << endl;

    return 0;
}
