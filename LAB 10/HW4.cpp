#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// Function to get current timestamp in a readable format
string getCurrentTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // Format the timestamp string manually
    string year = to_string(1900 + ltm->tm_year);
    string month = to_string(1 + ltm->tm_mon);
    string day = to_string(ltm->tm_mday);
    string hour = to_string(ltm->tm_hour);
    string min = to_string(ltm->tm_min);
    string sec = to_string(ltm->tm_sec);
    
    // Add leading zeros if necessary
    month = (month.length() == 1) ? "0" + month : month;
    day = (day.length() == 1) ? "0" + day : day;
    hour = (hour.length() == 1) ? "0" + hour : hour;
    min = (min.length() == 1) ? "0" + min : min;
    sec = (sec.length() == 1) ? "0" + sec : sec;
    
    return year + "-" + month + "-" + day + " " + hour + ":" + min + ":" + sec;
}

// Function to write log messages to a file with rotation
void writeLog(const string& logMessage, const string& baseFilename = "log", int maxSizeKB = 1024) {
    static int fileCounter = 1;
    string filename = baseFilename + to_string(fileCounter) + ".txt";
    ifstream file(filename, ios::binary);
    // Determine the size of the file
    if (file.is_open()) {
        file.seekg(0, ios::end);
        int fileSizeKB = file.tellg() / 1024;
        file.close();
        if (fileSizeKB > maxSizeKB) {
            fileCounter++;
            filename = baseFilename + to_string(fileCounter) + ".txt";
        }
    }
    //open file in append mode
    ofstream logFile(filename, ios::app);
    if (logFile.is_open()) {
        logFile << getCurrentTimestamp() << " - " << logMessage << endl;
        logFile.close();
    } else {
        cerr << "Error: Could not open log file " << filename << endl;
    }
}

// Function to add a task to the to-do list
void addTask(const string& task, const string& filename = "todo.txt") {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "0," << task << endl; // 0 for not done, 1 for done
        file.close();
        cout << "Task added: " << task << endl;
    } else {
        cerr << "Error: Could not open to-do list file" << endl;
    }
}

// Function to view all tasks
void viewTasks(const string& filename = "todo.txt") {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Current Tasks:" << endl;
        int taskCount = 1;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string status = line.substr(0, pos);
                string task = line.substr(pos + 1);
                cout << taskCount++ << ". ";
                if (status == "0") {
                    cout << "[ ] ";
                } else if (status == "1") {
                    cout << "[x] ";
                } else {
                    cout << "[?] "; //handle unexpected status
                }
                cout << task << endl;
            }
            else{
                 cout << taskCount++ << ". [?] " << line << endl;
            }
        }
        file.close();
    } else {
        cerr << "Error: Could not open to-do list file" << endl;
    }
}

// Function to mark a task as done
void markTaskAsDone(int taskNumber, const string& filename = "todo.txt") {
    ifstream file(filename);
    vector<string> tasks;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            tasks.push_back(line);
        }
        file.close();
    } else {
        cerr << "Error: Could not open to-do list file" << endl;
        return;
    }

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        size_t pos = tasks[taskNumber - 1].find(','); //find the first comma
        if(pos != string::npos){
            string status = tasks[taskNumber - 1].substr(0, pos);
            string task = tasks[taskNumber - 1].substr(pos + 1);
             if (status == "0") {
                tasks[taskNumber - 1] = "1," + task; //mark as done
                cout << "Task " << taskNumber << " marked as done." << endl;
            }
            else if (status == "1"){
                 cout << "Task " << taskNumber << " is already done." << endl;
            }
            else{
                cout << "Task " << taskNumber << " has an invalid status." << endl;
            }
        }
        else{
            cout << "Task " << taskNumber << " has an invalid format." << endl;
        }


        ofstream outfile(filename);
        if (outfile.is_open()) {
            for (const auto& task : tasks) {
                outfile << task << endl;
            }
            outfile.close();
        } else {
            cerr << "Error: Could not write to to-do list file" << endl;
        }
    } else {
        cout << "Error: Invalid task number." << endl;
    }
}

int main() {
    // Task 4: Logging System
    writeLog("Application started.");
    writeLog("User logged in.");
    writeLog("Data processed successfully.");
    writeLog("Warning: Low disk space.", "warning"); //rotate logs in warning*.txt
    writeLog("Error: Database connection failed.", "error"); //rotate logs in error*.txt
    for (int i = 0; i < 2500; ++i) { //create a lot of log entries to test rotation
        writeLog("Testing log rotation: " + to_string(i));
    }

    // Task 5: To-Do List Manager
    int choice;
    do {
        cout << "\nTo-Do List Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task: ";
                getline(cin, task);
                addTask(task);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter task number to mark as done: ";
                cin >> taskNumber;
                markTaskAsDone(taskNumber);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
