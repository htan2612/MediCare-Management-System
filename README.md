# Clinic Management System - 2026

> **Course:** Fundamental of Programming
> **Lecturer:** M.Sc. Tran Duy Quang
> **Class:** 25CA - Faculty of Information Technology
> **Team:** Huynh Thanh An · Luong Duy Phuoc · Ly Si Vi · Tran Ngoc My Trinh

---

## Build & Run

### 1. Compile

```bash
g++ *.cpp -o Clinic.exe
```

### 2. Run

**Standard launch**
```bash
Clinic.exe
```

**Open in a new Windows Terminal tab (recommended)**
```bash
wt -w 0 new-tab cmd /k Clinic.exe
```

> Running in a dedicated tab ensures the console is sized correctly (82×26),
> the CP437 code page loads properly, and box-drawing characters render as intended.
> Requires **Windows Terminal** - install from the Microsoft Store if not already present.

### 3. Linux / macOS

> The UI relies on Windows-only APIs (`_getch`, `SetConsoleTextAttribute`, `SetConsoleCursorPosition`).
> On Linux or macOS, use **WSL** or port those calls to ncurses equivalents before compiling.

```bash
g++ *.cpp -o Clinic
./Clinic
```

---

## File Structure

| File | Description | Learning Outcome |
|:---|:---|:---:|
| `Patient.h` | Core structs: `Patient`, `PatientList` | - |
| `History.h/cpp` | Linked list - visit history per patient | G3.1 |
| `PatientCRUD.h/cpp` | Add / View / Edit / Delete + dynamic array resize | G1.2, G1.3 |
| `PatientSearchSort.h/cpp` | Search by name/ID + Quick Sort by name & age | G1.4, G2.1 |
| `PatientFile.h/cpp` | Binary file save/load **including visit history** | G2.3 |
| `Queue.h/cpp` | FIFO examination queue (linked-list nodes) | G3.2 |
| `Medicine.h/cpp` | LIFO medicine stack + interactive menu | G3.2 |
| `Statistics.h/cpp` | 2D visit statistics + safe date parsing | G1.4 |
| `Reports.h/cpp` | Export full report to `.txt` with timestamp | G2.3 |
| `Clinic.h/cpp` | Console UI: box drawing, colours, arrow-key menus | G4.1 |
| `main.cpp` | Program entry point - wires all modules together | G4.1 |

---

## Features

1. **Patient CRUD** - add, view, edit, and delete records with duplicate-ID check and input validation
2. **Binary persistence** - full patient data and visit histories saved across sessions
3. **Search & Sort** - case-insensitive name search; Quick Sort by name (A–Z) or age (descending)
4. **Examination Queue (FIFO)** - enqueue patients on arrival, call next, record visit on dequeue
5. **Visit History (Linked List)** - per-patient singly linked list; view and clear
6. **Medicine Storage (Stack / LIFO)** - push / pop / peek with quantity validation
7. **Statistics (2D Array)** - visit counts aggregated by day × month with safe date parsing
8. **Report Export** - timestamped `.txt` report containing patients, visit histories, and statistics
9. **Modular code** - every feature in its own `.h` / `.cpp` pair with clean header guards