#include "Statistics.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void buildStats(Patient patientList[], int n, int stats[31][12]) {
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 12; j++)
            stats[i][j] = 0;

    for (int i = 0; i < n; i++) {
        VisitNode* cur = patientList[i].historyHead;

        while (cur != nullptr) {
            string date = cur->date;
            if (date.size() < 5) { 
                cur = cur->next; 
                continue;  
            }
            int day   = stoi(date.substr(0, 2));
            int month = stoi(date.substr(3, 2));

            if (day >= 1 && day <= 31 && month >= 1 && month <= 12) {
                stats[day - 1][month - 1]++;
            }

            cur = cur->next;
        }
    }
}

void displayStats(int stats[31][12]) {
    cout << "\nTHONG KE CA KHAM THEO NGAY VA THANG\n";

    cout << setw(6) << "Ngay";
    for (int m = 1; m <= 12; m++)
        cout << setw(6) << "T" + to_string(m);
    cout << "\n";

    for (int d = 0; d < 31; d++) {
        bool hasData = false;
        for (int m = 0; m < 12; m++)
            if (stats[d][m] > 0) { hasData = true; break; }
        if (!hasData) continue;

        cout << setw(6) << (d + 1);
        for (int m = 0; m < 12; m++)
            cout << setw(6) << stats[d][m];
        cout << "\n";
    }
}