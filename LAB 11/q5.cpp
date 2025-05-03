#include <iostream>
#include <stdexcept>  // For std::out_of_range
using namespace std;

// Custom exception for stack underflow
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: Attempted to pop or access top from an empty stack.";
    }
};

// Stack class template
template <typename T>
class Stack {
private:
    T* data;        // Dynamic array to store stack elements
    int capacity;   // Maximum capacity of the stack
    int topIndex;   // Index of the top element in the stack

public:
    // Constructor to initialize stack with a given capacity
    Stack(int cap = 10) : capacity(cap), topIndex(-1) {
        data = new T[capacity];
    }

    // Destructor to free dynamically allocated memory
    ~Stack() {
        delete[] data;
    }

    // Push an element onto the stack
    void push(const T& value) {
        if (topIndex >= capacity - 1) {
            throw overflow_error("Stack overflow: Attempted to push to a full stack.");
        }
        data[++topIndex] = value;
    }

    // Pop an element from the stack
    void pop() {
        if (topIndex == -1) {
            throw StackUnderflowException();
        }
        topIndex--;
    }

    // Get the top element of the stack
    T top() const {
        if (topIndex == -1) {
            throw StackUnderflowException();
        }
        return data[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Get the current size of the stack
    int size() const {
        return topIndex + 1;
    }
};

// Main function to demonstrate stack behavior
int main() {
    try {
        // Create a stack of integers with a capacity of 5
        Stack<int> stack(5);

        // Push elements onto the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        // Display the top element
        cout << "Top element: " << stack.top() << endl;

        // Pop elements from the stack
        stack.pop();
        cout << "After pop, top element: " << stack.top() << endl;

        // Pop remaining elements
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();

        // Attempt to pop from an empty stack (will throw exception)
        stack.pop();  // This will throw a StackUnderflowException

    } catch (const StackUnderflowException& e) {
        cout << "Exception: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
