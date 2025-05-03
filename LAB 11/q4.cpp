#include <iostream>
using namespace std;

// Base class template
template <typename T>
class Base {
protected:
    T value1;
    T value2;

public:
    // Constructor to initialize values
    Base(T v1, T v2) : value1(v1), value2(v2) {}

    // Function to multiply values in the base class
    T multiplyBase() const {
        return value1 * value2;
    }

    // Function to display values in the base class
    void displayBase() const {
        cout << "Base Class Values: " << value1 << " and " << value2 << endl;
    }
};

// Derived class template inheriting from Base class template
template <typename T>
class Derived : public Base<T> {
private:
    T value3;
    T value4;

public:
    // Constructor to initialize values of both base and derived classes
    Derived(T v1, T v2, T v3, T v4) : Base<T>(v1, v2), value3(v3), value4(v4) {}

    // Function to multiply values in the derived class
    T multiplyDerived() const {
        return this->value1 * this->value2 * value3 * value4;  // Multiply base and derived class values
    }

    // Function to display values of both base and derived classes
    void displayDerived() const {
        this->displayBase();  // Call base class display function
        cout << "Derived Class Values: " << value3 << " and " << value4 << endl;
    }
};

// Main function
int main() {
    // Create an object of the Derived class with int type
    Derived<int> obj(2, 3, 4, 5);

    // Display values in both base and derived classes
    obj.displayDerived();

    // Multiply values in the base and derived classes and display the result
    cout << "Multiplying values in the base class: " << obj.multiplyBase() << endl;
    cout << "Multiplying values in the derived class: " << obj.multiplyDerived() << endl;

    return 0;
}
