#ifndef REPORTS_H
#define REPORTS_H

#include "Patient.h"

void exportReport(Patient patientList[], int n, int stats[31][12], const string& filename);

#endif