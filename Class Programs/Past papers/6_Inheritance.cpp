/*Sophie is developing a software application that simulates a university&#39;s administrative system. The application involves
managing different types of employees, including staff members and faculty members. Sophie wants to implement a class
hierarchy that includes a base class called &quot;Employee,&quot; a derived class called &quot;Staff,&quot; and another derived class called
&quot;Faculty.&quot; She also wants to utilize static and constant functions and variables within the classes to track employee
information efficiently and prevent accidental modifications.
Your job is to demonstrate and implement the use of multi-level inheritance by defining the classes &quot;Employee,&quot; &quot;Staff,&quot;
and &quot;Faculty.&quot; 2 points
In the university&#39;s administrative system, employees have a unique ID, a name, and a salary. The base class &quot;Employee&quot;
should have member functions to display the employee&#39;s details and a constant function to calculate the bonus based on
the salary. 6 points
The derived class &quot;Staff&quot; should have a static variable to keep track of the total number of staff members and a static
function to display this count. 4 points
The derived class &quot;Faculty&quot; should have a constant variable to represent the maximum number of courses a faculty
member can teach. 2 points
Within the classes, implement static and constant functions and variables as appropriate. Additionally, provide an example
scenario where Sophie creates objects of each class, calls their member functions (including static and constant functions),
and accesses their member variables. 6 points*/



#include <iostream>
#include <string>

using namespace std;

// Base Class: Character
class Character {
protected:
    string name;
    int health;
    int attackPower;

public:
    Character(string n, int hp, int ap) : name(n), health(hp), attackPower(ap) {}

    // Constant function to calculate total damage dealt
    int calculateDamage() const {
        return attackPower * 2;  // Example calculation
    }

    // New function: Switch character
    void switchCharacter(string newName) {
        name = newName;
        cout << "Character switched to " << name << endl;
    }

    // Static function to show character type
    static void showCharacterType() {
        cout << "Character Type: Base Character\n";
    }

    // Display character stats
    void displayStats() const {
        cout << "Name: " << name << ", HP: " << health << ", AP: " << attackPower << endl;
    }
};

// Derived Class: Player (Inherits from Character)
class Player : public Character {
private:
    string weapon;

public:
    // Static variable to track number of players
    static int playerCount;

    Player(string n, int hp, int ap, string w) : Character(n, hp, ap), weapon(w) {
        playerCount++; // Increase player count when a new player is created
    }

    // Static function to display player count
    static void displayPlayerCount() {
        cout << "Total Players: " << playerCount << endl;
    }

    // Player-specific functions
    void switchWeapon(string newWeapon) {
        weapon = newWeapon;
        cout << name << " switched weapon to " << weapon << endl;
    }

    void healthRegen() {
        health += 10;
        cout << name << " regenerated health. New HP: " << health << endl;
    }

    void move() const {
        cout << name << " is moving...\n";
    }
};

// Initialize static variable
int Player::playerCount = 0;

// Derived Class: Enemy (Inherits from Character)
class Enemy : public Character {
public:
    // Constant variable: Maximum enemy health
    static const int MAX_ENEMY_HP = 150;

    Enemy(string n, int hp, int ap) : Character(n, hp, ap) {
        if (health > MAX_ENEMY_HP) {
            health = MAX_ENEMY_HP; // Ensure enemy health doesn't exceed the max
        }
    }

    // Enemy-specific functions
    void attack() const {
        cout << name << " attacks with " << attackPower << " AP!\n";
    }

    void specialAttack() const {
        cout << name << " performs a special attack with " << attackPower * 2 << " AP!\n";
    }

    void healthRegen() {
        health += 5;
        if (health > MAX_ENEMY_HP) {
            health = MAX_ENEMY_HP; // Ensure max health limit
        }
        cout << name << " regenerates health. New HP: " << health << endl;
    }
};

// Main function to demonstrate functionality
int main() {
    // Create Player objects
    Player p1("Sophia", 100, 20, "Sword");
    Player p2("Alex", 120, 25, "Bow");

    // Create Enemy objects
    Enemy e1("Goblin", 80, 15);
    Enemy e2("Orc", 200, 30);  // HP exceeds MAX_ENEMY_HP, should be adjusted

    // Display character stats
    p1.displayStats();
    p2.displayStats();
    e1.displayStats();
    e2.displayStats();

    // Call static functions
    Character::showCharacterType();
    Player::displayPlayerCount();

    // Player actions
    p1.switchWeapon("Axe");
    p1.healthRegen();
    p1.move();

    // Switch character
    p1.switchCharacter("Warrior");

    // Enemy actions
    e1.attack();
    e1.specialAttack();
    e1.healthRegen();

    // Display final stats
    p1.displayStats();
    e1.displayStats();

    return 0;
}
