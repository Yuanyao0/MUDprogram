#include "ColorSys.h"
#include <iostream>
using namespace std;
void ColorSys::changeTextColor(char color, std::ostringstream& oss)
{
	switch (color)
	{
	case 'W':
		ConsoleColor::setTextWhite(); break;
	case 'R':
		ConsoleColor::setTextRed(); break;
	case 'G':
		ConsoleColor::setTextGreen(); break;
	case 'B':
		ConsoleColor::setTextBlue(); break;
	case 'Y':
		ConsoleColor::setTextYellow(); break;
	case 'P':
		ConsoleColor::setTextPink(); break;
	case 'Q':
		ConsoleColor::setTextBrightBlue(); break;
	default:
		resetTextColor(); break;
	}
	//��������´μ���ʹ�ü���
	cout << oss.str();
	oss.str("");
	//�ָ�ԭ��������ɫ
	resetTextColor();
}

void ColorSys::resetTextColor()
{
	ConsoleColor::setTextWhite();
}
