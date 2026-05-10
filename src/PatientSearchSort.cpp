#include "PatientSearchSort.h"
#include "PatientCRUD.h"
#include <iostream>
#include <iomanip>
using namespace std;

Patient* searchPatientByID(const PatientList& list, const string& id) {
    for (int i = 0; i < list.count; i++)
        if (list.data[i].id == id)
            return &list.data[i];
    return nullptr;
}

void searchPatientByName(const PatientList& list, const string& name) {
    cout << "  --- SEARCH RESULTS FOR: \"" << name << "\" ---\n";
    bool found = false;

    for (int i = 0; i < list.count; i++) {
        string haystack = list.data[i].name;
        string needle   = name;
        for (char& c : haystack) c = tolower(c);
        for (char& c : needle)   c = tolower(c);

        if (haystack.find(needle) != string::npos) {
            if (!found) {
                cout << "\n  " << string(85, '=') << "\n";
                cout << "  " << left
                     << setw(12) << "ID"
                     << setw(26) << "Full Name"
                     << setw(7)  << "Age"
                     << setw(12) << "Gender"
                     << "Symptoms" << "\n";
                cout << "  " << string(85, '-') << "\n";
            }
            cout << "  ";
            printSinglePatient(list.data[i]);
            found = true;
        }
    }
    if (found) cout << "  " << string(85, '=') << "\n";
    else        cout << "  No matching patients found.\n";
}

static void swapPatientData(Patient& a, Patient& b) {
    swap(a.id,          b.id);
    swap(a.name,        b.name);
    swap(a.age,         b.age);
    swap(a.gender,      b.gender);
    swap(a.symptoms,    b.symptoms);
    swap(a.historyHead, b.historyHead);
}

static int partitionByName(PatientList& list, int low, int high) {
    string pivot = list.data[high].name;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (list.data[j].name <= pivot) {
            i++;
            swapPatientData(list.data[i], list.data[j]);
        }
    }
    swapPatientData(list.data[i + 1], list.data[high]);
    return i + 1;
}

static void quickSortByName(PatientList& list, int low, int high) {
    if (low < high) {
        int pi = partitionByName(list, low, high);
        quickSortByName(list, low, pi - 1);
        quickSortByName(list, pi + 1, high);
    }
}

static int partitionByAge(PatientList& list, int low, int high) {
    int pivot = list.data[high].age;
    int i     = low - 1;
    for (int j = low; j < high; j++) {
        if (list.data[j].age >= pivot) {
            i++;
            swapPatientData(list.data[i], list.data[j]);
        }
    }
    swapPatientData(list.data[i + 1], list.data[high]);
    return i + 1;
}

static void quickSortByAge(PatientList& list, int low, int high) {
    if (low < high) {
        int pi = partitionByAge(list, low, high);
        quickSortByAge(list, low, pi - 1);
        quickSortByAge(list, pi + 1, high);
    }
}

void sortPatientsByName(PatientList& list) {
    if (list.count > 1) {
        quickSortByName(list, 0, list.count - 1);
        cout << "  [OK] Sorted by Name (A to Z) using Quick Sort.\n";
    }
}

void sortPatientsByAge(PatientList& list) {
    if (list.count > 1) {
        quickSortByAge(list, 0, list.count - 1);
        cout << "  [OK] Sorted by Age (descending) using Quick Sort.\n";
    }
}