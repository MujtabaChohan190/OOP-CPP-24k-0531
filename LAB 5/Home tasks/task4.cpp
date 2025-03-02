#include <iostream>
#include <thread>   // For std::this_thread::sleep_for
#include <chrono>   // For time duration

using namespace std;


class Blend {
public:
    void blendProcess() {
        cout << "Selecting fruits...\n";
        cout << "Blending in progress...\n";

        // Loop for 4-5 seconds to simulate blending
        for (int i = 0; i < 4; i++) {
            cout << "Blending..." << endl;
            this_thread::sleep_for(chrono::seconds(1)); // Sleep for 1 second per iteration
        }

        cout << "Blending completed!\n";
    }
};

class Grind {
public:
    void grindProcess() {
        cout << "Grinding process started...\n";

        // Sleep for 5 seconds to simulate grinding
        this_thread::sleep_for(chrono::seconds(5));

        cout << "Grinding completed!\n";
    }
};

class JuiceMaker {
private:
    Blend blender;  // Composition: JuiceMaker has a Blend
    Grind grinder;  // Composition: JuiceMaker has a Grind

public:
    void makeJuice() {
        cout << "Starting the juice-making process...\n";
        
        blender.blendProcess();
        
        grinder.grindProcess();

        cout << "Juice is ready! Enjoy your drink.\n";
    }
};

int main() {
    JuiceMaker juicer;  
    juicer.makeJuice(); 
    return 0;
}

/*The blendJuice() method calls the blendProcess() function, which loops to simulate blending for 4-5 seconds.
The grindJuice() method calls the grindProcess() function, which sleeps the program for 5 seconds to simulate grinding.
The program prints messages at each step to simulate the real juice-making process*/
