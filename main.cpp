#include "Clinic.h"

int main() {
    // Khoi tao mang dong va tai file bin (Task 3)
    PatientList patientList;
    initPatientList(patientList);
    loadPatientsFromBin(patientList, "patients.bin");
    
    // Thiết lập Console
    SetConsoleOutputCP(65001); // Hiển thị UTF-8
    int pointer = 1;
    bool running = true;

    while (running) {
        system("cls");
        drawHeader();
        drawFrame(20, 10, 40, 8);
        drawFooter();

        // Danh sách Menu
        string options[] = {
            " 1. TIEP NHAN BENH NHAN   ",
            " 2. DANH SACH CHO KHAM    ",
            " 3. KHO THUOC & VAT TU    ",
            " 4. THONG KE DOANH THU    ",
            " 5. THOAT CHUONG TRINH    "
        };

        for (int i = 0; i < 5; i++) {
            if (pointer == i + 1) {
                gotoxy(25, 12 + i);
                setColor(240); // Nền trắng chữ đen (Highlight)
                cout << ">>" << options[i] << "<<";
            } else {
                gotoxy(25, 12 + i);
                setColor(15); // Màu trắng thường
                cout << "  " << options[i] << "  ";
            }
        }

        char key = _getch();
        if (key == 72) { // Up
            if (pointer > 1) pointer--;
            else pointer = 5;
        } else if (key == 80) { // Down
            if (pointer < 5) pointer++;
            else pointer = 1;
        } else if (key == 13) { // Enter
            system("cls");
            if (pointer == 5) break;
            
            if (pointer == 1) { // TIEP NHAN BENH NHAN
                system("cls");
                setColor(10);
                cout << "--- QUAN LY BENH NHAN (TASK 2, 4) ---\n";
                cout << "1. Them Benh nhan\n2. Xem danh sach\n3. Sua\n4. Xoa\n";
                cout << "5. Tim theo Ten\n6. Sap xep theo Ten (A-Z)\n7. Sap xep theo Tuoi (Giam dan)\n";
                cout << "Chon (1-7): ";
                int chon; cin >> chon; cin.ignore();
                
                cout << "\n";
                if(chon == 1) addPatient(patientList);
                else if(chon == 2) displayAllPatients(patientList);
                else if(chon == 3) {
                    string id; cout << "Nhap ID sua: "; cin >> id;
                    updatePatient(patientList, id);
                } else if(chon == 4) {
                    string id; cout << "Nhap ID xoa: "; cin >> id;
                    deletePatient(patientList, id);
                } else if(chon == 5) {
                    string n; cout << "Nhap Ten can tim: "; getline(cin, n);
                    searchPatientByName(patientList, n);
                } else if(chon == 6) {
                    sortPatientsByName(patientList);
                    displayAllPatients(patientList);
                } else if(chon == 7) {
                    sortPatientsByAge(patientList);
                    displayAllPatients(patientList);
                }

                cout << "\n[Nhan phim bat ky de quay lai menu chinh...]";
                _getch();
            else {
                showLoading();
                setColor(10);
                gotoxy(25, 18); cout << "DA VAO CHUC NANG: " << options[pointer-1];
                _getch();
            }

        } else if (key == 27) { // ESC
            break;
        }
    }

    system("cls");

    // Luu file khi tat chuong trinh va giai phong bo nho
    savePatientsToBin(patientList, "patients.bin");
    freePatientList(patientList);
    
    setColor(14);
    cout << "\n\n   CAM ON BAN DA SU DUNG HE THONG! HEN GAP LAI.\n\n";
    return 0;
}


