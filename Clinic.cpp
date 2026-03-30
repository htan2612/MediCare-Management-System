#include "Clinic.h"

void gotoxy(int x, int y) {
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawFrame(int x, int y, int width, int height) {
    setColor(11); // Màu Cyan
    gotoxy(x, y); cout << (char)201; 
    for(int i=0; i<width; i++) cout << (char)205;
    cout << (char)187;

    for(int i=1; i<=height; i++) {
        gotoxy(x, y+i); cout << (char)186;
        gotoxy(x + width + 1, y+i); cout << (char)186;
    }

    gotoxy(x, y + height + 1); cout << (char)200;
    for(int i=0; i<width; i++) cout << (char)205;
    cout << (char)188;
}

void drawHeader() {
    setColor(14); // Màu vàng
    gotoxy(15, 1); cout << " ██████╗██╗     ██╗███╗   ██╗██╗ ██████╗ ";
    gotoxy(15, 2); cout << "██╔════╝██║     ██║████╗  ██║██║██╔════╝ ";
    gotoxy(15, 3); cout << "██║     ██║     ██║██╔██╗ ██║██║██║      ";
    gotoxy(15, 4); cout << "██║     ██║     ██║██║╚██╗██║██║██║      ";
    gotoxy(15, 5); cout << "╚██████╗███████╗██║██║ ╚████║██║╚██████╗ ";
    gotoxy(15, 6); cout << " ╚═════╝╚══════╝╚═╝╚═╝  ╚═══╝╚═╝ ╚═════╝ ";
    setColor(10);
    gotoxy(30, 7); cout << "CLINIC MANAGEMENT 2026";
}

void drawFooter() {
    setColor(8); // Màu xám
    gotoxy(2, 22); cout << "______________________________________________________";
    gotoxy(2, 23); cout << "Phim [UP/DOWN]: Di chuyen | [ENTER]: Chon | [ESC]: Thoat";
}

void showLoading() {
    setColor(13); // Màu hồng/tím
    gotoxy(30, 15); cout << "DANG XU LY...";
    gotoxy(25, 16);
    for(int i=0; i<25; i++) {
        Sleep(30);
        cout << (char)219; // Ký tự khối đặc
    }
}