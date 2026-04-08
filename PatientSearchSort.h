#ifndef PATIENTSEARCHSORT_H
#define PATIENTSEARCHSORT_H

#include "Patient.h"

Patient* searchPatientByID(const PatientList& list, const string& id);
void searchPatientByName(const PatientList& list, const string& name);

void sortPatientsByName(PatientList& list);
void sortPatientsByAge(PatientList& list);

#endif
