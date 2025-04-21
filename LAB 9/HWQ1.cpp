#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual float getArea() = 0;
    virtual ~Shape() {}
};

// Rectangle class
class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float getArea() {
        return length * width;
    }
};

// Triangle class
class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }

    float getArea() {
        return 0.5f * base * height;
    }
};

// Main to demonstrate usage
int main() {
    Shape* rect = new Rectangle(10.0f, 5.0f);
    Shape* tri = new Triangle(6.0f, 4.0f);

    cout << "Area of Rectangle: " << rect->getArea() << " sq units" << endl;
    cout << "Area of Triangle: " << tri->getArea() << " sq units" << endl;

    delete rect;
    delete tri;

    return 0;
}
