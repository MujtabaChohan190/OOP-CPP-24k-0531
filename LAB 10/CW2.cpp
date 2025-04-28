#include <iostream>
#include <string>
#include <fstream>
#include <vector> // Include the vector header

using namespace std;

// Structure to hold employee data
struct Employee {
    int id;
    string name;
    string designation;
    int yearsOfService;
};

// Function to read employee data from the file
vector<Employee> readData(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Use find and substr to parse the comma-separated values
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);

            if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
                string id_str = line.substr(0, pos1);
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string designation = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string years_str = line.substr(pos3 + 1);
                try {
                    int id = stoi(id_str);
                    int yearsOfService = stoi(years_str);
                    employees.push_back({id, name, designation, yearsOfService});
                } catch (const invalid_argument& e) {
                    cerr << "Error: Invalid data format in file. Skipping line: " << line << endl;
                }
            } else {
                 cerr << "Error: Invalid data format in file. Skipping line: " << line << endl;
            }
        }
        file.close();
    } else {
        cerr << "Error opening file for reading: " << filename << endl;
    }
    return employees;
}

// Function to write employee data to the file
void writeData(const string& filename, const vector<Employee>& employees) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& emp : employees) {
            file << emp.id << "," << emp.name << "," << emp.designation << "," << emp.yearsOfService << endl;
        }
        file.close();
    } else {
        cerr << "Error opening file for writing: " << filename << endl;
    }
}

// Function to find employees matching the criteria (Query a)
vector<Employee> findEmployees(const vector<Employee>& employees) {
    vector<Employee> result;
    for (const auto& emp : employees) {
        if (emp.designation == "Manager" && emp.yearsOfService >= 2) {
            result.push_back(emp);
        }
    }
    return result;
}

// Function to delete all data except the matching data (Query b)
void deleteExceptMatching(const string& filename, const vector<Employee>& matchingEmployees) {
    writeData(filename, matchingEmployees); // Overwrite the file with the matching data
}

// Function to write the same data with incremented IDs and years (Query c)
void writeIncrementedData(const string& filename, const vector<Employee>& data) {
    vector<Employee> incrementedData;
    for (const auto& emp : data) {
        incrementedData.push_back({emp.id + 1, emp.name, emp.designation, emp.yearsOfService + 1});
    }
    writeData(filename, incrementedData);
}

int main() {
    string filename = "employee_data.txt";

    // Create some dummy data and write it to the file
    vector<Employee> initialData = {
        {1, "Alice Smith", "Software Engineer", 3},
        {2, "Bob Johnson", "Manager", 5},
        {3, "Charlie Brown", "Software Engineer", 1},
        {4, "David Miller", "Manager", 2},
        {5, "Eve Wilson", "Team Lead", 4}
    };
    writeData(filename, initialData);

    // Read the data from the file
    vector<Employee> employees = readData(filename);

    // a) Find employees with designation "Manager" and years of service >= 2
    cout << "\nQuery a) Employees with designation 'Manager' and years of service >= 2:\n";
    vector<Employee> matchingEmployees = findEmployees(employees);
    if (matchingEmployees.empty()) {
        cout << "No matching employees found.\n";
    } else {
        for (const auto& emp : matchingEmployees) {
            cout << "ID: " << emp.id << ", Name: " << emp.name << ", Designation: " << emp.designation
                 << ", Years of Service: " << emp.yearsOfService << endl;
        }
    }

    // b) Delete all data except the matching data
    deleteExceptMatching(filename, matchingEmployees);
    cout << "\nQuery b) Deleted all data except the matching data.\n";

    // Verify the deletion by reading the file
    vector<Employee> dataAfterDeletion = readData(filename);
    cout << "\nData in file after deletion:\n";
    if (dataAfterDeletion.empty()){
        cout<< "No Data" <<endl;
    }
    else{
        for(const auto& emp : dataAfterDeletion){
             cout << "ID: " << emp.id << ", Name: " << emp.name << ", Designation: " << emp.designation
                 << ", Years of Service: " << emp.yearsOfService << endl;
        }
    }


    // c) Write the same data with incremented IDs and years
    writeIncrementedData(filename, matchingEmployees);
    cout << "\nQuery c) Wrote incremented data to the file.\n";

     // Verify the data written
    vector<Employee> incrementedDataRead = readData(filename);
    cout << "\nData in file after incrementing IDs and years:\n";
     if (incrementedDataRead.empty()){
        cout<< "No Data" <<endl;
    }
    else{
        for (const auto& emp : incrementedDataRead) {
            cout << "ID: " << emp.id << ", Name: " << emp.name << ", Designation: " << emp.designation
                << ", Years of Service: " << emp.yearsOfService << endl;
        }
    }

    return 0;
}
