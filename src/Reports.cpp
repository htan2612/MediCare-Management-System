#include "Reports.h"
#include "History.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void exportReport(Patient patientList[], int n, int stats[31][12], const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "  [!] Cannot create file: " << filename << "\n";
        return;
    }

    time_t now = time(nullptr);
    char timebuf[64];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", localtime(&now));

    file << "============================================================\n";
    file << "             CLINIC MANAGEMENT SYSTEM — REPORT\n";
    file << "============================================================\n";
    file << "  Generated : " << timebuf << "\n";
    file << "  Total Patients : " << n << "\n";
    file << "============================================================\n\n";

    file << "------------------------------------------------------------\n";
    file << "  SECTION 1 — PATIENT RECORDS\n";
    file << "------------------------------------------------------------\n";
    file << left
         << setw(12) << "ID"
         << setw(24) << "Full Name"
         << setw(7)  << "Age"
         << setw(12) << "Gender"
         << "Symptoms\n";
    file << string(80, '-') << "\n";

    for (int i = 0; i < n; i++) {
        const Patient& p = patientList[i];
        file << left
             << setw(12) << p.id
             << setw(24) << p.name
             << setw(7)  << p.age
             << setw(12) << p.gender
             << p.symptoms << "\n";
    }

    file << "\n------------------------------------------------------------\n";
    file << "  SECTION 2 — VISIT HISTORIES\n";
    file << "------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        const Patient& p = patientList[i];
        if (p.historyHead == nullptr) continue;

        file << "\n  Patient: " << p.name << "  (ID: " << p.id << ")\n";
        file << "  " << string(40, '-') << "\n";

        VisitNode* cur = p.historyHead;
        int v = 1;
        while (cur) {
            file << "  Visit #" << v++ << " — " << cur->date << "\n";
            file << "    Diagnosis    : " << cur->diagnosis    << "\n";
            file << "    Prescription : " << cur->prescription << "\n";
            cur = cur->next;
        }
    }

    file << "\n------------------------------------------------------------\n";
    file << "  SECTION 3 — VISIT STATISTICS (BY DAY & MONTH)\n";
    file << "------------------------------------------------------------\n";
    file << setw(6) << "Day";
    for (int m = 1; m <= 12; m++)
        file << setw(5) << ("M" + to_string(m));
    file << "\n" << string(66, '-') << "\n";

    for (int d = 0; d < 31; d++) {
        bool hasData = false;
        for (int m = 0; m < 12; m++)
            if (stats[d][m] > 0) { hasData = true; break; }
        if (!hasData) continue;

        file << setw(6) << (d + 1);
        for (int m = 0; m < 12; m++)
            file << setw(5) << stats[d][m];
        file << "\n";
    }

    file << "\n============================================================\n";
    file << "                     END OF REPORT\n";
    file << "============================================================\n";

    file.close();
    cout << "  [OK] Report exported to \"" << filename << "\"\n";
}