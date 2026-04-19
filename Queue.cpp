#include <iostream>
#include "Queue.h"

using namespace std;

void initQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

// Dùng const Queue& để tránh copy shallow, tăng tính chuyên nghiệp
bool isEmpty(const Queue& q) {
    return q.front == nullptr;
}

// Dùng const Patient& p để chống sao chép dữ liệu thừa
void enqueue(Queue& q, const Patient& p) {
    QueueNode* newNode = new QueueNode;
    
    // Kiểm tra cấp phát bộ nhớ (Điểm cộng kỹ thuật)
    if (newNode == nullptr) {
        cout << "Lỗi: Không đủ bộ nhớ để thêm bệnh nhân!" << endl;
        return;
    }

    newNode->data = p;
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q.front = newNode;
        q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

bool dequeue(Queue& q, Patient& outPatient) {
    if (isEmpty(q)) return false; 
    
    QueueNode* temp = q.front;
    outPatient = temp->data;
    q.front = q.front->next;

    if (q.front == nullptr) {
        q.rear = nullptr;
    }

    delete temp;
    return true;
}

// Dùng const Queue&
void displayQueue(const Queue& q) {
    if (isEmpty(q)) {
        cout << "Hàng đợi hiện đang trống. Không có bệnh nhân nào đang chờ." << endl;
        return;
    }
    
    QueueNode* current = q.front;
    int count = 1;
    cout << "--- Danh sách bệnh nhân đang chờ khám ---" << endl;
    while (current != nullptr) {
        cout << count++ << ". ID: " << current->data.id 
             << " | Họ tên: " << current->data.name << endl;
        current = current->next;
    }
}

// HÀM MỚI: Dọn dẹp toàn bộ hàng đợi để tránh Memory Leak
void clearQueue(Queue& q) {
    QueueNode* current = q.front;
    while (current != nullptr) {
        QueueNode* nextNode = current->next;
        delete current; // Giải phóng từng người trong hàng
        current = nextNode;
    }
    q.front = nullptr;
    q.rear = nullptr;
}