#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#pragma once

#include <Windows.h>

using namespace std;
class Utill {
public:
    static void changeForeground(char color);
    static void ForegroundRGS();
    static void ForegroundGBS();
    static void ForegroundBRS();
    static void ForegroundALL();
    static void HideCursor();
    static void gotoxy(unsigned char x, unsigned char y);
};

