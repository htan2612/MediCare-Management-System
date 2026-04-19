#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include "Patient.h"

//  thêm lại trường symptoms (Triệu chứng)cho đúng yêu cầu ban đầu
struct VisitNode {
    std::string date;
    std::string symptoms;     
    std::string diagnosis;
    std::string prescription;
    VisitNode* next;
};

// Khai báo các hàm
VisitNode* createVisitNode(const std::string& date, const std::string& symptoms, const std::string& diagnosis, const std::string& prescription);
void initHistory(Patient& p);
void addVisitHistory(Patient& p, const std::string& date, const std::string& symptoms, const std::string& diagnosis, const std::string& prescription);
void displayVisitHistory(const Patient& p);
void deleteVisitHistory(Patient& p); // Hàm mới: Xóa lịch sử để giải phóng bộ nhớ

#endif