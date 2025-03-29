#include <iostream>

using namespace std;

class Shape {
private:
    double area;
public:
    Shape(double a = 0) : area(a) {}

    // Making function to compute area with some operation (e.g correction factor) - other operations can also be applied
    double Area() const {
        return area * 1.1; 
    }

    Shape operator+(const Shape& other) const {
        return Shape(this->Area() + other.Area());
    }

    void display() const {
        cout << "Computed Area: " << Area() << endl;
    }
};

int main() {
    Shape shape1(20.5), shape2(15.3);
    
    Shape totalArea = shape1 + shape2; 

    cout << "Shape1 ";
    shape1.display();

    cout << "Shape2 ";
    shape2.display();

    cout << "Total ";
    totalArea.display();

    return 0;
}
