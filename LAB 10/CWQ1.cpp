#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class EncryptDecrypt {
public:
    // Encrypts the input text by adding the index value to the ASCII code
    string encrypt(const string& input_text) {
        string encrypted_text = "";
        for (size_t i = 0; i < input_text.length(); ++i) {
            // Add the 1-based index value to the ASCII code of the character
            char encrypted_char = input_text[i] + (i + 1);
            encrypted_text += encrypted_char;
        }
        return encrypted_text;
    }

    // Decrypts the encrypted text by subtracting the index value from the ASCII code
    string decrypt(const string& encrypted_text) {
        string decrypted_text = "";
        for (size_t i = 0; i < encrypted_text.length(); ++i) {
            // Subtract the 1-based index value to retrieve the original character
            char decrypted_char = encrypted_text[i] - (i + 1);
            decrypted_text += decrypted_char;
        }
        return decrypted_text;
    }

    // Saves the encrypted text to a file
    void saveEncryptedTextToFile(const string& encrypted_text, const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << encrypted_text;
            outFile.close();
            cout << "Encrypted text inserted in file" << endl;
        } else {
            cerr << "Error opening file for writing" << endl;
        }
    }

    // Reads the encrypted text from a file
    string readEncryptedTextFromFile(const string& filename) {
        string encrypted_text;
        ifstream inFile(filename);
        if (inFile.is_open()) {
            getline(inFile, encrypted_text);
            inFile.close();
        } else {
            cerr << "Error opening file for reading" << endl;
        }
        return encrypted_text;
    }
};

int main() {
    EncryptDecrypt ed;

    // Input the string to encrypt
    string input_text;
    cout << "Enter String: ";
    getline(cin, input_text);
    cout << "Normal Text: " << input_text << endl;

    // Encrypt the string
    string encrypted_text = ed.encrypt(input_text);
    // Save the encrypted text to the file
    ed.saveEncryptedTextToFile(encrypted_text, "encrypted_text.txt");

    // Read the encrypted text from the file
    string encrypted_text_from_file = ed.readEncryptedTextFromFile("encrypted_text.txt");

    // Decrypt the text
    string decrypted_text = ed.decrypt(encrypted_text_from_file);
    cout << "Decrypted text Read then decoded from file: " << decrypted_text << endl;

    return 0;
}
