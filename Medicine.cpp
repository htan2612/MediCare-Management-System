#include "Medicine.h"
#include "Clinic.h"
#include <iostream>
#include <iomanip>
using namespace std;

void initMedicineStack(MedicineStack& s) {
    s.top   = nullptr;
    s.count = 0;
}

bool isMedicineStackEmpty(const MedicineStack& s) {
    return s.top == nullptr;
}

void pushMedicine(MedicineStack& s, const MedicineItem& item) {
    MedicineNode* node = new MedicineNode;
    node->data = item;
    node->next = s.top;
    s.top      = node;
    s.count++;
}

bool popMedicine(MedicineStack& s, MedicineItem& outItem) {
    if (isMedicineStackEmpty(s)) return false;
    MedicineNode* tmp = s.top;
    outItem   = tmp->data;
    s.top     = s.top->next;
    delete tmp;
    s.count--;
    return true;
}

void peekMedicine(const MedicineStack& s) {
    if (isMedicineStackEmpty(s)) {
        cout << "  Medicine storage is empty.\n";
        return;
    }
    const MedicineItem& item = s.top->data;
    cout << "  --- TOP OF STACK (Last In) ---\n";
    cout << "  Name        : " << item.name       << "\n";
    cout << "  Quantity    : " << item.quantity    << "\n";
    cout << "  Import Date : " << item.importDate  << "\n";
}

void displayMedicineStack(const MedicineStack& s) {
    if (isMedicineStackEmpty(s)) {
        cout << "  Medicine storage is empty.\n";
        return;
    }

    cout << "\n  " << string(55, '=') << "\n";
    cout << "  " << left << setw(5) << "#" << setw(25) << "Medicine Name" << setw(10) << "Qty" << "Import Date\n";
    cout << "  " << string(55, '-') << "\n";

    MedicineNode* cur = s.top;
    int i = 1;
    while (cur != nullptr) {
        cout << "  " << left << setw(5) << i++ << setw(25) << cur->data.name
             << setw(10) << cur->data.quantity << cur->data.importDate << "\n";
        cur = cur->next;
    }
    cout << "  " << string(55, '=') << "\n";
    cout << "  Total types: " << s.count << "\n";
}

void clearMedicineStack(MedicineStack& s) {
    MedicineNode* cur = s.top;
    while (cur != nullptr) {
        MedicineNode* next = cur->next;
        delete cur;
        cur = next;
    }
    s.top   = nullptr;
    s.count = 0;
}

static void medicinePause() {
    setColor(8);
    cout << "\n  Press any key to continue...";
    resetColor();
    _getch();
    system("cls");
}

void medicineMenu(MedicineStack& s) {
    const char* opts[] = {
        "Import medicine       (Push)   ",
        "Dispense medicine     (Pop)    ",
        "View top of stack     (Peek)   ",
        "View all medicine              ",
        "Back to main menu              "
    };
    const int N = 5;

    while (true) {
        system("cls");
        drawHeader();
        drawFooter(22);

        int choice = runMenu("MEDICINE STORAGE  (Stack - LIFO)", opts, N, 11);
        if (choice == 0 || choice == N) break;

        system("cls");
        printSectionHeader("MEDICINE STORAGE");

        switch (choice) {
            case 1: {
                MedicineItem item;
                cout << "  Medicine Name           : ";
                getline(cin, item.name);
                if (item.name.empty()) {
                    showError("Name cannot be empty.");
                    break;
                }

                cout << "  Quantity                : ";
                while (!(cin >> item.quantity) || item.quantity <= 0) {
                    cin.clear(); cin.ignore(1000, '\n');
                    cout << "  Invalid quantity. Enter a positive number: ";
                }
                cin.ignore();

                cout << "  Import Date (dd/mm/yyyy): ";
                getline(cin, item.importDate);

                pushMedicine(s, item);
                showSuccess("\"" + item.name + "\" added to storage. Total types: "
                            + to_string(s.count) + ".");
                break;
            }
            case 2: {
                MedicineItem out;
                if (popMedicine(s, out)) {
                    showSuccess("Dispensed: " + out.name +
                                "  (Qty: " + to_string(out.quantity) +
                                ", Imported: " + out.importDate + ")");
                } else {
                    showError("Storage is empty - nothing to dispense.");
                }
                break;
            }
            case 3:
                peekMedicine(s);
                break;
            case 4:
                displayMedicineStack(s);
                break;
        }
        medicinePause();
    }
}