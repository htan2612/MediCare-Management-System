#include "History.h"
#include "Patient.h"
#include <iostream>
using namespace std;

VisitNode* createVisitNode(const string& date, const string& diagnosis, const string& prescription) {
    VisitNode* node = new VisitNode;
    node->date         = date;
    node->diagnosis    = diagnosis;
    node->prescription = prescription;
    node->next         = nullptr;
    return node;
}

void initHistory(Patient& p) {
    p.historyHead = nullptr;
}

void addVisitHistory(Patient& p, const string& date, const string& diagnosis, const string& prescription) {
    VisitNode* newNode = createVisitNode(date, diagnosis, prescription);

    if (p.historyHead == nullptr) {
        p.historyHead = newNode;
        return;
    }

    VisitNode* cur = p.historyHead;
    while (cur->next != nullptr)
        cur = cur->next;
    cur->next = newNode;
}

void displayVisitHistory(const Patient& p) {
    if (p.historyHead == nullptr) {
        cout << "  No visit history found for this patient.\n";
        return;
    }

    VisitNode* cur = p.historyHead;
    int visit = 1;
    cout << "\n  ===== VISIT HISTORY =====\n";
    while (cur != nullptr) {
        cout << "  Visit #" << visit++ << ":\n";
        cout << "    Date         : " << cur->date         << "\n";
        cout << "    Diagnosis    : " << cur->diagnosis    << "\n";
        cout << "    Prescription : " << cur->prescription << "\n";
        cout << "  " << string(30, '-') << "\n";
        cur = cur->next;
    }
}

void deleteVisitHistory(Patient& p) {
    VisitNode* cur = p.historyHead;
    while (cur != nullptr) {
        VisitNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    p.historyHead = nullptr;
}