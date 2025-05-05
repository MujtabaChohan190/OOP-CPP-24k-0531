#include <iostream>
#include <string>
using namespace std;

// Base class
class SamsungSmartAppliance {
protected:
    string modelName;
    bool powerOn;
    int currentMode;
    int numberOfModes;

public:
    // Constructor
    SamsungSmartAppliance(string name, int modes)
        : modelName(name), powerOn(false), currentMode(0), numberOfModes(modes) {}

    // Set power state
    void setPower(bool state) {
        powerOn = state;
        cout << (powerOn ? "Power ON\n" : "Power OFF\n");
    }

    // Check power state
    bool isPowerOn() const {
        return powerOn;
    }

    // Prefix ++ operator to cycle mode
    SamsungSmartAppliance& operator++() {
        if (powerOn) {
            currentMode = (currentMode + 1) % numberOfModes;
        }
        return *this;
    }

    // Display status (base version - will be overridden)
    virtual void displayStatus() const {
        cout << "Model: " << modelName
             << ", Power: " << (powerOn ? "ON" : "OFF");
        if (powerOn)
            cout << ", Mode: " << currentMode;
        cout << endl;
    }
};

// Derived class: SamsungSmartTV
class SamsungSmartTV : public SamsungSmartAppliance {
public:
    // Constructor sets fixed number of TV modes
    SamsungSmartTV(string name) : SamsungSmartAppliance(name, 5) {}

    // Override displayStatus
    void displayStatus() const override {
        cout << "Smart TV - Model: " << modelName
             << ", Power: " << (powerOn ? "ON" : "OFF");
        if (powerOn)
            cout << ", TV Mode: " << currentMode;
        cout << endl;
    }
};

// Derived class: SamsungWashingMachine
class SamsungWashingMachine : public SamsungSmartAppliance {
public:
    // Constructor sets fixed number of washer modes
    SamsungWashingMachine(string name) : SamsungSmartAppliance(name, 3) {}

    // Override displayStatus
    void displayStatus() const override {
        cout << "Washing Machine - Model: " << modelName
             << ", Power: " << (powerOn ? "ON" : "OFF");
        if (powerOn)
            cout << ", Wash Mode: " << currentMode;
        cout << endl;
    }
};

// Main function to demonstrate functionality
int main() {
    // Create objects
    SamsungSmartTV tv("QLED_TV");
    SamsungWashingMachine wm("EcoWasher");

    // Display initial status
    tv.displayStatus();
    wm.displayStatus();

    // Power ON both
    tv.setPower(true);
    wm.setPower(true);

    // Cycle modes
    ++tv;
    ++tv;
    ++wm;

    // Display updated status
    tv.displayStatus();
    wm.displayStatus();

    return 0;
}
