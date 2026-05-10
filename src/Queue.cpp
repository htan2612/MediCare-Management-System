#include "Queue.h"
#include <iostream>
#include <iomanip>
using namespace std;

void initQueue(Queue& q) {
    q.front = nullptr;
    q.rear  = nullptr;
    q.count = 0;
}

bool isQueueEmpty(const Queue& q) {
    return q.front == nullptr;
}

void enqueue(Queue& q, const Patient& p) {
    QueueNode* node    = new QueueNode;
    node->patientId    = p.id;
    node->patientName  = p.name;
    node->next         = nullptr;

    if (isQueueEmpty(q)) {
        q.front = node;
        q.rear  = node;
    } else {
        q.rear->next = node;
        q.rear       = node;
    }
    q.count++;
}

bool dequeue(Queue& q, string& outId, string& outName) {
    if (isQueueEmpty(q)) return false;
    QueueNode* tmp = q.front;
    outId   = tmp->patientId;
    outName = tmp->patientName;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete tmp;
    q.count--;
    return true;
}

void displayQueue(const Queue& q) {
    if (isQueueEmpty(q)) {
        cout << "  Waiting queue is empty.\n";
        return;
    }

    cout << "\n  " << string(45, '=') << "\n";
    cout << "  " << left << setw(6) << "#" << setw(14) << "Patient ID" << "Full Name\n";
    cout << "  " << string(45, '-') << "\n";

    QueueNode* cur = q.front;
    int stt = 1;
    while (cur != nullptr) {
        cout << "  " << left << setw(6) << stt++ << setw(14) << cur->patientId << cur->patientName << "\n";
        cur = cur->next;
    }
    cout << "  " << string(45, '=') << "\n";
    cout << "  Patients waiting: " << q.count << "\n";
}

void clearQueue(Queue& q) {
    QueueNode* cur = q.front;
    while (cur != nullptr) {
        QueueNode* next = cur->next;
        delete cur;
        cur = next;
    }
    q.front = nullptr;
    q.rear  = nullptr;
    q.count = 0;
}