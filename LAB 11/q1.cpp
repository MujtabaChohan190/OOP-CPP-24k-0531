#include <iostream>
#include <string>
#include <any>
#include <unordered_map>
#include <typeindex>
#include <exception>

using namespace std;

// Custom exception for type mismatch
class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Type mismatch: Requested type does not match stored type.";
    }
};

// TypeSafeContainer class
class TypeSafeContainer {
private:
    unordered_map<string, any> data;

public:
    // Store a value of any type
    template<typename T>
    void store(const string& key, const T& value) {
        data[key] = value;
    }

    // Retrieve a value safely
    template<typename T>
    T get(const string& key) const {
        auto it = data.find(key);
        if (it == data.end()) {
            throw out_of_range("Key not found in container.");
        }

        try {
            return any_cast<T>(it->second);
        } catch (const bad_any_cast&) {
            throw BadTypeException();
        }
    }
};

int main() {
    TypeSafeContainer container;

    // Storing values of different types
    container.store("age", 30);
    container.store("name", string("Alice"));
    container.store("height", 5.9);

    try {
        int age = container.get<int>("age");
        string name = container.get<string>("name");
        double height = container.get<double>("height");

        cout << "Name: " << name << ", Age: " << age << ", Height: " << height << endl;

        // This will throw BadTypeException
        string wrongType = container.get<string>("age");
        cout << "This won't print: " << wrongType << endl;

    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
