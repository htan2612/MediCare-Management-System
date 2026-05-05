#include "Reports.h"
#include "History.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void exportReport(Patient patientList[], int n, int stats[31][12], const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Loi: Khong the tao file " << filename << "\n";
        return;
    }

    file << "===========================================\n";
    file << "         DANH SACH BENH NHAN\n";
    file << "===========================================\n";
    file << left
         << setw(6)  << "ID"
         << setw(20) << "Ho ten"
         << setw(6)  << "Tuoi"
         << setw(10) << "Gioi tinh"
         << "Trieu chung\n";
    file << "-------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        Patient& p = patientList[i];
        file << left
             << setw(6)  << p.id
             << setw(20) << p.name
             << setw(6)  << p.age
             << setw(10) << p.gender
             << p.symptom << "\n";
    }

    file << "\n===========================================\n";
    file << "   THONG KE CA KHAM THEO NGAY VA THANG\n";
    file << "===========================================\n";

    file << setw(6) << "Ngay";
    for (int m = 1; m <= 12; m++)
        file << setw(6) << ("T" + to_string(m));
    file << "\n";
    file << "-------------------------------------------\n";

    for (int d = 0; d < 31; d++) {
        bool hasData = false;
        for (int m = 0; m < 12; m++)
            if (stats[d][m] > 0) { hasData = true; break; }
        if (!hasData) continue;

        file << setw(6) << (d + 1);
        for (int m = 0; m < 12; m++)
            file << setw(6) << stats[d][m];
        file << "\n";
    }

    file << "\n===========================================\n";
    file << "           END OF REPORT\n";
    file << "===========================================\n";

    file.close();
    cout << "Xuat bao cao thanh cong: " << filename << "\n";
}