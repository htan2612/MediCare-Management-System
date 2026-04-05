#include "Clinic.h"
#include "Validate.h"

// Danh sach benh nhan (mang dong)
Patient* danhSach = nullptr;
int soLuong = 0;
int dungLuong = 0;

// Mo rong mang khi can
void expandList() {
    dungLuong += 10;
    Patient* temp = new Patient[dungLuong];
    for (int i = 0; i < soLuong; i++) temp[i] = danhSach[i];
    delete[] danhSach;
    danhSach = temp;
}

// Hien thi danh sach benh nhan
void hienThiDanhSach() {
    system("cls");
    drawHeader();
    setColor(14);
    gotoxy(5, 9); cout << "DANH SACH BENH NHAN";
    setColor(11);
    gotoxy(2, 10);
    cout << "--------------------------------------------------------------";
    gotoxy(2, 11);
    cout << setw(5)  << "ID"
         << setw(20) << "HO TEN"
         << setw(6)  << "TUOI"
         << setw(8)  << "GIOI TINH"
         << setw(20) << "TRIEU CHUNG";
    gotoxy(2, 12);
    cout << "--------------------------------------------------------------";

    if (soLuong == 0) {
        setColor(8);
        gotoxy(10, 13); cout << "(Chua co benh nhan nao trong danh sach)";
    } else {
        for (int i = 0; i < soLuong; i++) {
            setColor(15);
            gotoxy(2, 13 + i);
            cout << setw(5)  << danhSach[i].id
                 << setw(20) << danhSach[i].name
                 << setw(6)  << danhSach[i].age
                 << setw(10) << danhSach[i].gender
                 << setw(20) << danhSach[i].symptoms;
        }
    }

    setColor(8);
    gotoxy(2, 20); cout << "Nhan phim bat ky de quay lai...";
    _getch();
}

int main() {
    SetConsoleOutputCP(65001);
    int pointer = 1;
    bool running = true;

    // Khoi tao mang dong
    dungLuong = 10;
    danhSach = new Patient[dungLuong];

    while (running) {
        system("cls");
        drawHeader();
        drawFrame(20, 10, 40, 8);
        drawFooter();

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
                setColor(240);
                cout << ">>" << options[i] << "<<";
            } else {
                gotoxy(25, 12 + i);
                setColor(15);
                cout << "  " << options[i] << "  ";
            }
        }

        char key = _getch();
        if (key == 72) {
            if (pointer > 1) pointer--;
            else pointer = 5;
        } else if (key == 80) {
            if (pointer < 5) pointer++;
            else pointer = 1;
        } else if (key == 13) {
            system("cls");
            if (pointer == 5) break;

            if (pointer == 1) {
                drawHeader();

                if (soLuong >= dungLuong) expandList();

                // Goi ham nhap co validate - Task 11
                Patient p = inputPatient(danhSach, soLuong);
                danhSach[soLuong++] = p;

                setColor(10);
                gotoxy(5, 20);
                cout << "Da luu benh nhan vao danh sach! Nhan phim bat ky...";
                _getch();
            }

            else if (pointer == 2) {
                hienThiDanhSach();
            }

            else {
                showLoading();
                setColor(10);
                gotoxy(25, 18);
                cout << "Chuc nang dang phat trien...";
                _getch();
            }
        } else if (key == 27) {
            break;
        }
    }

    // Giai phong bo nho
    delete[] danhSach;

    system("cls");
    setColor(14);
    cout << "\n\n   CAM ON BAN DA SU DUNG HE THONG! HEN GAP LAI.\n\n";
    return 0;
}