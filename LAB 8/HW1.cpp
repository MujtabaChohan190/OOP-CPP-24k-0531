#include <iostream>

using namespace std;

class Number {
private:
    int value;
public:
    Number(int v) : value(v) {}

    // Prefix -- (multiplies by 4)
    Number& operator--() {
        value *= 4;
        return *this;
    }

    // Postfix -- (divides by 4)
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(8);

    cout << "Original: ";
    num.display();

    --num; // Prefix: multiply by 4
    cout << "After Prefix --: ";
    num.display();

    num--; // Postfix: divide by 4
    cout << "After Postfix --: ";
    num.display();

    return 0;
}
