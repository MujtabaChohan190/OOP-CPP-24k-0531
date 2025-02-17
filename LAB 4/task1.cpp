/*Task - 01:
Your task is to create a Circle constructor that creates a circle with a radius provided by an argument. The
circles constructed must have two getters getArea() (PIr^2) and getPerimeter() (2PI*r) which give both
respective areas and perimeter (circumference).*/

#include<iostream>
using namespace std;
class Circle{
    float radius;
    public:
    Circle(float r): radius(r){}
    double getArea() const {
        return 3.141 * radius * radius;
    }

    double getPerimeter()  {
        return 2 *3.141 * radius;
    }
};

int main() {
    double r;
    cout << "Enter radius of the circle: ";
    cin >> r;

    Circle c(r);

    cout << "Area: " << c.getArea() << endl;
    cout << "Perimeter: " << c.getPerimeter() << endl;

    return 0;
}
