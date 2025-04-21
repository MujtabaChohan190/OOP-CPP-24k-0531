#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PatientRecord
{
private:
    string name;
    string id;
    string dob;
    vector<string> medicalHistory;
    vector<string> billingDetails;

    void updateMedicalHistory(const string &entry)
    {
        medicalHistory.push_back(entry);
    }

    void addBillingDetail(const string &entry)
    {
        billingDetails.push_back(entry);
    }

    friend class Doctor;
    friend class Billing;

public:
    PatientRecord(const string &n, const string &i, const string &d)
    {
        name = n;
        id = i;
        dob = d;
    }

    string getPublicData() const
    {
        return "Name: " + name + ", ID: " + id;
    }

    vector<string> getMedicalData(const string &role) const
    {
        if (role == "Doctor") {
            return medicalHistory;
        }
        return {};
    }

    vector<string> getBillingData(const string &role) const
    {
        if (role == "Billing") {
            return billingDetails;
        }
        return {};
    }
};

class Doctor
{
public:
    void addMedicalNote(PatientRecord &record, const string &note)
    {
        record.updateMedicalHistory(note);
    }

    void viewMedicalData(const PatientRecord &record)
    {
        vector<string> data = record.getMedicalData("Doctor");
        for (const string &entry : data) {
            cout << entry << endl;
        }
    }
};

class Billing
{
public:
    void addBill(PatientRecord &record, const string &entry)
    {
        record.addBillingDetail(entry);
    }

    void viewBills(const PatientRecord &record)
    {
        vector<string> data = record.getBillingData("Billing");
        for (const string &entry : data) {
            cout << entry << endl;
        }
    }
};

class Receptionist
{
public:
    void tryAccess(PatientRecord &record)
    {
        cout << record.getPublicData() << endl;
        vector<string> med = record.getMedicalData("Receptionist");
        vector<string> bills = record.getBillingData("Receptionist");
        cout << "Medical entries: " << med.size() << ", Billing entries: " << bills.size() << endl;
    }
};

int main()
{
    PatientRecord p("John Doe", "P123", "1990-01-01");

    Doctor doc;
    doc.addMedicalNote(p, "Diagnosed with hypertension.");
    doc.viewMedicalData(p);

    Billing bill;
    bill.addBill(p, "Consultation Fee: $200");
    bill.viewBills(p);

    Receptionist rec;
    rec.tryAccess(p);

    return 0;
}
