#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative = false;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    void normalize() {
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i] >= 10) {
                if (i == digits.size() - 1) {
                    digits.push_back(0);
                }
                digits[i+1] += digits[i] / 10;
                digits[i] %= 10;
            } else if (digits[i] < 0) {
                if (i == digits.size() - 1) {
                    throw runtime_error("Negative digit during normalization");
                }
                int borrow = (abs(digits[i]) + 9) / 10;
                digits[i+1] -= borrow;
                digits[i] += borrow * 10;
            }
        }
        removeLeadingZeros();
    }

    BigInteger addMagnitude(const BigInteger& other) const {
        BigInteger result;
        size_t maxSize = max(digits.size(), other.digits.size());
        result.digits.resize(maxSize, 0);

        for (size_t i = 0; i < maxSize; ++i) {
            if (i < digits.size()) result.digits[i] += digits[i];
            if (i < other.digits.size()) result.digits[i] += other.digits[i];
        }

        result.normalize();
        return result;
    }

    BigInteger subtractMagnitude(const BigInteger& other) const {
        BigInteger result(*this);
        for (size_t i = 0; i < other.digits.size(); ++i) {
            result.digits[i] -= other.digits[i];
        }
        result.normalize();
        return result;
    }

    int compareMagnitude(const BigInteger& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size() ? -1 : 1;
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i] ? -1 : 1;
            }
        }
        return 0;
    }

public:
    BigInteger() : digits({0}), isNegative(false) {}
    
    BigInteger(long long num) {
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        do {
            digits.push_back(num % 10);
            num /= 10;
        } while (num > 0);
    }

    BigInteger(const string& s) {
        if (s.empty()) {
            digits.push_back(0);
            return;
        }

        size_t start = 0;
        if (s[0] == '-') {
            isNegative = true;
            start = 1;
        }

        for (int i = s.length() - 1; i >= static_cast<int>(start); --i) {
            if (!isdigit(s[i])) {
                throw invalid_argument("Invalid character in BigInteger string");
            }
            digits.push_back(s[i] - '0');
        }

        removeLeadingZeros();
    }

    BigInteger operator-() const {
        BigInteger result(*this);
        if (result != BigInteger(0)) {
            result.isNegative = !result.isNegative;
        }
        return result;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = addMagnitude(other);
            result.isNegative = isNegative;
            return result;
        }

        int cmp = compareMagnitude(other);
        if (cmp == 0) return BigInteger(0);

        BigInteger result;
        if (cmp > 0) {
            result = subtractMagnitude(other);
            result.isNegative = isNegative;
        } else {
            result = other.subtractMagnitude(*this);
            result.isNegative = other.isNegative;
        }
        return result;
    }

    BigInteger operator-(const BigInteger& other) const {
        return *this + (-other);
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i) {
            for (size_t j = 0; j < other.digits.size(); ++j) {
                result.digits[i+j] += digits[i] * other.digits[j];
            }
        }

        result.isNegative = isNegative != other.isNegative;
        result.normalize();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        int cmp = compareMagnitude(other);
        return isNegative ? cmp > 0 : cmp < 0;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative) os << '-';
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& num) {
        string s;
        is >> s;
        num = BigInteger(s);
        return is;
    }
};

int main() {
    BigInteger a("12345678901234567890");
    BigInteger b("98765432109876543210");
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    
    BigInteger c;
    cout << "Enter a big integer: ";
    cin >> c;
    cout << "You entered: " << c << endl;
    
    return 0;
}