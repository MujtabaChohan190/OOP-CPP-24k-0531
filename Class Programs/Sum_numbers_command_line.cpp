//This program calculates the sum of numbers provided as command-line arguments (argv).
#include <iostream>
#include <cstdlib>  // For atoi()
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <num1> <num2> ..." << endl;
        return 1;
    }

    int sum = 0;
    
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);  // Convert string to integer
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
