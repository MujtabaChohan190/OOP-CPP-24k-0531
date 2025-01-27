/*6. Write a program that reads a student name followed by five test scores. The program should output the
student’s name, the five test scores, and the average test score. Output the average test score with two
decimal places.
Input:
Andrew Miller 87.50 89 65.75 37 98.50
Output:
Student name: Andrew Miller
Test scores: 87.50 89.00 65.75 37.00 98.50
Average test score: 75.55*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string studentName;
    float testScores[5];
    float sum = 0, average;

    // Read the student name
    cout << "Enter student name: ";
    getline(cin, studentName);

    // Read the five test scores
    cout << "Enter five test scores: ";
    for (int i = 0; i < 5; i++) {
        cin >> testScores[i];
        sum += testScores[i];  // Calculate the sum of the scores
    }

    average = sum / 5;

    cout << "Student name: " << studentName << endl;
    cout << "Test scores: ";
    for (int i = 0; i < 5; i++) {
        cout << fixed << setprecision(2) << testScores[i] << " ";  // Print each score with two decimal places
    }
    cout << endl;

    cout << "Average test score: " << fixed << setprecision(2) << average << endl;

    return 0;
}
