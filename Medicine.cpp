#include "Medicine.h"
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

void medicineMenu(MedicineStack& s) {
    int choice;
    do {
        cout << "\n  +------------------------------------------+\n";
        cout << "  |    MEDICINE STORAGE  (Stack - LIFO)      |\n";
        cout << "  +------------------------------------------+\n";
        cout << "  |  1. Import medicine (Push)               |\n";
        cout << "  |  2. Dispense medicine (Pop - LIFO)       |\n";
        cout << "  |  3. View top of stack (Peek)             |\n";
        cout << "  |  4. View all medicine                    |\n";
        cout << "  |  0. Back to main menu                    |\n";
        cout << "  +------------------------------------------+\n";
        cout << "  Choice (0-4): ";
        cin >> choice;
        cin.ignore();
        cout << "\n";

        if (choice == 1) {
            MedicineItem item;
            cout << "  Medicine Name  : "; getline(cin, item.name);
            if (item.name.empty()) { cout << "  [!] Name cannot be empty.\n"; continue; }

            cout << "  Quantity       : ";
            while (!(cin >> item.quantity) || item.quantity <= 0) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "  Invalid quantity. Try again: ";
            }
            cin.ignore();

            cout << "  Import Date (dd/mm/yyyy): "; getline(cin, item.importDate);
            pushMedicine(s, item);
            cout << "  [OK] \"" << item.name << "\" added to storage.\n";

        } else if (choice == 2) {
            MedicineItem out;
            if (popMedicine(s, out)) {
                cout << "  [OK] Dispensed: " << out.name
                     << "  (Qty: " << out.quantity
                     << ", Imported: " << out.importDate << ")\n";
            } else {
                cout << "  [!] Storage is empty.\n";
            }
        } else if (choice == 3) {
            peekMedicine(s);
        } else if (choice == 4) {
            displayMedicineStack(s);
        } else if (choice != 0) {
            cout << "  [!] Invalid choice.\n";
        }

        if (choice != 0) { cout << "\n  Press any key to continue..."; cin.get(); system("cls"); }
    } while (choice != 0);
}