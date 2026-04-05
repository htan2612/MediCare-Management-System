#include "History.h"

VisitNode* createVisitNode(const string& date, const string& diagnosis, const string& prescription) {
    VisitNode* node = new VisitNode;
    node->date = date;
    node->diagnosis = diagnosis;
    node->prescription = prescription;
    node->next = nullptr;
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

    VisitNode* current = p.historyHead;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

void displayVisitHistory(const Patient& p) {
    if (p.historyHead == nullptr) {
        cout << "Bệnh nhân chưa có lịch sử khám.\n";
        return;
    }

    VisitNode* current = p.historyHead;
    int stt = 1;

    cout << "\n===== LỊCH SỬ KHÁM =====\n";
    while (current != nullptr) {
        cout << "Lần khám " << stt++ << ":\n";
        cout << "Ngày khám: " << current->date << endl;
        cout << "Chẩn đoán: " << current->diagnosis << endl;
        cout << "Đơn thuốc: " << current->prescription << endl;
        cout << "-------------------------\n";
        current = current->next;
    }
}

void deleteVisitHistory(Patient& p) {
    VisitNode* current = p.historyHead;

    while (current != nullptr) {
        VisitNode* temp = current;
        current = current->next;
        delete temp;
    }

    p.historyHead = nullptr;
}