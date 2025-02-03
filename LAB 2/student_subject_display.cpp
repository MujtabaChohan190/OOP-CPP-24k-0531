/*Task 6:
Write a program that creates a dynamic array of not values but structures. Each struct would contain
another struct and in that struct a variable of subject should exist. The outer structure should be an ID
and an array (Fixed) for subjects. (Note you can utilize vectors for this question)*/

#include <iostream>
#include <vector>
using namespace std;

struct Subject {
    string subjectName;
};

struct Student {
    int ID;
    vector<Subject> subjects;
};

int main() {
    Subject math = {"Mathematics"};
    Subject english = {"English"};
    Subject chemistry = {"Chemistry"};
    Subject programming = {"Programming Basics"};

    Student student1 = {101, {math, english}};
    Student student2 = {102, {chemistry, programming}};
    
    vector<Student> allStudents = {student1, student2};

    for (int i = 0; i < allStudents.size(); i++) {
        cout << "Student ID: " << allStudents[i].ID << endl;
        for (int j = 0; j < allStudents[i].subjects.size(); j++) {
            cout << "Subject " << j + 1 << ": " << allStudents[i].subjects[j].subjectName << endl;
        }
        cout << endl;
    }

    return 0;
}
