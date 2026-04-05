#include "Validate.h"

bool isValidAge(int age) {
    return (age >= 0 && age <= 120);
}

bool isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (isdigit(c)) return false;
    }
    return true;
}

bool isValidGender(const string& gender) {
    return (gender == "Nam" || gender == "Nu"  ||
            gender == "nam" || gender == "nu");
}

bool isValidID(int id, Patient* list, int count) {
    if (id <= 0) return false;
    for (int i = 0; i < count; i++) {
        if (list[i].id == id) return false;
    }
    return true;
}

void showError(const string& msg) {
    setColor(12); // Do
    cout << "  [LOI] " << msg << endl;
    setColor(15); // Trang
}

void showSuccess(const string& msg) {
    setColor(10); // Xanh la
    cout << "  [OK]  " << msg << endl;
    setColor(15);
}

int inputID(Patient* list, int count) {
    int id;
    do {
        setColor(11);
        cout << "  Nhap ID benh nhan (so nguyen duong, khong trung): ";
        setColor(15);
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            showError("ID phai la so nguyen. Vui long nhap lai.");
            continue;
        }
        if (id <= 0) {
            showError("ID phai lon hon 0. Vui long nhap lai.");
            continue;
        }
        if (!isValidID(id, list, count)) {
            showError("ID nay da ton tai. Vui long nhap ID khac.");
            continue;
        }
        break; // ID hop le
    } while (true);

    cin.ignore();
    return id;
}

string inputName() {
    string name;
    do {
        setColor(11);
        cout << "  Nhap ho ten benh nhan (khong chua so): ";
        setColor(15);
        getline(cin, name);

        if (!isValidName(name)) {
            showError("Ten khong hop le (khong duoc de trong hoac chua chu so).");
            continue;
        }
        break;
    } while (true);

    return name;
}

int inputAge() {
    int age;
    do {
        setColor(11);
        cout << "  Nhap tuoi (0 - 120): ";
        setColor(15);
        cin >> age;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            showError("Tuoi phai la so nguyen. Vui long nhap lai.");
            continue;
        }
        if (!isValidAge(age)) {
            showError("Tuoi phai trong khoang 0 den 120.");
            continue;
        }
        break;
    } while (true);

    cin.ignore();
    return age;
}

string inputGender() {
    string gender;
    do {
        setColor(11);
        cout << "  Nhap gioi tinh (Nam / Nu): ";
        setColor(15);
        getline(cin, gender);

        if (!isValidGender(gender)) {
            showError("Chi chap nhan 'Nam' hoac 'Nu'.");
            continue;
        }
        break;
    } while (true);

    if (gender == "nam") gender = "Nam";
    if (gender == "nu")  gender = "Nu";
    return gender;
}

string inputSymptoms() {
    string symptoms;
    do {
        setColor(11);
        cout << "  Nhap trieu chung (khong de trong): ";
        setColor(15);
        getline(cin, symptoms);

        if (symptoms.empty()) {
            showError("Trieu chung khong duoc de trong.");
            continue;
        }
        break;
    } while (true);

    return symptoms;
}

Patient inputPatient(Patient* list, int count) {
    Patient p;
    setColor(14);
    cout << "\n NHAP THONG TIN BENH NHAN" << endl;
    setColor(15);

    p.id       = inputID(list, count);
    p.name     = inputName();
    p.age      = inputAge();
    p.gender   = inputGender();
    p.symptoms = inputSymptoms();

    showSuccess("Nhap thong tin thanh cong!");
    return p;
}