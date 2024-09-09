#include "Utill.h"
void Utill::changeForeground(char color)  //�ı��ֵ���ɫ  R �� B �� G ��
{
	//�ı������ɫ
	HANDLE consolehwnd;//�������
	consolehwnd =
		GetStdHandle(STD_OUTPUT_HANDLE);//ʵ�������
	switch (color) {
	case 'R':
		SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case 'B':
		SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	case 'G':
		SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	default:
		break;
	}
}


void Utill::ForegroundRGS()  //������
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void Utill::ForegroundGBS()	//������
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void Utill::ForegroundBRS()	//������
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void Utill::ForegroundALL() //ȫɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void Utill::HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Utill::gotoxy(unsigned char x, unsigned char y)
{
	COORD cor;
	HANDLE hout;
	cor.X = y;
	cor.Y = x;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, cor);
}
