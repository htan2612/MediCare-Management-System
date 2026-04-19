#ifndef QUEUE_H
#define QUEUE_H

#include "Patient.h"

struct QueueNode {
    Patient data;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

void initQueue(Queue& q);
bool isEmpty(const Queue& q); // Thêm const &
void enqueue(Queue& q, const Patient& p); // Thêm const &
bool dequeue(Queue& q, Patient& outPatient);
void displayQueue(const Queue& q); // Thêm const &
void clearQueue(Queue& q); // Hàm mới thêm

#endif