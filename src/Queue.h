#ifndef QUEUE_H
#define QUEUE_H

#include "Patient.h"

struct QueueNode {
    string patientId;
    string patientName;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int count;
};

void initQueue(Queue& q);
bool isQueueEmpty(const Queue& q);
void enqueue(Queue& q, const Patient& p);
bool dequeue(Queue& q, string& outId, string& outName);
void displayQueue(const Queue& q);
void clearQueue(Queue& q);

#endif