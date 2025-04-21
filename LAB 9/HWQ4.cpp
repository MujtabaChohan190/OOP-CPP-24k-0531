#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    double getTuition(string status, int creditHours) override {
        double tuition = 0.0;
        if (status == "undergraduate") {
            tuition = 200 * creditHours;
        }
        else if (status == "graduate") {
            tuition = 300 * creditHours;
        }
        else if (status == "doctoral") {
            tuition = 400 * creditHours;
        }
        return tuition;
    }

    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }
};

int main() {
    GraduateStudent gradStudent;
    gradStudent.setResearchTopic("Artificial Intelligence");

    string status;
    int creditHours;

    cout << "Enter student status (undergraduate, graduate, doctoral): ";
    cin >> status;
    cout << "Enter number of credit hours: ";
    cin >> creditHours;

    double tuition = gradStudent.getTuition(status, creditHours);

    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;
    cout << "Tuition for " << status << " student (" << creditHours << " credit hours): $" << tuition << endl;

    return 0;
}
