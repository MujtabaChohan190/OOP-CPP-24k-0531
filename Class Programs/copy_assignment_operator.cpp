#include <iostream>
using namespace std;

class Example {
public:
    int x;

    // Constructor
    Example(int value) { x = value; }

    // Copy Assignment Operator
    Example& operator=(const Example& obj) {
        cout << "Copy Assignment Operator Called\n";
        x = obj.x;  // Copy data
        return *this;
    }

    void display() { cout << "Value: " << x << endl; }
};

int main() {
    Example obj1(10);  // Object 1 with x = 10
    Example obj2(20);  // Object 2 with x = 20

    obj2 = obj1;  // Copy obj1’s data into obj2

    obj1.display();  // Output: Value: 10
    obj2.display();  // Output: Value: 10

    return 0;
}
