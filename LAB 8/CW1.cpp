#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    static int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        if (denominator == 0) {
            throw runtime_error("Denominator cannot be zero");
        }
        
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        
        int common_divisor = gcd(numerator, denominator);
        if (common_divisor != 0) {
            numerator /= common_divisor;
            denominator /= common_divisor;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(
            numerator * other.numerator,
            denominator * other.denominator
        );
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw runtime_error("Division by zero");
        }
        return Fraction(
            numerator * other.denominator,
            denominator * other.numerator
        );
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator<=(const Fraction& other) const {
        return *this < other || *this == other;
    }

    bool operator>=(const Fraction& other) const {
        return *this > other || *this == other;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1) {
            os << f.numerator;
        } else {
            os << f.numerator << "/" << f.denominator;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        int num, denom = 1;
        char slash;
        
        is >> num;
        if (is.peek() == '/') {
            is >> slash >> denom;
        }
        
        f = Fraction(num, denom);
        return is;
    }
};

int main() {
    Fraction f1(2, 4); 
    Fraction f2(3, 6);  
    
    cout << (f1 + f2) << endl;  
    
    return 0;
}
