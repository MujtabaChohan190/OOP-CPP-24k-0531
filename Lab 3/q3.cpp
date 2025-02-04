/*We are prototyping a robot that refills glasses during dinner. Every glass holds 200 milliliters. During dinner,
people either drink water or juice, and as soon as there is less than 100 ml left in the glass, the robot refills it back
to 200 ml.
Create a class Glass with one public int field LiquidLevel and methods public Drink(int milliliters) that takes the
amount of liquid that a person drank and public Refill() that refills the glass to be 200 ml full. Both methods
should not return any value. Initially set LiquidLevel to 200. In the Main method create an object of class Glass
and read commands from the screen until the user terminates the program (see next). Don't forget to refill the glass
when needed!
*/

#include<iostream>
using namespace std;

class Glass{
    public:
    int Liquidlevel;

    //Constructor to intially set liquid level to 200
    Glass(){
        Liquidlevel = 200;
    }

    //Method to simulate the drinking in class , liquidlevel gets reduced in each drink , and as soon as liquid level becomes 100 , robot refills
    void Drink(int milliliters){
        Liquidlevel -= milliliters;
        if(Liquidlevel<100){
            refill();
        }
    }
    void refill(){
        Liquidlevel = 200;
        cout<<"The glass has been refilled back to 200ml"<<endl;
    }

};

int main(){
    Glass myGlass;  

    int drinkAmount;
    
    // Continuous loop to read commands until the user chooses to stop
    while (true) {
        cout << "The Current Liquid Level is : " << myGlass.Liquidlevel << " ml" << endl;
        cout << "How many milliliters did you drink (enter a number, or 0 to exit) ";
        cin >> drinkAmount;

        // If the user enters 0, terminate the program
        if (drinkAmount == 0) {
            cout << "Terminating the program." << endl;
            break;
        }

        myGlass.Drink(drinkAmount);
    }

    return 0;
}
