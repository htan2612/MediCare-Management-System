#ifndef PATIENTCRUD_H
#define PATIENTCRUD_H

#include "Patient.h"

void initPatientList(PatientList& list, int capacity = 10);

void freePatientList(PatientList& list);

void addPatient(PatientList& list);
void displayAllPatients(const PatientList& list);
void updatePatient(PatientList& list, const string& id);
void deletePatient(PatientList& list, const string& id);

#endif
