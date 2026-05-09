# Clinic Management System — 2026

> **Course:** Fundamental of Programming  
> **Lecturer:** Tran Duy Quang  
> **Class:** 25CA — Faculty of Information Technology  
> **Team:** Huynh Thanh An · Luong Duy Phuoc · Ly Si Vi · Tran Ngoc My Trinh

---

## Build & Run

**Windows (MinGW / g++)**
```bash
g++ *.cpp -o Clinic.exe
Clinic.exe
```

**Linux / macOS** *(note: Windows-only APIs like `_getch`, `SetConsoleTextAttribute` require WSL or porting)*
```bash
g++ *.cpp -o Clinic
./Clinic
```

---

## File Structure

| File | Description | Learning Outcome |
|:---|:---|:---:|
| `Patient.h` | Core structs: `Patient`, `PatientList` | — |
| `History.h/cpp` | Linked list — visit history per patient | G3.1 |
| `PatientCRUD.h/cpp` | Add / View / Edit / Delete + dynamic array resize | G1.2, G1.3, G4.1 |
| `PatientSearchSort.h/cpp` | Search by name/ID + Quick Sort by name & age | G1.4, G2.1, G2.2 |
| `PatientFile.h/cpp` | Binary file save/load **including visit history** | G2.3 |
| `Queue.h/cpp` | FIFO examination queue (linked-list nodes) | G3.2 |
| `Medicine.h/cpp` | LIFO medicine stack + interactive menu | G3.2 |
| `Statistics.h/cpp` | 2-D visit statistics + safe date parsing | G1.4 |
| `Reports.h/cpp` | Export full report to `.txt` with timestamp | G2.3 |
| `Clinic.h/cpp` | Console UI: box drawing, colours, arrow-key menus | G4.1 |
| `main.cpp` | Program entry point — wires all modules together | G4.1 |

---

## Features

1. **Patient CRUD** — add, view, edit, delete with duplicate-ID check
2. **Binary persistence** — full patient data + visit histories saved across sessions
3. **Search & Sort** — case-insensitive name search; Quick Sort by name or age
4. **Examination Queue (FIFO)** — enqueue patients, call next, record visit on dequeue
5. **Visit History (Linked List)** — per-patient linked list; view & clear
6. **Medicine Storage (Stack / LIFO)** — push/pop/peek with quantity validation
7. **Statistics (2D Array)** — visit counts by day × month; safe date parsing
8. **Report Export** — timestamped `.txt` report with patients, histories, stats
9. **Modular code** — every feature in its own `.h` / `.cpp` pair

---

## Bug Fixes vs Original

| # | File | Fix |
|:---:|:---|:---|
| 1 | `PatientCRUD.cpp` | `deletePatient` now frees the visit-history linked list before removing the record (prevents memory leak) |
| 2 | `PatientCRUD.cpp` | Removed redundant `cin.ignore()` inside `updatePatient`; caller handles it |
| 3 | `main.cpp` | `int stats[31][12] = {}` — zero-initialised at declaration |
| 4 | `PatientFile.cpp` | Visit history linked list is now fully serialised to / deserialised from the binary file |
| 5 | `Queue.h/cpp` | Queue nodes store only `id` + `name` — avoids shallow-copy of `historyHead` pointer |
| 6 | `PatientSearchSort.cpp` | `swapPatientData` swaps each field individually (including `historyHead`) so history follows the correct patient after sorting |
| 7 | `Statistics.cpp` | `parseDate` validates format before indexing — no crash on malformed dates |
| 8 | `Medicine.cpp` | Quantity validated to be > 0 before push |
| 9 | `PatientCRUD.cpp` | Duplicate-ID check on add |
| 10 | `PatientSearchSort.cpp` | Name search is case-insensitive |
| 11 | `Clinic.h` | `using namespace std` removed from header |