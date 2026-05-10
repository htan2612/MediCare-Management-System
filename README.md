# Clinic Management System - 2026

> **Course:** Fundamental of Programming
> **Lecturer:** M.Sc. Tran Duy Quang
> **Class:** 25CA - Faculty of Information Technology
> **Team:** Huynh Thanh An - Luong Duy Phuoc - Ly Si Vi - Tran Ngoc My Trinh

---

## Introduction

The **Clinic Management System** is a console-based C++ application built to automate the core workflows of a small clinic. It covers patient record management, an examination queue, a medicine inventory, per-patient visit histories, statistical reporting, and persistent binary-file storage - all wired together through a clean, modular multi-file architecture.

The project was developed as the final assignment for the *Fundamental of Programming* course (Class 25CA, 2026). Every major data-structure category from the curriculum is represented: dynamic arrays, singly linked lists, a FIFO queue, a LIFO stack, and a two-dimensional array. The console interface uses CP437 box-drawing characters and Windows API colour/cursor control to provide a fully navigable arrow-key menu system.

---

## Project Structure

```
MediCare-Management-System/
├── src/
│   ├── main.cpp
│   ├── Clinic.h / Clinic.cpp
│   ├── Patient.h
│   ├── PatientCRUD.h / PatientCRUD.cpp
│   ├── PatientFile.h / PatientFile.cpp
│   ├── PatientSearchSort.h / PatientSearchSort.cpp
│   ├── History.h / History.cpp
│   ├── Queue.h / Queue.cpp
│   ├── Medicine.h / Medicine.cpp
│   ├── Statistics.h / Statistics.cpp
│   └── Reports.h / Reports.cpp
├── report
│   ├── report.pdf
├── video/
│   └── link.txt
└── README.md
```

---

## Build & Run

### 1. Compile

Navigate into `src/` first, then compile:

```bash
cd src
g++ *.cpp -o ../Clinic.exe
```

Or compile from the project root:

```bash
g++ src/*.cpp -o Clinic.exe
```

### 2. Run

**Standard launch** (from project root):
```bash
Clinic.exe
```

**Open in a new Windows Terminal tab (recommended):**
```bash
wt -w 0 new-tab cmd /k Clinic.exe
```

> Running in a dedicated tab ensures the console is sized correctly (82x26),
> the CP437 code page loads properly, and box-drawing characters render as intended.
> Requires **Windows Terminal** - install from the Microsoft Store if not already present.

> `patients.bin` (save data) is created in the same directory where `Clinic.exe` is run,
> i.e. the project root.

### 3. Linux / macOS

> The UI relies on Windows-only APIs (`_getch`, `SetConsoleTextAttribute`, `SetConsoleCursorPosition`).
> On Linux or macOS, use **WSL** or port those calls to ncurses equivalents before compiling.

```bash
g++ src/*.cpp -o Clinic
./Clinic
```

---

## File Structure

| File | Description | Learning Outcome |
|:---|:---|:---:|
| `src/Patient.h` | Core structs: `Patient`, `PatientList` | - |
| `src/History.h/cpp` | Linked list - visit history per patient | G3.1 |
| `src/PatientCRUD.h/cpp` | Add / View / Edit / Delete + dynamic array resize | G1.2, G1.3 |
| `src/PatientSearchSort.h/cpp` | Search by name/ID + Quick Sort by name & age | G1.4, G2.1 |
| `src/PatientFile.h/cpp` | Binary file save/load **including visit history** | G2.3 |
| `src/Queue.h/cpp` | FIFO examination queue (linked-list nodes) | G3.2 |
| `src/Medicine.h/cpp` | LIFO medicine stack + interactive menu | G3.2 |
| `src/Statistics.h/cpp` | 2D visit statistics + safe date parsing | G1.4 |
| `src/Reports.h/cpp` | Export full report to `.txt` with timestamp | G2.3 |
| `src/Clinic.h/cpp` | Console UI: box drawing, colours, arrow-key menus | G4.1 |
| `src/main.cpp` | Program entry point - wires all modules together | G4.1 |
| `report/report.pdf` | Compiled project report (PDF) | - |
| `video/link.txt` | YouTube demo video link | - |

---

## Features

1. **Patient CRUD** - add, view, edit, and delete records with duplicate-ID check and input validation
2. **Binary persistence** - full patient data and visit histories saved across sessions
3. **Search & Sort** - case-insensitive name search; Quick Sort by name (A-Z) or age (descending)
4. **Examination Queue (FIFO)** - enqueue patients on arrival, call next, record visit on dequeue
5. **Visit History (Linked List)** - per-patient singly linked list; view and clear
6. **Medicine Storage (Stack / LIFO)** - push / pop / peek with quantity validation
7. **Statistics (2D Array)** - visit counts aggregated by day x month with safe date parsing
8. **Report Export** - timestamped `.txt` report containing patients, visit histories, and statistics
9. **Modular code** - every feature in its own `.h` / `.cpp` pair with clean header guards