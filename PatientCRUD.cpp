#include "PatientCRUD.h"
#include "History.h"
#include <iostream>
#include <iomanip>
using namespace std;

void initPatientList(PatientList& list, int capacity) {
    list.capacity = capacity;
    list.count    = 0;
    list.data     = new Patient[list.capacity];
}

void freePatientList(PatientList& list) {
    if (list.data != nullptr) {
        delete[] list.data;
        list.data = nullptr;
    }
    list.count    = 0;
    list.capacity = 0;
}

void resizePatientList(PatientList& list) {
    int newCapacity  = list.capacity * 2;
    Patient* newData = new Patient[newCapacity];
    for (int i = 0; i < list.count; i++)
        newData[i] = list.data[i];
    delete[] list.data;
    list.data     = newData;
    list.capacity = newCapacity;
}

void printSinglePatient(const Patient& p) {
    cout << left
         << setw(12) << p.id
         << setw(26) << p.name
         << setw(7)  << p.age
         << setw(12) << p.gender
         << p.symptoms << "\n";
}

void addPatient(PatientList& list) {
    if (list.count >= list.capacity)
        resizePatientList(list);

    Patient p;
    p.historyHead = nullptr;

    cout << "\n  --- ADD NEW PATIENT ---\n";
    cout << "  Patient ID   : ";
    cin >> p.id;
    cin.ignore();

    for (int i = 0; i < list.count; i++) {
        if (list.data[i].id == p.id) {
            cout << "  [!] Error: ID already exists. Please use a different ID.\n";
            return;
        }
    }

    cout << "  Full Name    : ";
    getline(cin, p.name);

    cout << "  Age          : ";
    while (!(cin >> p.age) || p.age <= 0 || p.age > 150) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "  Invalid age. Try again: ";
    }
    cin.ignore();

    cout << "  Gender (M/F) : ";
    getline(cin, p.gender);

    cout << "  Symptoms     : ";
    getline(cin, p.symptoms);

    list.data[list.count] = p;
    list.count++;

    cout << "  [OK] Patient added successfully.\n";
}

void displayAllPatients(const PatientList& list) {
    if (list.count == 0) {
        cout << "  No patients on record.\n";
        return;
    }

    cout << "\n  " << string(85, '=') << "\n";
    cout << "  " << left
         << setw(12) << "ID"
         << setw(26) << "Full Name"
         << setw(7)  << "Age"
         << setw(12) << "Gender"
         << "Symptoms" << "\n";
    cout << "  " << string(85, '-') << "\n";

    for (int i = 0; i < list.count; i++) {
        cout << "  ";
        printSinglePatient(list.data[i]);
    }
    cout << "  " << string(85, '=') << "\n";
    cout << "  Total: " << list.count << " patient(s).\n";
}

void updatePatient(PatientList& list, const string& id) {
    for (int i = 0; i < list.count; i++) {
        if (list.data[i].id == id) {
            cout << "  --- EDIT PATIENT (ID: " << id << ") ---\n";
            cout << "  Leave blank to keep current value.\n\n";

            string tmp;

            cout << "  Full Name    [" << list.data[i].name << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) list.data[i].name = tmp;

            cout << "  Age          [" << list.data[i].age << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) {
                try {
                    int a = stoi(tmp);
                    if (a > 0 && a <= 150) list.data[i].age = a;
                } catch (...) {}
            }

            cout << "  Gender       [" << list.data[i].gender << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) list.data[i].gender = tmp;

            cout << "  Symptoms     [" << list.data[i].symptoms << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) list.data[i].symptoms = tmp;

            cout << "  [OK] Patient updated successfully.\n";
            return;
        }
    }
    cout << "  [!] Patient with ID \"" << id << "\" not found.\n";
}

void deletePatient(PatientList& list, const string& id) {
    for (int i = 0; i < list.count; i++) {
        if (list.data[i].id == id) {
            deleteVisitHistory(list.data[i]);

            for (int j = i; j < list.count - 1; j++)
                list.data[j] = list.data[j + 1];

            list.data[list.count - 1].historyHead = nullptr;
            list.count--;
            cout << "  [OK] Patient deleted successfully.\n";
            return;
        }
    }
    cout << "  [!] Patient with ID \"" << id << "\" not found.\n";
}