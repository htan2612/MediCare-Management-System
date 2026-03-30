#ifndef CLINIC_H
#define CLINIC_H

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

// Hàm hỗ trợ giao diện
void gotoxy(int x, int y);
void setColor(int color);
void drawFrame(int x, int y, int width, int height);
void drawHeader();
void drawFooter();
void showLoading();

#endif