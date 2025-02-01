#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;  

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Vector elements: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";  
    }

    v.pop_back(); // Remove last element

    cout << "\nAfter pop_back: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
