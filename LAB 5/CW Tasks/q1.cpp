/*Task 1: Car and Engine (Basic Composition)
Description
Create two classes: Car and Engine. Demonstrate composition by ensuring:
 Car has-a Engine as a direct member (e.g., Engine engine; inside Car).
 The Engine object is fully contained within Car (i.e., the Car controls the Engine’s
lifetime).
Requirements
1. Engine
o Has a start() and stop() function that just prints messages (e.g., &quot;Engine started&quot;,
&quot;Engine stopped&quot;).
o Has a member variable (e.g., bool isRunning) to indicate if the engine is running.
2. Car
o Declares a private Engine engine; as a composition member.
o Provides a startCar() and stopCar() method that delegates to engine.start() and
engine.stop().
o In main() or a test function, create a Car object and call startCar() and stopCar().*/


#include <iostream>

using namespace std;

class Engine {
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {}

    void start() {
        if (!isRunning) {
            isRunning = true;
            cout << "Engine started" << endl;
        } else {
            cout << "Engine is already running" << endl;
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            cout << "Engine stopped" << endl;
        } else {
            cout << "Engine is already off" << endl;
        }
    }
};

class Car {
private:
    Engine engine; 

public:
    void startCar() {
        cout << "Starting the car." << endl;
        engine.start();
    }

    void stopCar() {
        cout << "Stopping the car." << endl;
        engine.stop();
    }
};

int main() {
    cout << "Creating a Car object..." << endl;
    Car myCar; // With this Engine is automatically created with Car

    myCar.startCar();
    myCar.stopCar();

    cout << "Car object going out of scope, destroying Engine automatically..." << endl;

    return 0;
}
