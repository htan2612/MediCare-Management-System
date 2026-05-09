#include "Clinic.h"
#include "Medicine.h"
#include "Statistics.h"
#include "Reports.h"
#include <iostream>
#include <iomanip>
using namespace std;

// -----------------------------------------------
//  HELPERS
// -----------------------------------------------

static void pause() {
    setColor(8);
    cout << "\n  Press any key to continue...";
    resetColor();
    _getch();
    system("cls");
}

// -----------------------------------------------
//  MENU 1 - PATIENT MANAGEMENT
// -----------------------------------------------

static void menuPatient(PatientList& pl) {
    const char* opts[] = {
        "Add new patient                ",
        "View all patients              ",
        "Edit patient record            ",
        "Delete patient                 ",
        "Search by name                 ",
        "Search by ID                   ",
        "Sort by Name  (A to Z)         ",
        "Sort by Age   (oldest first)   ",
        "Back to main menu              "
    };
    const int N = 9;

    while (true) {
        system("cls");
        drawHeader();
        drawFooter(22);

        int choice = runMenu("PATIENT MANAGEMENT", opts, N, 10);
        if (choice == 0 || choice == N) break;

        system("cls");
        printSectionHeader("PATIENT MANAGEMENT");

        switch (choice) {
            case 1:
                addPatient(pl);
                break;
            case 2:
                displayAllPatients(pl);
                break;
            case 3: {
                string id;
                cout << "  Patient ID to edit: "; cin >> id; cin.ignore();
                updatePatient(pl, id);
                break;
            }
            case 4: {
                string id;
                cout << "  Patient ID to delete: "; cin >> id; cin.ignore();
                deletePatient(pl, id);
                break;
            }
            case 5: {
                string name;
                cout << "  Search name: "; getline(cin, name);
                searchPatientByName(pl, name);
                break;
            }
            case 6: {
                string id;
                cout << "  Search ID: "; cin >> id; cin.ignore();
                Patient* p = searchPatientByID(pl, id);
                if (p) {
                    cout << "\n  " << string(85, '=') << "\n";
                    cout << "  " << left
                         << setw(12) << "ID" << setw(26) << "Full Name"
                         << setw(7)  << "Age" << setw(12) << "Gender"
                         << "Symptoms\n";
                    cout << "  " << string(85, '-') << "\n";
                    cout << "  ";
                    printSinglePatient(*p);
                    cout << "  " << string(85, '=') << "\n";
                } else {
                    showError("Patient with ID \"" + id + "\" not found.");
                }
                break;
            }
            case 7:
                sortPatientsByName(pl);
                displayAllPatients(pl);
                break;
            case 8:
                sortPatientsByAge(pl);
                displayAllPatients(pl);
                break;
        }
        pause();
    }
}

// -----------------------------------------------
//  MENU 2 - EXAMINATION QUEUE
// -----------------------------------------------

static void menuQueue(Queue& q, PatientList& pl) {
    const char* opts[] = {
        "Add patient to queue  (Enqueue)",
        "Call next patient     (Dequeue)",
        "View waiting list              ",
        "Back to main menu              "
    };
    const int N = 4;

    while (true) {
        system("cls");
        drawHeader();
        drawFooter(22);

        int choice = runMenu("EXAMINATION QUEUE  (FIFO)", opts, N, 11);
        if (choice == 0 || choice == N) break;

        system("cls");
        printSectionHeader("EXAMINATION QUEUE");

        switch (choice) {
            case 1: {
                string id;
                cout << "  Patient ID: "; cin >> id; cin.ignore();
                Patient* p = searchPatientByID(pl, id);
                if (p) {
                    enqueue(q, *p);
                    showSuccess(p->name + " added to queue. Waiting: " + to_string(q.count) + " patient(s).");
                } else {
                    showError("Patient with ID \"" + id + "\" not found.");
                }
                break;
            }
            case 2: {
                string outId, outName;
                if (dequeue(q, outId, outName)) {
                    showInfo("Now calling: " + outName + "  (ID: " + outId + ")");
                    cout << "\n";
                    string date, diagnosis, prescription;
                    cout << "  Visit date  (dd/mm/yyyy) : "; getline(cin, date);
                    cout << "  Diagnosis                : "; getline(cin, diagnosis);
                    cout << "  Prescription             : "; getline(cin, prescription);

                    Patient* p = searchPatientByID(pl, outId);
                    if (p) {
                        addVisitHistory(*p, date, diagnosis, prescription);
                        showSuccess("Visit recorded for " + outName + ".");
                    } else {
                        showError("Warning: patient was removed from the list while waiting.");
                    }
                } else {
                    showError("Queue is empty - no patients waiting.");
                }
                break;
            }
            case 3:
                displayQueue(q);
                break;
        }
        pause();
    }
}

