#ifndef VALIDATE_H
#define VALIDATE_H

#include "Clinic.h"

struct Patient {
    int     id;
    string  name;
    int     age;
    string  gender; // "Nam" hoac "Nu"
    string  symptoms;
};

bool isValidAge(int age);
bool isValidName(const string& name);
bool isValidGender(const string& gender);
bool isValidID(int id, Patient* list, int count);

int    inputAge();
string inputName();
string inputGender();
int    inputID(Patient* list, int count);
string inputSymptoms();

Patient inputPatient(Patient* list, int count);

void showError(const string& msg);
void showSuccess(const string& msg);

#endif