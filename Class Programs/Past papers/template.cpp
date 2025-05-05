#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// ----------------- Abstract Base Class -----------------
class Entity {
public:
    virtual string getName() const = 0;
    virtual double getMass() const = 0;
    virtual ~Entity() {}
};

// ----------------- Properties Class -----------------
class Properties {
public:
    // Example placeholder variables
    double charge;
    double velocity;
    double orbitRadius;
    double gravityForce;
    string quantumState;

    Properties() : charge(0), velocity(0), orbitRadius(0), gravityForce(0), quantumState("Unknown") {}
};

// ----------------- Derived Entity Types -----------------

class Particle : public Entity {
protected:
    string name;
    double mass;
    Properties props;
public:
    Particle(string n, double m, double c, double v) {
        name = n;
        mass = m;
        props.charge = c;
        props.velocity = v;
    }

    string getName() const override { return name; }
    double getMass() const override { return mass; }
    Properties getProperties() const { return props; }
};

class CelestialBody : public Entity {
protected:
    string name;
    double mass;
    Properties props;
public:
    CelestialBody(string n, double m, double orbit, double gravity) {
        name = n;
        mass = m;
        props.orbitRadius = orbit;
        props.gravityForce = gravity;
    }

    string getName() const override { return name; }
    double getMass() const override { return mass; }
    Properties getProperties() const { return props; }
};

class SubatomicParticle : public Entity {
protected:
    string name;
    double mass;
    Properties props;
public:
    SubatomicParticle(string n, double m, string qState) {
        name = n;
        mass = m;
        props.quantumState = qState;
    }

    string getName() const override { return name; }
    double getMass() const override { return mass; }
    Properties getProperties() const { return props; }
};

// ----------------- Specialized Entities -----------------
class Electron : public Particle {
public:
    Electron() : Particle("Electron", 9.11e-31, -1, 2.2e6) {}
};

class Proton : public Particle {
public:
    Proton() : Particle("Proton", 1.67e-27, 1, 0.0) {}
};

class Earth : public CelestialBody {
public:
    Earth() : CelestialBody("Earth", 5.97e24, 149.6e6, 9.8) {}
};

class Neutrino : public SubatomicParticle {
public:
    Neutrino() : SubatomicParticle("Neutrino", 1e-36, "Lepton, weak interaction") {}
};
template <typename T>
class EntityContainer {
    vector<T*> entities; // raw pointers to base class
public:
    ~EntityContainer() {
        for (int i = 0; i < entities.size(); i++) {
            delete entities[i]; // clean up memory
        }
    }

    void addEntity(T* entity) {
        entities.push_back(entity);
    }

    void displayNames() const {
        for (int i = 0; i < entities.size(); i++) {
            cout << "Entity: " << entities[i]->getName() << endl;
        }
    }

    double calculateTotalMass() const {
        double total = 0;
        for (int i = 0; i < entities.size(); i++) {
            total += entities[i]->getMass();
        }
        return total;
    }

    void showProperties() const {
        for (int i = 0; i < entities.size(); i++) {
            cout << "--- " << entities[i]->getName() << " ---\n";
            entities[i]->displayProperties(); // each class shows its own properties
        }
    }
};

int main() {
    // Create container to hold any type of Entity
    EntityContainer<Entity> container;

    // Add various entities using polymorphism
    container.addEntity(new Electron());
    container.addEntity(new Proton());
    container.addEntity(new Earth());
    container.addEntity(new Neutrino());

    // Display all entity names
    cout << "Entity Names:\n";
    container.displayNames();

    // Calculate and display total mass
    double totalMass = container.calculateTotalMass();
    cout << "\nTotal Mass of All Entities: " << totalMass << " kg\n";

    // Show specific properties based on type (handled by polymorphic displayProperties())
    cout << "\nEntity Properties:\n";
    container.showProperties();

    return 0;
}


