#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isAvailable;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isAvailable(true) {}

    virtual void displayInfo() {
        cout << "Title           : " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID       : " << uniqueID << endl;
        cout << "Publisher       : " << publisher << endl;
        cout << "Availability    : " << (isAvailable ? "Available" : "Checked Out") << endl;
    }

    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem() {
        if (!isAvailable) {
            isAvailable = true;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }
    string getUniqueID() { return uniqueID; }
    string getPublisher() { return publisher; }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author          : " << author << endl;
        cout << "ISBN            : " << ISBN << endl;
        cout << "Pages           : " << numberOfPages << endl;
    }

    string getAuthor() { return author; }
};

class DVD : public Media {
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director        : " << director << endl;
        cout << "Duration (min)  : " << duration << endl;
        cout << "Rating          : " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist          : " << artist << endl;
        cout << "Tracks          : " << numberOfTracks << endl;
        cout << "Genre           : " << genre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(string t, string pubDate, string id, string pub, int issue)
        : Media(t, pubDate, id, pub), issueNumber(issue) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number    : " << issueNumber << endl;
    }
};

class Library {
private:
    Media* mediaCollection[10];
    int mediaCount;

public:
    Library() : mediaCount(0) {}

    void addMedia(Media* m) {
        if (mediaCount < 10) {
            mediaCollection[mediaCount] = m;
            mediaCount++;
        } else {
            cout << "Library is full." << endl;
        }
    }

    void displayAll() {
        for (int i = 0; i < mediaCount; i++) {
            mediaCollection[i]->displayInfo();
            cout << "--------------------------" << endl;
        }
    }

    void searchByTitle(string t) {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getTitle() == t) {
                cout << "Media Found (Title):" << endl;
                mediaCollection[i]->displayInfo();
                return;
            }
        }
        cout << "Media not found by title: " << t << endl;
    }

    void searchByPublisher(string p) {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getPublisher() == p) {
                cout << "Media Found (Publisher):" << endl;
                mediaCollection[i]->displayInfo();
                return;
            }
        }
        cout << "Media not found by publisher: " << p << endl;
    }

    void searchByPublicationYear(string year) {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getPublicationDate() == year) {
                cout << "Media Found (Publication Year):" << endl;
                mediaCollection[i]->displayInfo();
                return;
            }
        }
        cout << "Media not found for publication year: " << year << endl;
    }
};

int main() {
    Library library;

    Book b1("C++ Programming", "2020", "B001", "TechPress", "Bjarne Stroustrup", "1234567890", 350);
    DVD d1("Inception", "2010", "D001", "WB", "Christopher Nolan", 148, "PG-13");
    CD c1("Thriller", "1982", "C001", "Epic", "Michael Jackson", 9, "Pop");
    Magazine m1("National Geographic", "2021", "M001", "NatGeo", 101);

    library.addMedia(&b1);
    library.addMedia(&d1);
    library.addMedia(&c1);
    library.addMedia(&m1);

    cout << "=== All Media ===" << endl;
    library.displayAll();

    cout << "=== Search by Title ===" << endl;
    library.searchByTitle("Inception");

    cout << "=== Search by Publisher ===" << endl;
    library.searchByPublisher("Epic");

    cout << "=== Search by Publication Year ===" << endl;
    library.searchByPublicationYear("2020");

    cout << "=== Check Out and Return ===" << endl;
    b1.checkOut();
    b1.checkOut();
    b1.returnItem();
    b1.returnItem();

    return 0;
}
