/*Task - 02: Implement a Polynomial Class
1. Overview:
A Polynomial can be represented by its coefficients. For example,

a0​+a1​x+a2​x2+…+an​xn

Create a class Polynomial that stores these coefficients dynamically.
2. Details:
o Data members:
 A dynamically allocated array of double (for coefficients).
 An int that represents the highest power (degree) of the polynomial.
o Constructors:

1. Default constructor: Creates a polynomial of degree 0 with a coefficient array of size 1 (initialized to 0).
2. Parameterized constructor: Takes an int degree and an array of double for coefficients. Copies them
dynamically.
3. Copy constructor: Deep copy of the coefficients.
4. Move constructor: Transfers ownership of the coefficient array.
5. Destructor: Cleans up the allocated memory.

o Member functions:
 int getDegree() const: returns the polynomial’s degree.
 double evaluate(double x) const: computes the polynomial value at x.
 Polynomial add(const Polynomial&amp; other) const: returns a new Polynomial that is
the sum of the current polynomial and other.
 Polynomial multiply(const Polynomial&amp; other) const: returns a new Polynomial
that is the product of the two polynomials.*/


#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
    double *coefficients;
    int degree;

public:
    Polynomial() : degree(0), coefficients(new double[1]{0}) {}

    Polynomial(int deg, double *arr) : degree(deg), coefficients(new double[deg + 1])
    {
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = arr[i];
        }
    }

    Polynomial(const Polynomial &other) : degree(other.degree), coefficients(new double[other.degree + 1])
    {
        for (int i = 0; i <= other.degree; i++)
        {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial &&other) noexcept : degree(other.degree), coefficients(other.coefficients)
    {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial()
    {
        delete[] coefficients;
    }

    int getDegree() const
    {
        return degree;
    }

    double evaluate(double x) const
    {
        double result = 0;
        for (int i = 0; i <= degree; i++)
        {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial &other) const
    {
        int maxDegree = max(degree, other.degree);
        double *newCoefficients = new double[maxDegree + 1](); // Zero initialize

        for (int i = 0; i <= degree; i++)
        {
            newCoefficients[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; i++)
        {
            newCoefficients[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, newCoefficients);
        delete[] newCoefficients;
        return result;
    }

    Polynomial multiply(const Polynomial &other) const
    {
        int newDegree = degree + other.degree;
        double *newCoefficients = new double[newDegree + 1]();

        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= other.degree; j++)
            {
                newCoefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(newDegree, newCoefficients);
        delete[] newCoefficients;
        return result;
    }

    void print() const
    {
        bool first = true;
        for (int i = degree; i >= 0; i--)
        {
            if (coefficients[i] != 0)
            {
                if (!first)
                    cout << " + ";
                cout << coefficients[i] << "x^" << i;
                first = false;
            }
        }
        cout << endl;
    }
};

int main()
{
    double coeffs1[] = {2, 3, 1}; 
    double coeffs2[] = {1, -2, 4};

    Polynomial p1(2, coeffs1);
    Polynomial p2(2, coeffs2);

    cout << "Polynomial 1: ";
    p1.print();

    cout << "Polynomial 2: ";
    p2.print();

    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.print();

    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.print();

    double x = 2;
    cout << "p1 evaluated at x = " << x << ": " << p1.evaluate(x) << endl;

    return 0;
}
