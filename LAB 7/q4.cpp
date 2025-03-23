#include <iostream>
#include <vector>
using namespace std;

// Forward declaration to break circular dependency
class Course;

// Base class: Person
class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
             << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }

    virtual void updateInfo(string newAddress, string newPhone, string newEmail) {
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }

    virtual ~Person() {}
};

// Derived class: Student
class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, int year, double gpa)
        : Person(n, i, a, p, e), enrollmentYear(year), GPA(gpa) {}

    void enrollInCourse(const string& courseName) {
        coursesEnrolled.push_back(courseName);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << "\nGPA: " << GPA << "\nCourses: ";
        for (const string& course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Derived class: Professor
class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string dept, double sal)
        : Person(n, i, a, p, e), department(dept), salary(sal) {}

    void assignCourse(const string& courseName) {
        coursesTaught.push_back(courseName);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (const string& course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Derived class: Staff
class Staff : public Person {
private:
    string department;
    string position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string dept, string pos, double sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << endl;
    }
};

// Class: Course
class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    Course(string id, string name, int cred, string instr, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}

    void registerStudent(Student& student) {
        student.enrollInCourse(courseName);
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << endl;
    }
};

// Main function
int main() {
    // Creating objects
    Student s1("Alice", "S123", "123 St", "123-456", "alice@email.com", 2022, 3.8);
    Professor p1("Dr. Smith", "P456", "456 St", "456-789", "smith@email.com", "CS", 75000);
    Staff st1("Mr. Johnson", "ST789", "789 St", "789-123", "johnson@email.com", "Admin", "Manager", 50000);
    Course c1("CS101", "Intro to CS", 3, "Dr. Smith", "MWF 9 AM");

    // Assign course to professor
    p1.assignCourse("Intro to CS");

    // Enroll student in the course
    c1.registerStudent(s1);

    // Display information
    cout << "\n--- Student Info ---\n";
    s1.displayInfo();
    
    cout << "\n--- Professor Info ---\n";
    p1.displayInfo();

    cout << "\n--- Staff Info ---\n";
    st1.displayInfo();

    cout << "\n--- Course Info ---\n";
    c1.displayCourseInfo();

    return 0;
}
