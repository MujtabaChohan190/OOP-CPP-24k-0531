#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    double x, y;
    string color;
    double borderThickness;

public:
    Shape(double posX, double posY, string c, double bT) 
        : x(posX), y(posY), color(c), borderThickness(bT) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    virtual void getAttributes() {
        cout << "Position: (" << x << ", " << y << ")\n";
        cout << "Color: " << color << endl;
        cout << "Border Thickness: " << borderThickness << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double posX, double posY, string c, double bT, double r) 
        : Shape(posX, posY, c, bT), radius(r) {}

    void draw() override {
        cout << "Drawing a " << color << " Circle at center (" << x << ", " << y 
             << ") with radius " << radius << endl;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }

    void getAttributes() override {
        Shape::getAttributes();
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double posX, double posY, string c, double bT, double w, double h) 
        : Shape(posX, posY, c, bT), width(w), height(h) {}

    void draw() override {
        cout << "Drawing a " << color << " Rectangle with top-left corner at (" 
             << x << ", " << y << "), width " << width << " and height " << height << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }

    void getAttributes() override {
        Shape::getAttributes();
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double posX, double posY, string c, double bT, double side1, double side2, double side3)
        : Shape(posX, posY, c, bT), a(side1), b(side2), c(side3) {}

    void draw() override {
        cout << "Drawing a " << color << " Triangle at (" << x << ", " << y << ") with sides " 
             << a << ", " << b << ", " << c << endl;
    }

    double calculateArea() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calculatePerimeter() override {
        return a + b + c;
    }

    void getAttributes() override {
        Shape::getAttributes();
        cout << "Sides: " << a << ", " << b << ", " << c << endl;
    }
};

class Polygon : public Shape {
private:
    int numSides;
    double sideLength;

public:
    Polygon(double posX, double posY, string c, double bT, int n, double s)
        : Shape(posX, posY, c, bT), numSides(n), sideLength(s) {}

    void draw() override {
        cout << "Drawing a " << color << " " << numSides << "-sided Polygon at (" 
             << x << ", " << y << ") with side length " << sideLength << endl;
    }

    double calculateArea() override {
        return (numSides * sideLength * sideLength) / (4 * tan(M_PI / numSides));
    }

    double calculatePerimeter() override {
        return numSides * sideLength;
    }

    void getAttributes() override {
        Shape::getAttributes();
        cout << "Number of Sides: " << numSides << ", Side Length: " << sideLength << endl;
    }
};

int main() {
    Shape* shapes[4];

    shapes[0] = new Circle(2, 3, "Red", 1.5, 5);
    shapes[1] = new Rectangle(5, 7, "Blue", 2.0, 4, 6);
    shapes[2] = new Triangle(0, 0, "Green", 1.0, 3, 4, 5);
    shapes[3] = new Polygon(10, 15, "Yellow", 1.2, 6, 4);  // Hexagon

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        shapes[i]->getAttributes();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    return 0;
}

