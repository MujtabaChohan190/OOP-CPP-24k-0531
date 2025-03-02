#include <iostream>
#include <windows.h> // For Sleep function
using namespace std;

class Car {
private:
    mutable float engineHorsepower;
    mutable int seatingCapacity;
    mutable int numberOfSpeakers;

public:
  
    Car() : engineHorsepower(0), seatingCapacity(0), numberOfSpeakers(0) {}

    // Constant setter functions (modifies values due to `mutable`)
    void setEngineHorsepower(float hp) const 
    { 
        engineHorsepower = hp; 
    }
    
    void setSeatingCapacity(int capacity) const 
    { 
        seatingCapacity = capacity; 
    }
    
    void setNumberOfSpeakers(int speakers) const 
    { 
        numberOfSpeakers = speakers; 
    }

    // Getter functions (marked `const` for read-only access)
    float getEngineHorsepower() const 
    { 
        return engineHorsepower; 
    }
    
    int getSeatingCapacity() const 
    { 
        return seatingCapacity; 
    }
    
    int getNumberOfSpeakers() const 
    { 
        return numberOfSpeakers; 
    }

    void display() const {
        cout << "Engine Horsepower: " << getEngineHorsepower() << endl;
        cout << "Seating Capacity: " << getSeatingCapacity() << endl;
        cout << "Number of Speakers: " << getNumberOfSpeakers() << endl;

        Sleep(5000);  // Pause for 5 seconds
        system("cls"); // Clear screen
    }
};

int main() {
    Car myCar;

    cout << "Initial Car Details:\n";
    myCar.display();

  //Updated car details
    myCar.setEngineHorsepower(500);
    myCar.setSeatingCapacity(10);
    myCar.setNumberOfSpeakers(2);

    cout << "Updated Car Details:\n";
    myCar.display();

    cout << "Thank you for using our program!" << endl;
    Sleep(5000); // Pause before exit
    return 0;
}
