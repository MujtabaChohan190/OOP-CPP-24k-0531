#include <iostream>
using namespace std;


class Student {
protected:
    string name;
    int rollNo;
    string department;
public:
    Student(string n, int r, string dept) : name(n), rollNo(r), department(dept) {}
    
    void displayStudentDetails() {
        cout << "=== Student Details ===\n";
        cout << "Name: " << name << "\nRoll No: " << rollNo << "\nDepartment: " << department << endl;
    }
};

class Marks : public Student {
protected:
    int subject1, subject2, subject3;
public:
    Marks(string n, int r, string dept, int m1, int m2, int m3) 
        : Student(n, r, dept), subject1(m1), subject2(m2), subject3(m3) {}
    
    void displayMarks() {
        cout << "\n=== Marks Obtained ===\n";
        cout << "Subject 1: " << subject1 << "\nSubject 2: " << subject2 << "\nSubject 3: " << subject3 << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int r, string dept, int m1, int m2, int m3) 
        : Marks(n, r, dept, m1, m2, m3) {}

    void displayResult() {
        int total = subject1 + subject2 + subject3;
        float average = total / 3.0;

        cout << "\n=== Result ===\n";
        cout << "Total Marks: " << total << "\nAverage Marks: " << average << endl;
    }
};

int main() {
    // Creating an object of Result class
    Result student1("John Doe", 101, "Computer Science", 85, 90, 80);
    
    student1.displayStudentDetails();
    student1.displayMarks();
    student1.displayResult();

    return 0;
}
