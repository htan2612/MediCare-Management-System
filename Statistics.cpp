#include "Statistics.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

static bool parseDate(const string& date, int& day, int& month) {
    if (date.length() < 10)              return false;
    if (date[2] != '/' || date[5] != '/') return false;
    try {
        day   = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
    } catch (...) { return false; }
    return (day >= 1 && day <= 31 && month >= 1 && month <= 12);
}

void buildStats(Patient patientList[], int n, int stats[31][12]) {
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 12; j++)
            stats[i][j] = 0;

    for (int i = 0; i < n; i++) {
        VisitNode* cur = patientList[i].historyHead;
        while (cur != nullptr) {
            int day = 0, month = 0;
            if (parseDate(cur->date, day, month))
                stats[day - 1][month - 1]++;
            cur = cur->next;
        }
    }
}

void displayStats(int stats[31][12]) {
    bool hasAny = false;
    for (int d = 0; d < 31 && !hasAny; d++)
        for (int m = 0; m < 12 && !hasAny; m++)
            if (stats[d][m] > 0) hasAny = true;

    if (!hasAny) {
        cout << "  No visit history available for statistics.\n";
        return;
    }

    cout << "\n  ===== VISIT STATISTICS BY DAY & MONTH =====\n\n";
    cout << "  " << setw(6) << "Day";
    for (int m = 1; m <= 12; m++)
        cout << setw(5) << ("M" + to_string(m));
    cout << "\n  " << string(66, '-') << "\n";

    for (int d = 0; d < 31; d++) {
        bool hasData = false;
        for (int m = 0; m < 12; m++)
            if (stats[d][m] > 0) { hasData = true; break; }
        if (!hasData) continue;

        cout << "  " << setw(6) << (d + 1);
        for (int m = 0; m < 12; m++)
            cout << setw(5) << stats[d][m];
        cout << "\n";
    }
    cout << "  " << string(66, '-') << "\n";
}