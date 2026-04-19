#include <iostream>
#include "History.h"

using namespace std;

// Hàm hỗ trợ tạo Node mới (để code hàm add gọn hơn)
VisitNode* createVisitNode(const string& date, const string& symptoms, const string& diagnosis, const string& prescription) {
    VisitNode* newNode = new VisitNode;
    newNode->date = date;
    newNode->symptoms = symptoms;
    newNode->diagnosis = diagnosis;
    newNode->prescription = prescription;
    newNode->next = nullptr;
    return newNode;
}

// Khởi tạo lịch sử rỗng
void initHistory(Patient& p) {
    p.historyHead = nullptr;
}

// Thêm lịch sử khám vào cuối danh sách
void addVisitHistory(Patient& p, const string& date, const string& symptoms, const string& diagnosis, const string& prescription) {
    VisitNode* newNode = createVisitNode(date, symptoms, diagnosis, prescription);

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

// Hiển thị lịch sử khám
void displayVisitHistory(const Patient& p) {
    if (p.historyHead == nullptr) {
        cout << "Bệnh nhân " << p.name << " (ID: " << p.id << ") chưa có lịch sử khám bệnh." << endl;
        return;
    }

    cout << "=== LỊCH SỬ KHÁM BỆNH ===" << endl;
    cout << "Bệnh nhân: " << p.name << " | ID: " << p.id << endl;
    
    VisitNode* current = p.historyHead;
    int visitCount = 1;

    while (current != nullptr) {
        cout << "\n--- Lần khám thứ " << visitCount++ << " ---" << endl;
        cout << "+ Ngày khám   : " << current->date << endl;
        cout << "+ Triệu chứng : " << current->symptoms << endl;
        cout << "+ Chẩn đoán   : " << current->diagnosis << endl;
        cout << "+ Đơn thuốc   : " << current->prescription << endl;
        
        current = current->next;
    }
    cout << "=========================" << endl;
}

// Xóa toàn bộ lịch sử khám của một bệnh nhân (Tránh Memory Leak)
void deleteVisitHistory(Patient& p) {
    VisitNode* current = p.historyHead;
    while (current != nullptr) {
        VisitNode* nextNode = current->next; // Giữ lại địa chỉ node tiếp theo
        delete current;                      // Giải phóng node hiện tại
        current = nextNode;                  // Di chuyển sang node tiếp theo
    }
    p.historyHead = nullptr; // Đặt lại con trỏ đầu về null
}