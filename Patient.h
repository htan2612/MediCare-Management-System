#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct VisitNode; // Forward declaration

struct Patient {
    string id;
    string name;
    int age;
    string gender;
    string symptoms;
    VisitNode* historyHead = nullptr;
};

struct PatientList {
    Patient* data;
    int count;
    int capacity;
};

#endif