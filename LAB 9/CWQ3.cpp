#include <iostream>
#include <string>
using namespace std;


class Doctor;
class Billing;

class PatientRecord {
private:
    string name;
    string patientID;
    string dob;
    string* medicalHistory;
    int medCount;

    string* billingRecords;
    int billingCount;

    void addToMedicalHistory(const string& entry) {
        string* newHistory = new string[medCount + 1];
        for (int i = 0; i < medCount; i++) newHistory[i] = medicalHistory[i];
        newHistory[medCount++] = entry;
        delete[] medicalHistory;
        medicalHistory = newHistory;
    }

    void addToBilling(const string& bill) {
        string* newBilling = new string[billingCount + 1];
        for (int i = 0; i < billingCount; i++) newBilling[i] = billingRecords[i];
        newBilling[billingCount++] = bill;
        delete[] billingRecords;
        billingRecords = newBilling;
    }

public:
    PatientRecord(string id, string n, string birth) {
        patientID = id;
        name = n;
        dob = birth;
        medicalHistory = nullptr;
        billingRecords = nullptr;
        medCount = billingCount = 0;
    }

    string getPublicData() const {
        return "Patient: " + name + " | ID: " + patientID + " | DOB: " + dob;
    }

    string getMedicalData() const {
        string result = "Medical History:\n";
        for (int i = 0; i < medCount; i++) {
            result += "- " + medicalHistory[i] + "\n";
        }
        return result;
    }

    string getBillingData() const {
        string result = "Billing Records:\n";
        for (int i = 0; i < billingCount; i++) {
            result += "- " + billingRecords[i] + "\n";
        }
        return result;
    }

 
    friend class Doctor;
    friend class Billing;

    ~PatientRecord() {
        delete[] medicalHistory;
        delete[] billingRecords;
    }
};

class Doctor {
public:
    void addMedicalNote(PatientRecord& patient, const string& note) {
        patient.addToMedicalHistory("Doctor Note: " + note);
        cout << "Doctor updated medical history.\n";
    }

    void viewMedicalHistory(const PatientRecord& patient) {
        cout << patient.getMedicalData();
    }
};

class Billing {
public:
    void addBillingEntry(PatientRecord& patient, const string& entry) {
        patient.addToBilling("Bill: " + entry);
        cout << "Billing updated billing records.\n";
    }

    void viewBillingInfo(const PatientRecord& patient) {
        cout << patient.getBillingData();
    }
};

class Receptionist {
public:
    void viewPublicInfo(const PatientRecord& patient) {
        cout << patient.getPublicData() << endl;
    }

    void tryAccessMedical(const PatientRecord& patient) {
        cout << "Receptionist attempting medical access...\n";
    
        cout << "Access Denied!\n";
    }

    void tryAccessBilling(const PatientRecord& patient) {
        cout << "Receptionist attempting billing access...\n";
        
        cout << "Access Denied!\n";
    }
};

int main() {
    PatientRecord p1("P123", "John Doe", "1990-05-15");

    Doctor doc;
    Billing bill;
    Receptionist rec;

    cout << "\n=== Receptionist Access ===\n";
    rec.viewPublicInfo(p1);
    rec.tryAccessMedical(p1);
    rec.tryAccessBilling(p1);

    cout << "\n=== Doctor Access ===\n";
    doc.addMedicalNote(p1, "Diagnosed with mild hypertension.");
    doc.viewMedicalHistory(p1);

    cout << "\n=== Billing Access ===\n";
    bill.addBillingEntry(p1, "$250 Consultation Fee");
    bill.viewBillingInfo(p1);

    return 0;
}
