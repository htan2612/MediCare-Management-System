#ifndef CLINIC_H
#define CLINIC_H

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>

#include "Patient.h"
#include "PatientCRUD.h"
#include "PatientFile.h"
#include "PatientSearchSort.h"
#include "History.h"
#include "Queue.h"

void gotoxy(int x, int y);
void setColor(int fg, int bg = 0);
void resetColor();
void clearLine(int y, int width = 80);

void drawBox(int x, int y, int w, int h, int color = 11);
void drawHeader();
void drawFooter(int y);
void drawDivider(int y, int width = 78, int color = 8);

void showBanner();
void showLoading(const string& msg = "Processing...");
void showSuccess(const string& msg);
void showError(const string& msg);
void showInfo(const string& msg);

int runMenu(const char* title, const char* options[], int count, int startY = 10);

void printSectionHeader(const string& title);

#endif