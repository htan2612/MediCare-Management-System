#include "PatientSearchSort.h"
#include <iostream>
#include <iomanip>

using namespace std;

void printSinglePatient(const Patient& p) {
    cout << left << setw(10) << p.id
         << setw(25) << p.name
         << setw(10) << p.age
         << setw(15) << p.gender
         << setw(25) << p.symptoms << "\n";
}

Patient* searchPatientByID(const PatientList& list, const string& id) {
    for (int i = 0; i < list.count; i++) {
        if (list.data[i].id == id) {
            return &list.data[i];
        }
    }
    return nullptr; 
}

void searchPatientByName(const PatientList& list, const string& name) {
    cout << "--- KET QUA TIM KIEM THEO TEN: " << name << " ---\n";
    bool found = false;
    for (int i = 0; i < list.count; i++) {
        if (list.data[i].name.find(name) != string::npos) {
            if(!found){ // In header 1 lần
                cout << string(85, '-') << "\n";
                cout << left << setw(10) << "ID" << setw(25) << "Ten" << setw(10) << "Tuoi" 
                     << setw(15) << "Gioi Tinh" << setw(25) << "Trieu Chung" << "\n";
                cout << string(85, '-') << "\n";
            }
            printSinglePatient(list.data[i]);
            found = true;
        }
    }
    if(found) cout << string(85, '-') << "\n";
    else cout << "=> Khong tim thay benh nhan nao phu hop.\n";
}

void swapPatients(Patient* a, Patient* b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

int partitionByAge(PatientList& list, int low, int high) {
    int pivot = list.data[high].age; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (list.data[j].age >= pivot) { 
            i++; 
            swapPatients(&list.data[i], &list.data[j]);
        }
    }
    swapPatients(&list.data[i + 1], &list.data[high]);
    return (i + 1);
}

void quickSortByAge(PatientList& list, int low, int high) {
    if (low < high) {
        int pi = partitionByAge(list, low, high);
        quickSortByAge(list, low, pi - 1);
        quickSortByAge(list, pi + 1, high);
    }
}

int partitionByName(PatientList& list, int low, int high) {
    string pivot = list.data[high].name; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (list.data[j].name <= pivot) { // A-Z (tăng dần)
            i++; 
            swapPatients(&list.data[i], &list.data[j]);
        }
    }
    swapPatients(&list.data[i + 1], &list.data[high]);
    return (i + 1);
}

void quickSortByName(PatientList& list, int low, int high) {
    if (low < high) {
        int pi = partitionByName(list, low, high);
        quickSortByName(list, low, pi - 1);
        quickSortByName(list, pi + 1, high);
    }
}

void sortPatientsByName(PatientList& list) {
    if(list.count > 1) {
        quickSortByName(list, 0, list.count - 1);
        cout << "=> Da sap xep danh sach benh nhan theo Ten (tu A-Z) bang Quick Sort.\n";
    }
}

void sortPatientsByAge(PatientList& list) {
    if(list.count > 1) {
        quickSortByAge(list, 0, list.count - 1);
        cout << "=> Da sap xep danh sach benh nhan theo Tuoi (Giam dan) bang Quick Sort.\n";
    }
}
