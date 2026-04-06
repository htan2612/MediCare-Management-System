#ifndef STATISTICS_H
#define STATISTICS_H

#include "Patient.h"
#include "History.h"

void buildStats(Patient patientList[], int n, int stats[31][12]);
void displayStats(int stats[31][12]);

#endif