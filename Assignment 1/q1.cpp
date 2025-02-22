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
    Skill** requiredSkills; 
    // Pointer to an array of Skill pointers - using skill* requiredskills would mean that reqskills is a pointer to a single skill object not an array

public:
    Sport(int id, string sportName, string desc) : sportID(id), name(sportName), description(desc) {
    requiredSkills = new Skill*[10];// Allocating space for 10 skills pointers - here we are allocating memory for an array of pointers to skill object
    for (int i = 0; i < 10; i++) requiredSkills[i] = nullptr;

    }

    
    ~Sport() {
        delete[] requiredSkills; //Destructor is essentially if you dynamically allocated the memory
    }
    
    void addSkill(Skill* s) {  //the parameter  skill* s is a pointer to skill object . this means that when calling the function we are passing the address of the skill object instead of copying the entire object 
        for (int i = 0; i < 10; i++) { 
            if (requiredSkills[i] == nullptr) { 
                requiredSkills[i] = s; //since requiredarray element  is empty , we assign the address of skill object to requiredskill element 
                cout << "Skill added to " << name << ".\n";
                return;
            }
        }
        cout << "No space to add more skills to " << name << ".\n";
    }

    void removeSkill(Skill* skillPtr) {
        for (int i = 0; i < 10; i++) {
            if (requiredSkills[i] == skillPtr) { // Compare addresses directly
                requiredSkills[i] = nullptr;
                cout << "Skill removed from " << name << ".\n";
                return;
            }
        }
        cout << "Skill not found in " << name << ".\n";
    }

    string getName() {
        return name;
    }
};

//Mentor and student class functions are dependent on each other so there is circular dependency , hence we use forward declaration.
class Mentor; // Forward declaration - Declares Mentor before Student because Student references Mentor

class Student {
private:
    int studentID;
    string name;
    int age;
    Sport** sportsInterests;  // Pointer to an array of sport pointers - it represents multiple sports student is interested in
    Mentor* mentorAssigned;   // Pointer to assigned Mentor -  it represents a single mentor assigned to a student

public:
    Student(int id, string studentName, int studentAge) : studentID(id), name(studentName), age(studentAge), mentorAssigned(nullptr) {
        sportsInterests = new Sport*[10]; 
        for (int i = 0; i < 10; i++) sportsInterests[i] = nullptr;
    }

    ~Student() {
        delete[] sportsInterests;
    }

    void registerForMentorship(Mentor* m);

    void viewMentorDetails();

    void updateSportsInterest(Sport* s) {
        for (int i = 0; i < 10; i++) {
            if (sportsInterests[i] == nullptr) {
                sportsInterests[i] = s;
                cout << name << " has added " << s->getName() << " to their interests.\n";
                return; // it helps to exit the function , otherwise the function will contiue executing even after a particular sport is added for student
            }
        }
        cout << name << " cannot add more sports.\n";
    }

    string getName() {
        return name;
    }
};

class Mentor {
private:
    int mentorID;
    string name;
    string* sportsExpertise;
    int expertiseCount;
    int maxLearners;
    Student** assignedLearners;

public:
    Mentor(int id, string mentorName, string expertise[], int expertiseSize, int capacity) 
        : mentorID(id), name(mentorName), maxLearners(capacity) {
        sportsExpertise = new string[expertiseSize];
        expertiseCount = expertiseSize;
        for (int i = 0; i < expertiseSize; i++) {
            sportsExpertise[i] = expertise[i];
        }
        assignedLearners = new Student*[maxLearners];
        for (int i = 0; i < maxLearners; i++) assignedLearners[i] = nullptr;
    }

    ~Mentor() {
        delete[] sportsExpertise;
        delete[] assignedLearners;
    }

    bool assignLearner(Student* s) {
        for (int i = 0; i < maxLearners; i++) {
            if (assignedLearners[i] == nullptr) {
                assignedLearners[i] = s;
                return true;
            }
        }
        return false;
    }

    void removeLearner(Student* s) {
        for (int i = 0; i < maxLearners; i++) {
            if (assignedLearners[i] == s) {
                assignedLearners[i] = nullptr;
                cout << s->getName() << " has been removed from " << name << "'s mentorship.\n";
                return;
            }
        }
        cout << "Student not found under " << name << "'s mentorship.\n";
    }

    void viewLearners() {
        cout << "Mentor " << name << "'s Students:\n";
        for (int i = 0; i < maxLearners; i++) {
            if (assignedLearners[i] != nullptr) {
                cout << "- " << assignedLearners[i]->getName() << endl;
            }
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
    // assigning the student to the mentor
    bool isAssigned = m->assignLearner(this);  
    
    // If the mentor is full, print a message and return
    if (!isAssigned) {  
        cout << "Mentor " << m->getName() << " is full.\n";  
        return;  
    }

    // Otherwise, assign the mentor to the student
    mentorAssigned = m;
    cout << name << " is now mentored by " << m->getName() << ".\n";
}

void Student::viewMentorDetails() {
    if (mentorAssigned) { //mentorAssigned is a pointer to a Mentor object. it checks if pointer is not nullptr thus ensuring that if mentor is assigned 
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

    tennis.addSkill(&serve);
    football.addSkill(&dribble);

    string tennisExpertise[] = {"Tennis"};
    Mentor mentorAli(101, "Ali", tennisExpertise, 1, 3);

    Student saad(201, "Saad", 20);
    Student ahmed(202, "Ahmed", 21);
    Student zain(203, "Zain", 22);

    saad.registerForMentorship(&mentorAli);
    ahmed.registerForMentorship(&mentorAli);
    zain.registerForMentorship(&mentorAli);

    saad.viewMentorDetails();
    mentorAli.viewLearners();
    saad.updateSportsInterest(&tennis);
    mentorAli.provideGuidance();
    mentorAli.removeLearner(&saad);
    mentorAli.viewLearners();

    return 0;
}

