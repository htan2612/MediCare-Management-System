#include "Clinic.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD c = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setColor(int fg, int bg) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bg << 4) | fg);
}

void resetColor() {
    setColor(15, 0);
}

void clearLine(int y, int width) {
    gotoxy(0, y);
    for (int i = 0; i < width; i++) cout << ' ';
}

void drawBox(int x, int y, int w, int h, int color) {
    setColor(color);

    gotoxy(x, y);
    cout << (char)201;
    for (int i = 0; i < w; i++) cout << (char)205;
    cout << (char)187;

    for (int i = 1; i <= h; i++) {
        gotoxy(x,     y + i); cout << (char)186;
        gotoxy(x+w+1, y + i); cout << (char)186;
    }

    gotoxy(x, y + h + 1);
    cout << (char)200;
    for (int i = 0; i < w; i++) cout << (char)205;
    cout << (char)188;

    resetColor();
}

void drawHeader() {
    setColor(6);
    gotoxy(1, 0);  cout << (char)201; for(int i=0;i<78;i++) cout<<(char)205; cout<<(char)187;
    gotoxy(1, 8);  cout << (char)200; for(int i=0;i<78;i++) cout<<(char)205; cout<<(char)188;
    for(int r=1;r<=7;r++){
        gotoxy(1,r);  cout<<(char)186;
        gotoxy(80,r); cout<<(char)186;
    }

    setColor(14);
    gotoxy(16, 1); cout << "   ___  _     ___  _  _ ___  ___        ";
    gotoxy(16, 2); cout << "  / __|| |   |_ _|| \\| ||_ _|/ __|      ";
    gotoxy(16, 3); cout << " | (__ | |__  | | | .` | | || (__       ";
    gotoxy(16, 4); cout << "  \\___||____||___||_|\\_||___|\\___|      ";

    setColor(11);
    gotoxy(19, 5); cout << "C L I N I C   M A N A G E M E N T   S Y S T E M";

    setColor(8);
    gotoxy(22, 6); cout << "Fundamental of Programming  |  2026";

    resetColor();
}

void drawFooter(int y) {
    setColor(8);
    gotoxy(1, y);
    cout << string(80, (char)196);
    gotoxy(1, y + 1);
    setColor(7);
    cout << "  [UP/DOWN] Navigate   [ENTER] Select   [ESC] Back/Exit";
    resetColor();
}

void drawDivider(int y, int width, int color) {
    setColor(color);
    gotoxy(2, y);
    for (int i = 0; i < width; i++) cout << (char)196;
    resetColor();
}

void printSectionHeader(const string& title) {
    int pad = (int)(76 - title.size()) / 2;
    setColor(0, 11);
    cout << "\n  ";
    for (int i = 0; i < pad; i++) cout << ' ';
    cout << " " << title << " ";
    for (int i = 0; i < pad; i++) cout << ' ';
    cout << "\n";
    resetColor();
    cout << "\n";
}

void showBanner() {
    system("cls");
    drawHeader();

    setColor(10);
    gotoxy(20, 11); cout << "Initialising system...";
    gotoxy(20, 12);
    for (int i = 0; i < 40; i++) {
        Sleep(18);
        setColor(10 + (i % 4));
        cout << (char)219;
    }

    setColor(14);
    gotoxy(23, 14); cout << ">> System ready. Welcome! <<";
    Sleep(600);
    resetColor();
}

void showLoading(const string& msg) {
    setColor(13);
    cout << "\n  " << msg << "\n  ";
    for (int i = 0; i < 30; i++) {
        Sleep(18);
        cout << (char)219;
        cout.flush();
    }
    resetColor();
    cout << "\n";
}

void showSuccess(const string& msg) {
    setColor(10);
    cout << "\n  [OK]  " << msg << "\n";
    resetColor();
}

void showError(const string& msg) {
    setColor(12);
    cout << "\n  [!!]  " << msg << "\n";
    resetColor();
}

void showInfo(const string& msg) {
    setColor(11);
    cout << "\n  [>>]  " << msg << "\n";
    resetColor();
}

int runMenu(const char* title, const char* options[], int count, int startY) {
    int pointer = 0;

    int titlePad = (int)(74 - strlen(title)) / 2;
    setColor(0, 6);
    gotoxy(3, startY - 2);
    cout << "  ";
    for (int i = 0; i < titlePad; i++) cout << ' ';
    cout << title;
    for (int i = 0; i < titlePad; i++) cout << ' ';
    cout << "  ";
    resetColor();

    while (true) {
        for (int i = 0; i < count; i++) {
            gotoxy(8, startY + i);
            if (i == pointer) {
                setColor(0, 14);
                cout << "  > " << options[i] << "  ";
            } else {
                setColor(15, 0);
                cout << "    " << options[i] << "  ";
            }
        }
        resetColor();

        gotoxy(8, startY + count + 1);
        setColor(8);
        cout << "  Use arrow keys to navigate, Enter to confirm";
        resetColor();

        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 72 || key == 'w' || key == 'W') {
            pointer = (pointer > 0) ? pointer - 1 : count - 1;
        } else if (key == 80 || key == 's' || key == 'S') {
            pointer = (pointer < count - 1) ? pointer + 1 : 0;
        } else if (key == 13) {
            return pointer + 1;
        } else if (key == 27) {
            return 0;
        }
    }
}