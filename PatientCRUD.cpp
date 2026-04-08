#include "PatientCRUD.h"
#include <iostream>
#include <iomanip>

using namespace std;

void initPatientList(PatientList& list, int capacity) {
    list.capacity = capacity;
    list.count = 0;
    list.data = new Patient[list.capacity];
}

void freePatientList(PatientList& list) {
    if (list.data != nullptr) {
        delete[] list.data;
        list.data = nullptr;
    }
    list.count = 0;
    list.capacity = 0;
}

void resizePatientList(PatientList& list) {
    int newCapacity = list.capacity * 2;
    Patient* newData = new Patient[newCapacity];
    for (int i = 0; i < list.count; i++) {
        newData[i] = list.data[i];
    }
    delete[] list.data;
    list.data = newData;
    list.capacity = newCapacity;
}

void addPatient(PatientList& list) {
    if (list.count >= list.capacity) {
        resizePatientList(list);
    }
    
    Patient p;
    cout << "--- THEM BENH NHAN MOI ---\n";
    cout << "Nhap ID: ";
    cin >> p.id;
    cin.ignore();
    
    cout << "Nhap Ten: ";
    getline(cin, p.name);
    
    cout << "Nhap Tuoi: ";
    cin >> p.age;
    cin.ignore();
    
    cout << "Nhap Gioi tinh: ";
    getline(cin, p.gender);
    
    cout << "Nhap Trieu chung: ";
    getline(cin, p.symptoms);
    
    list.data[list.count] = p;
    list.count++;
    
    cout << "=> Them benh nhan thanh cong!\n";
}

void displayAllPatients(const PatientList& list) {
    if (list.count == 0) {
        cout << "=> Danh sach benh nhan hien dang trong!\n";
        return;
    }
    
    cout << string(85, '-') << "\n";
    cout << left << setw(10) << "ID" 
         << setw(25) << "Ten" 
         << setw(10) << "Tuoi" 
         << setw(15) << "Gioi Tinh" 
         << setw(25) << "Trieu Chung" << "\n";
    cout << string(85, '-') << "\n";
    
    for (int i = 0; i < list.count; i++) {
        cout << left << setw(10) << list.data[i].id
             << setw(25) << list.data[i].name
             << setw(10) << list.data[i].age
             << setw(15) << list.data[i].gender
             << setw(25) << list.data[i].symptoms << "\n";
    }
    cout << string(85, '-') << "\n";
    cout << "Tong cong: " << list.count << " benh nhan.\n";
}

void updatePatient(PatientList& list, const string& id) {
    for (int i = 0; i < list.count; i++) {
        if (list.data[i].id == id) {
            cout << "--- SUA THONG TIN TRANG THAI --- (ID: " << id << ")\n";
            cin.ignore();
            cout << "Nhap Ten moi (sua thanh: ): ";
            getline(cin, list.data[i].name);
            
            cout << "Nhap Tuoi moi: ";
            cin >> list.data[i].age;
            cin.ignore();
            
            cout << "Nhap Gioi tinh moi: ";
            getline(cin, list.data[i].gender);
            
            cout << "Nhap Trieu chung moi: ";
            getline(cin, list.data[i].symptoms);
            
            cout << "=> Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "=> Khong tim thay benh nhan voi ID nay.\n";
}

void deletePatient(PatientList& list, const string& id) {
    for (int i = 0; i < list.count; i++) {
        if (list.data[i].id == id) {
            for (int j = i; j < list.count - 1; j++) {
                list.data[j] = list.data[j + 1];
            }
            list.count--;
            cout << "=> Xoa benh nhan thanh cong!\n";
            return;
        }
    }
    cout << "=> Khong tim thay benh nhan voi ID nay de xoa.\n";
}
