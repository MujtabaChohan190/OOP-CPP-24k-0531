/*Create a class User with two public fields: int Age and string Name. In the Main method, create an object of class
User and set Name to "Teo" and Age to 24. Then, output to the screen: "My name is {Name} and I'm {Age} years
old." using object fields for Name and Age.*/

#include<iostream>
#include<string>
using namespace std;

class User{
    public:
    int Age;
    string Name;
};

int main(){
    User user1;
    user1.Name = "Teo";
    user1.Age = 24;
    cout<<"My name is "<< user1.Name <<" and I'm "<< user1.Age <<" years old "<<endl;
    return 0;
}
