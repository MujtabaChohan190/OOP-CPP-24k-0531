/*Create a class called Book to represent a book. A Book should include four pieces of information as instance
variables‐a book name, an ISBN number, an author name and a publisher. Provide methods (query method) for
each instance variable. In addition, provide a method named getBookInfo that returns the description of the book
as a String (the description should include all the information about the book). You should use this keyword in
member methods and constructor. Write a test application named BookTest to create an array of object for 5
elements for class Book to demonstrate the class Book&#39;s capabilities.*/

#include<iostream>
#include<string>
using namespace std;

class Book {
    private:
        string Bookname;
        string ISBNno;  
        string Authorname;
        string Publisher;
    
    public:
        //Setter for book details
        void setBookDetails(string Bookname, string ISBNno, string Authorname, string Publisher) {
            this->Bookname = Bookname; //this-> pointer helps differentiate the class member variable from the function parameter when both have the same name.
            this->ISBNno = ISBNno;
            this->Authorname = Authorname;
            this->Publisher = Publisher;
        }
        //Getters
        string getBookname() {
            return this->Bookname;
        }
    
        string getISBNno() {  
            return this->ISBNno;
        }
    
        string getAuthorname() {
            return this->Authorname;
        }
    
        string getPublisher() {
            return this->Publisher;
        }

    // Method to return all book information as a string
    string getBookInfo() {
        return "Book Name: " + Bookname + 
               "\nISBN: " + ISBNno + 
               "\nAuthor: " + Authorname + 
               "\nPublisher: " + Publisher;
    }
    
};

// Test application named BookTest to demonstrate the Book class
void BookTest() {

    Book books[5];

    // Initializing  book details using the setter
    books[0].setBookDetails("Rich Dad Poor Dad", "90874562148", "Robert Kiyosaki", "123publishers");
    books[1].setBookDetails("King Henry V", "9457147852365", "William Shakespeare", "21stCEpublishers");
    books[2].setBookDetails("Lord of the Rings", "98564561238526", "J.R.R. Tolkien", "BestPublishers");
    books[3].setBookDetails("Harry Potter", "93442357864", "J.K. Rowling", "123publishers");
    books[4].setBookDetails("Diary of a Wimpy Kid", "97897539874", "Jeff Kinney", "xyzpublishers");

    for (int i = 0; i < 5; i++) {
        cout << books[i].getBookInfo() << endl<< endl;
    }
}

int main() {
    // Running  the test application
    BookTest();
    return 0;
}
