#include "PatientFile.h"
#include "PatientCRUD.h"
#include "History.h"
#include <fstream>
#include <iostream>
using namespace std;

static void writeString(ofstream& out, const string& str) {
    size_t len = str.length();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(str.c_str(), len);
}

static string readString(ifstream& in) {
    size_t len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!in || len == 0) return "";
    char* buf = new char[len + 1];
    in.read(buf, len);
    buf[len] = '\0';
    string str(buf);
    delete[] buf;
    return str;
}

bool savePatientsToBin(const PatientList& list, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cout << "  [!] Error: Cannot write to file " << filename << "\n";
        return false;
    }

    out.write(reinterpret_cast<const char*>(&list.count), sizeof(list.count));

    for (int i = 0; i < list.count; i++) {
        const Patient& p = list.data[i];
        writeString(out, p.id);
        writeString(out, p.name);
        out.write(reinterpret_cast<const char*>(&p.age), sizeof(int));
        writeString(out, p.gender);
        writeString(out, p.symptoms);

        int visitCount = 0;
        VisitNode* cur = p.historyHead;
        while (cur) { visitCount++; cur = cur->next; }
        out.write(reinterpret_cast<const char*>(&visitCount), sizeof(int));

        cur = p.historyHead;
        while (cur) {
            writeString(out, cur->date);
            writeString(out, cur->diagnosis);
            writeString(out, cur->prescription);
            cur = cur->next;
        }
    }

    out.close();
    cout << "  [OK] Saved " << list.count << " patient(s) to \"" << filename << "\".\n";
    return true;
}

bool loadPatientsFromBin(PatientList& list, const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cout << "  [i] No save file found. A new file will be created on exit.\n";
        return false;
    }

    int fileCount = 0;
    in.read(reinterpret_cast<char*>(&fileCount), sizeof(fileCount));
    if (!in || fileCount < 0) {
        cout << "  [!] Save file is corrupted.\n";
        return false;
    }

    while (list.capacity < fileCount) {
        int newCap   = list.capacity * 2;
        if (newCap == 0) newCap = 10;
        Patient* nd  = new Patient[newCap];
        for (int i   = 0; i < list.count; i++) nd[i] = list.data[i];
        delete[] list.data;
        list.data     = nd;
        list.capacity = newCap;
    }

    list.count = fileCount;
    for (int i = 0; i < list.count; i++) {
        Patient& p    = list.data[i];
        p.historyHead = nullptr;

        p.id       = readString(in);
        p.name     = readString(in);
        in.read(reinterpret_cast<char*>(&p.age), sizeof(int));
        p.gender   = readString(in);
        p.symptoms = readString(in);

        int visitCount = 0;
        in.read(reinterpret_cast<char*>(&visitCount), sizeof(int));
        for (int v = 0; v < visitCount; v++) {
            string date  = readString(in);
            string diag  = readString(in);
            string presc = readString(in);
            addVisitHistory(p, date, diag, presc);
        }
    }

    in.close();
    cout << "  [OK] Loaded " << fileCount << " patient(s) from \"" << filename << "\".\n";
    return true;
}