// -----------------------------------------------
//  MENU 4 - VISIT HISTORY
// -----------------------------------------------

static void menuHistory(PatientList& pl) {
    const char* opts[] = {
        "View visit history for patient ",
        "Delete visit history           ",
        "Back to main menu              "
    };
    const int N = 3;

    while (true) {
        system("cls");
        drawHeader();
        drawFooter(22);

        int choice = runMenu("VISIT HISTORY  (Linked List)", opts, N, 12);
        if (choice == 0 || choice == N) break;

        system("cls");
        printSectionHeader("VISIT HISTORY");

        switch (choice) {
            case 1: {
                string id;
                cout << "  Patient ID: "; cin >> id; cin.ignore();
                Patient* p = searchPatientByID(pl, id);
                if (p) {
                    showInfo("Patient: " + p->name + "  (ID: " + id + ")");
                    displayVisitHistory(*p);
                } else {
                    showError("Patient not found.");
                }
                break;
            }
            case 2: {
                string id;
                cout << "  Patient ID: "; cin >> id; cin.ignore();
                Patient* p = searchPatientByID(pl, id);
                if (p) {
                    deleteVisitHistory(*p);
                    showSuccess("All visit history cleared for patient " + id + ".");
                } else {
                    showError("Patient not found.");
                }
                break;
            }
        }
        pause();
    }
}

// -----------------------------------------------
//  MENU 5 - STATISTICS & REPORTS
// -----------------------------------------------

static void menuStats(PatientList& pl, int stats[31][12]) {
    const char* opts[] = {
        "Visit statistics by day/month  ",
        "Export full report to .txt     ",
        "Back to main menu              "
    };
    const int N = 3;

    while (true) {
        system("cls");
        drawHeader();
        drawFooter(22);

        int choice = runMenu("STATISTICS & REPORTS  (2D Array)", opts, N, 12);
        if (choice == 0 || choice == N) break;

        system("cls");
        printSectionHeader("STATISTICS & REPORTS");

        switch (choice) {
            case 1:
                buildStats(pl.data, pl.count, stats);
                displayStats(stats);
                break;
            case 2: {
                buildStats(pl.data, pl.count, stats);
                string filename;
                cout << "  Output filename (e.g. report.txt): "; getline(cin, filename);
                if (filename.empty()) filename = "report.txt";
                exportReport(pl.data, pl.count, stats, filename);
                break;
            }
        }
        pause();
    }
}

// -----------------------------------------------
//  MAIN
// -----------------------------------------------

int main() {
    SetConsoleOutputCP(437);     // ensure box-drawing chars render
    SetConsoleCP(437);

    // Resize console to comfortable width
    system("mode con: cols=82 lines=26");

    // -- Initialise data structures --
    PatientList patientList;
    initPatientList(patientList);

    Queue examQueue;
    initQueue(examQueue);

    MedicineStack medStack;
    initMedicineStack(medStack);

    int stats[31][12] = {};

    // -- Boot banner + load save file --
    showBanner();
    system("cls");
    printSectionHeader("LOADING SAVED DATA");
    loadPatientsFromBin(patientList, "patients.bin");
    Sleep(800);

    // -- Main menu --
    const char* mainOpts[] = {
        "Patient Management    (CRUD + Arrays)    ",
        "Examination Queue     (Queue - FIFO)     ",
        "Medicine Storage      (Stack - LIFO)     ",
        "Visit History         (Linked List)      ",
        "Statistics & Reports  (2D Array + File)  ",
        "Exit                                     "
    };
    const int MAIN_N = 6;

    while (true) {
        system("cls");
        drawHeader();
        drawFooter(22);

        int choice = runMenu("MAIN MENU", mainOpts, MAIN_N, 10);

        if (choice == 0 || choice == MAIN_N) break;

        switch (choice) {
            case 1: menuPatient(patientList);         break;
            case 2: menuQueue(examQueue, patientList); break;
            case 3:
                system("cls");
                medicineMenu(medStack);
                break;
            case 4: menuHistory(patientList);         break;
            case 5: menuStats(patientList, stats);    break;
        }
    }

    // -- Shutdown --
    system("cls");
    showLoading("Saving data...");
    savePatientsToBin(patientList, "patients.bin");

    // Free all memory
    for (int i = 0; i < patientList.count; i++)
        deleteVisitHistory(patientList.data[i]);
    freePatientList(patientList);
    clearQueue(examQueue);
    clearMedicineStack(medStack);

    system("cls");
    setColor(14);
    cout << "\n\n";
    cout << "  ============================================================\n";
    cout << "         Thank you for using Clinic Management System!\n";
    cout << "                      Team 25CA - 2026\n";
    cout << "  ============================================================\n\n";
    resetColor();

    return 0;
}