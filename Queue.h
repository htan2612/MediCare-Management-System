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
bool isEmpty(Queue q);
void enqueue(Queue& q, Patient p);
bool dequeue(Queue& q, Patient& outPatient);
void displayQueue(Queue q);

#endif