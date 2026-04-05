#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct VisitNode;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string symptom;
    VisitNode* historyHead;
};

const int MAX_PATIENTS = 100;

int findPatientById(Patient patientList[], int n, int id);
void setupSamplePatients(Patient patientList[], int& n);

#endif