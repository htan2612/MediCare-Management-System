#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <string>
#include "Patient.h"
using namespace std;

struct VisitNode {
    string date;
    string diagnosis;
    string prescription;
    VisitNode* next;
};

VisitNode* createVisitNode(const string& date, const string& diagnosis, const string& prescription);
void initHistory(Patient& p);
void addVisitHistory(Patient& p, const string& date, const string& diagnosis, const string& prescription);
void displayVisitHistory(const Patient& p);
void deleteVisitHistory(Patient& p);

#endif