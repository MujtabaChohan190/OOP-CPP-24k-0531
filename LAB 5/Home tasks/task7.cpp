#include <iostream>
using namespace std;
class Student {
private:
    const int rollNo;
public:
    Student(int roll) : rollNo(roll) {}
    void display() const {
        cout << "Student Roll No: " <<rollNo<< endl;
    }
};
int main() {
    int roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;
    Student s(roll);
    s.display();
    return 0;
}
