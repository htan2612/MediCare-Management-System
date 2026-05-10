#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>
using namespace std;

struct MedicineItem {
    string name;
    int    quantity;
    string importDate;
};

struct MedicineNode {
    MedicineItem  data;
    MedicineNode* next;
};

struct MedicineStack {
    MedicineNode* top;
    int count;
};

void initMedicineStack(MedicineStack& s);
bool isMedicineStackEmpty(const MedicineStack& s);
void pushMedicine(MedicineStack& s, const MedicineItem& item);
bool popMedicine(MedicineStack& s, MedicineItem& outItem);
void peekMedicine(const MedicineStack& s);
void displayMedicineStack(const MedicineStack& s);
void clearMedicineStack(MedicineStack& s);
void medicineMenu(MedicineStack& s);

#endif