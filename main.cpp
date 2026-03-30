#include "Clinic.h"

int main() {
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

            // Ví dụ một chức năng
            showLoading();
            setColor(10);
            gotoxy(25, 18); cout << "DA VAO CHUC NANG: " << options[pointer-1];
            _getch();
        } else if (key == 27) { // ESC
            break;
        }
    }

    system("cls");
    setColor(14);
    cout << "\n\n   CAM ON BAN DA SU DUNG HE THONG! HEN GAP LAI.\n\n";
    return 0;
}