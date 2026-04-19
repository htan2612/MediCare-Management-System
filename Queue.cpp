#include <iostream>
#include "Queue.h"

using namespace std;

void initQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

bool isEmpty(Queue q) {
    return q.front == nullptr;
}

void enqueue(Queue& q, Patient p) {
    QueueNode* newNode = new QueueNode;
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

void displayQueue(Queue q) {
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