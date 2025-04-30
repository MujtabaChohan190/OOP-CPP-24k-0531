#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class StackUnderFlow : public exception {
    string str;
public:
    StackUnderFlow(string s) : str(s) {}
    const char* what() const noexcept override {
        return str.c_str();
    }
};

template <typename T>
class Stack {
    vector<T> stack;
public:
    Stack() {}

    void push(T val) {
        stack.push_back(val);
    }

    void pop() {
        if (stack.empty()) throw StackUnderFlow("Stack UnderFlow! Empty Stack");
        stack.pop_back();
    }

    void top() {
        if (stack.empty()) throw StackUnderFlow("Stack UnderFlow! Empty Stack");
        cout << "Top element: " << stack.back() << endl;
    }

    void display() {
        cout << "Stack: ";
        for (int i = stack.size() - 1; i >= 0; --i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);

        s.display();
        s.top();

        s.pop();
        s.display();

        s.pop();
        s.pop();
        s.pop(); 

    } catch (const StackUnderFlow& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
