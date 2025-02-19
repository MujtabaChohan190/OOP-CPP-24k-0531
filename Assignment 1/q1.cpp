/*FAST has many sports enthusiasts, and to encourage their growth, the university wants to 
implement a mentorship program. In this program, mentors guide learners (students), but each 
mentor has a limited capacity to manage a fixed number of learners. The university sports 
mentorship system involves two main roles: mentors and learners (students).  
The Student class has data members such as studentID, name, age, sportsInterests[], and 
mentorAssigned. A student can register for mentorship under a mentor by calling the 
registerForMentorship(Mentor m) method. The student can also view the mentor’s details and 
update their sports interests through viewMentorDetails() and updateSportsInterest(Sport s) 
methods, respectively. 

The Mentor class, on the other hand, has data members like mentorID, name, sportsExpertise[], 
maxLearners, and assignedLearners[]. The maxLearners attribute specifies the maximum number 
of learners the mentor can handle. The mentor can assign learners using the assignLearner(Student 
s) method, as long as they have available capacity. If a learner needs to be removed, the 
removeLearner(Student s) method can be used. The mentor can also view their list of assigned 
learners by calling viewLearners() and provide guidance using the provideGuidance() method. 
The Sport class defines the sports offered for mentorship. It includes attributes like sportID, name, 
description, and requiredSkills[]. The mentor can add new skills required for a specific sport using 
the addSkill(Skill s) method, and they can also remove skills from the list using removeSkill(Skill 
s). 

The Skill class defines the various skills related to each sport, including data members like skillID, 
skillName, and description. This class provides methods such as showSkillDetails() to display the 
skill details and updateSkillDescription(String newDescription) to update a skill’s description. In 
this system, each mentor has a limited capacity to handle learners. For example, a mentor named 
Ali who specializes in Tennis can only mentor up to three students at a time. When a student like 
Saad, who is interested in Tennis, registers for mentorship, Ali can assign him as a mentee if there 
is space. If Ali already has three learners, Saad cannot be assigned until a slot becomes available. 
If Saad later decides to stop the mentorship, Ali can remove them, freeing up space for a new 
student. The system allows mentors to guide students on their sports skills, providing training and 
advice to improve their performance.*/



#include <iostream>
#include <vector>
using namespace std;

class Skill {
private:
    int skillID;
    string skillName;
    string description;

public:
    Skill(int id, string name, string desc) : skillID(id), skillName(name), description(desc) {}

    void showSkillDetails() {
        cout << "Skill ID: " << skillID << ", Name: " << skillName << ", Description: " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
        cout << "Skill description updated.\n";
    }

    int getSkillID() {
        return skillID;
    }
};

class Sport {
private:
    int sportID;
    string name;
    string description;
    vector<Skill> requiredSkills;

public:
    Sport(int id, string sportName, string desc) : sportID(id), name(sportName), description(desc) {}

    void addSkill(Skill s) {
        requiredSkills.push_back(s);
        cout << "Skill added to " << name << ".\n";
    }

    void removeSkill(int skillID) {
        for (size_t i = 0; i < requiredSkills.size(); i++) {
            if (requiredSkills[i].getSkillID() == skillID) {
                requiredSkills.erase(requiredSkills.begin() + i);
                cout << "Skill removed from " << name << ".\n";
                return;
            }
        }
        cout << "Skill not found in " << name << ".\n";
    }

    string getName() {  // Added getter method
        return name;
    }
};

class Mentor; // Forward declaration

class Student {
private:
    int studentID;
    string name;
    int age;
    vector<Sport> sportsInterests;
    Mentor* mentorAssigned;

public:
    Student(int id, string studentName, int studentAge) : studentID(id), name(studentName), age(studentAge), mentorAssigned(nullptr) {}

    void registerForMentorship(Mentor* m);

    void viewMentorDetails();

    void updateSportsInterest(Sport s) {
        sportsInterests.push_back(s);
        cout << name << " has added " << s.getName() << " to their interests.\n"; // Now s.getName() works
    }

    string getName() {
        return name;
    }
};

class Mentor {
private:
    int mentorID;
    string name;
    vector<string> sportsExpertise;
    int maxLearners;
    vector<Student*> assignedLearners;

public:
    Mentor(int id, string mentorName, vector<string> expertise, int capacity) 
        : mentorID(id), name(mentorName), sportsExpertise(expertise), maxLearners(capacity) {}

    bool assignLearner(Student* s) {
        if (assignedLearners.size() < maxLearners) {
            assignedLearners.push_back(s);
            return true;
        }
        return false;
    }

    void removeLearner(Student* s) {
        for (size_t i = 0; i < assignedLearners.size(); i++) {
            if (assignedLearners[i] == s) {
                assignedLearners.erase(assignedLearners.begin() + i);
                cout << s->getName() << " has been removed from " << name << "'s mentorship.\n";
                return;
            }
        }
        cout << "Student not found under " << name << "'s mentorship.\n";
    }

    void viewLearners() {
        cout << "Mentor " << name << "'s Students:\n";
        for (size_t i = 0; i < assignedLearners.size(); i++) { //assignedLearners is a vector<Student*>, meaning it stores pointers to Student objects.
            Student* s = assignedLearners[i]; // Get the pointer from the vector
            cout << "- " << s->getName() << endl;
        }        
    }


    void provideGuidance() {
        cout << name << " is providing guidance to students.\n";
    }

    string getName() {
        return name;
    }
};

void Student::registerForMentorship(Mentor* m) {
    if (m->assignLearner(this)) {
        mentorAssigned = m;
        cout << name << " has been assigned to mentor " << m->getName() << ".\n";
    } else {
        cout << "Mentor " << m->getName() << " has reached the maximum number of students.\n";
    }
}

void Student::viewMentorDetails() {
    if (mentorAssigned) {
        cout << "Mentor Name: " << mentorAssigned->getName() << endl;
    } else {
        cout << "No mentor assigned.\n";
    }
}

int main() {
    Sport tennis(1, "Tennis", "A sport played with a racket and ball.");
    Sport football(2, "Football", "A team sport played with a round ball.");

    Skill serve(1, "Serve", "Basic tennis serve technique.");
    Skill dribble(2, "Dribble", "Basic football dribbling skill.");

    tennis.addSkill(serve);
    football.addSkill(dribble);

    vector<string> tennisExpertise = {"Tennis"};
    Mentor mentorAli(101, "Ali", tennisExpertise, 3);

    Student saad(201, "Saad", 20);
    Student ahmed(202, "Ahmed", 21);
    Student zain(203, "Zain", 22);

    saad.registerForMentorship(&mentorAli);
    ahmed.registerForMentorship(&mentorAli);
    zain.registerForMentorship(&mentorAli);

    saad.viewMentorDetails();
    mentorAli.viewLearners();
    saad.updateSportsInterest(tennis);
    mentorAli.provideGuidance();
    mentorAli.removeLearner(&saad);
    mentorAli.viewLearners();

    return 0;
}
