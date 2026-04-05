# Clinic Management System 2026

A C++ console application for managing small clinic operations.
Built as a team project for **CSC10012 – Fundamentals of Programming**, Faculty of Information Technology, VNUHCM – University of Science.

---

## Team Members

| No. | Full Name | Student ID | Role |
|:---:|:---|:---:|:---:|
| 1 | Huynh Thanh An | 25127178 | Team Leader |
| 2 | Luong Duy Phuoc | 24127509 | Member |
| 3 | Ly Si Vi | 24127587 | Member |
| 4 | Tran Ngoc My Trinh | 25127258 | Member |

---

## Project Structure

```
Clinic2026/
├── Clinic.h          # UI helper declarations (gotoxy, setColor, drawFrame...)
├── Clinic.cpp        # UI helper implementations
├── Validate.h        # Patient struct + input validation declarations
├── Validate.cpp      # Input validation logic (Task 11)
└── main.cpp          # Entry point, menu navigation, feature routing
```

---

## How to Run

Make sure you have `g++` installed. Open a terminal in the project folder and run:

```bash
g++ *.cpp -o Clinic
./Clinic
```

> **Note:** This project uses Windows-specific APIs (`windows.h`, `conio.h`). It must be compiled and run on Windows.

Navigate the menu using arrow keys. Press `Enter` to select and `ESC` to exit.

---

## Features

### Done
| # | Feature | Learning Outcome | Notes |
|:---:|:---|:---:|:---|
| 1 | UI & Navigation | G4.1 | Arrow-key menu, ASCII logo, colored frames, loading effect |
| 11 | Input Validation | G1.2, G1.3 | Validates ID (unique, positive), name (no digits), age (0–120), gender, symptoms using `do-while` loops |

### In Progress
| # | Feature | Learning Outcome | Assigned To |
|:---:|:---|:---:|:---|
| 2 | Patient Management (CRUD) | G1.2, G1.3 | – |
| 5 | Examination Queue | G3.2 | Duy Phuoc |
| 6 | Visit History (Linked List) | G3.1 | Duy Phuoc |
| 7 | Medicine Inventory (Stack) | G3.2 | My Trinh |
| 8 | Statistics (2D Array) | G1.4 | My Trinh |
| 9 | Export Report (.txt) | G2.3 | My Trinh |
| 12 | User Feedback System | G1.2, G1.3 | Thanh An |
| 13 | Login System | G2.3, G4.1 | Ly Si Vi |

### Not Started
| # | Feature | Learning Outcome |
|:---:|:---|:---:|
| 3 | Save / Load Data (.bin) | G2.3 |
| 4 | Search & Sort | G1.4, G2.1 |
| 10 | Word Report & Documentation | G4.1, G5.1, G6.1 |

---

## Data Structures Used

| Structure | Applied In |
|:---|:---|
| `struct` | `Patient`, `Account` |
| Dynamic array + pointer | Patient list in `main.cpp` |
| `do-while` + `if-else` | All input validation (Task 11) |
| Queue | Examination queue (in progress) |
| Linked List | Visit history per patient (in progress) |
| Stack (LIFO) | Medicine import/export (in progress) |
| 2D Array | Visit statistics by day/month (in progress) |
| Binary file | Save/load patient data (not started) |

---

## Course Learning Outcomes Coverage

| LO | Description | Status |
|:---:|:---|:---:|
| G1.2 | Input/Output manipulation | ✅ Done |
| G1.3 | Control flow statements | ✅ Done |
| G1.4 | 1D and 2D arrays | 🔄 In Progress |
| G2.1 | Pointers | 🔄 In Progress |
| G2.2 | Dynamic array and string via pointers | 🔄 In Progress |
| G2.3 | Binary file I/O | ⬜ Not Started |
| G3.1 | Linked List | 🔄 In Progress |
| G3.2 | Stack and Queue | 🔄 In Progress |
| G4.1 | Multi-file program organization | ✅ Done |
| G5.1 | Present concepts in English | ⬜ Not Started |
| G6.1 | Teamwork and presentation | ⬜ Not Started |