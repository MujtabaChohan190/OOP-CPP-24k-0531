#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class BadTypeException {
public:
    string message;
    BadTypeException(const string& msg) : message(msg) {}
};

class TypeSafeContainer {
    void* data = nullptr;
    string typeName;

public:
    TypeSafeContainer() = default;

    // Store value of any supported type
    template <typename T>
    void store(const T& value) {
        if (data) {
            // Delete based on previous type
            if (typeName == typeid(int).name()) delete static_cast<int*>(data);
            else if (typeName == typeid(string).name()) delete static_cast<string*>(data);
            else if (typeName == typeid(bool).name()) delete static_cast<bool*>(data);
            else if (typeName == typeid(float).name()) delete static_cast<float*>(data);
            else if (typeName == typeid(char).name()) delete static_cast<char*>(data);
        }

        data = new T(value);
        typeName = typeid(T).name();
    }

    // Retrieve value safely
    template <typename T>
    T get() {
        if (typeid(T).name() != typeName) {
            throw BadTypeException("Incorrect type requested.");
        }
        return *(T*)data; // casts data to T* and returns the dereferenced value *(T*)data.
    }

    ~TypeSafeContainer() {
        if (data) {
            // Delete based on stored type
            if (typeName == typeid(int).name()) delete static_cast<int*>(data);
            else if (typeName == typeid(string).name()) delete static_cast<string*>(data);
            else if (typeName == typeid(bool).name()) delete static_cast<bool*>(data);
            else if (typeName == typeid(float).name()) delete static_cast<float*>(data);
            else if (typeName == typeid(char).name()) delete static_cast<char*>(data);
        }
    }
};

int main() {
    try {
        TypeSafeContainer container;

        container.store<int>(123);
        cout << "Stored int: " << container.get<int>() << endl;

        container.store<string>("Test");
        cout << "Stored string: " << container.get<string>() << endl;

        container.store<bool>(true);
        cout << "Stored bool: " << (container.get<bool>() ? "true" : "false") << endl;

        container.store<float>(3.14f);
        cout << "Stored float: " << container.get<float>() << endl;

        container.store<char>('A');
        cout << "Stored char: " << container.get<char>() << endl;

        // Uncomment to trigger exception:
        // cout << container.get<int>() << endl;

    } catch (BadTypeException& e) {
        cout << "Exception: " << e.message << endl;
    }

    return 0;
}
