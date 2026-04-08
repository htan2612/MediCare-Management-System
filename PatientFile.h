#ifndef PATIENTFILE_H
#define PATIENTFILE_H

#include "Patient.h"
#include <string>

using namespace std;

bool savePatientsToBin(const PatientList& list, const string& filename);

bool loadPatientsFromBin(PatientList& list, const string& filename);

#endif
