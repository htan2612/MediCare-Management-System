#include "PatientFile.h"
#include "PatientCRUD.h" 
#include <fstream>
#include <iostream>

using namespace std;

void writeString(ofstream& out, const string& str) {
    size_t length = str.length();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(str.c_str(), length);
}

string readString(ifstream& in) {
    size_t length;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    char* buffer = new char[length + 1];
    in.read(buffer, length);
    buffer[length] = '\0';
    string str(buffer);
    delete[] buffer;
    return str;
}

bool savePatientsToBin(const PatientList& list, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cout << "=> Lỗi: Khong the tao/ghi tap tin " << filename << "\n";
        return false;
    }

    out.write(reinterpret_cast<const char*>(&list.count), sizeof(list.count));

    for (int i = 0; i < list.count; i++) {
        writeString(out, list.data[i].id);
        writeString(out, list.data[i].name);
        out.write(reinterpret_cast<const char*>(&list.data[i].age), sizeof(int));
        writeString(out, list.data[i].gender);
        writeString(out, list.data[i].symptoms);
    }

    out.close();
    cout << "=> Da luu file nhi phan thanh cong!\n";
    return true;
}

bool loadPatientsFromBin(PatientList& list, const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cout << "=> Lỗi: Khong tim thay tap tin " << filename << " de doc du lieu (co the file chua ton tai vao lan dau chay)\n";
        return false;
    }

    int fileCount;
    in.read(reinterpret_cast<char*>(&fileCount), sizeof(fileCount));

    while (list.capacity < fileCount) {
        int newCapacity = list.capacity * 2;
        if(newCapacity == 0) newCapacity = 10;
        
        Patient* newData = new Patient[newCapacity];
        for (int i = 0; i < list.count; i++) {
            newData[i] = list.data[i];
        }
        delete[] list.data;
        list.data = newData;
        list.capacity = newCapacity;
    }

    list.count = fileCount;

    for (int i = 0; i < list.count; i++) {
        list.data[i].id = readString(in);
        list.data[i].name = readString(in);
        in.read(reinterpret_cast<char*>(&list.data[i].age), sizeof(int));
        list.data[i].gender = readString(in);
        list.data[i].symptoms = readString(in);
    }

    in.close();
    cout << "=> Đa doc file nhi phan thanh cong (" << fileCount << " ho so)\n";
    return true;
}
