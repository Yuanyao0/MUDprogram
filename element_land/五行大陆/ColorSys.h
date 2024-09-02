#pragma once
#ifndef __COLORSYS_H__
#define __COLORSYS_H__
#include "ColorContainer.h"
#include "ConsoleColor.h"
class ColorSys :public ColorContainer, private ConsoleColor {
public:
	virtual void changeTextColor(char color, std::ostringstream& oss);
private:
	void resetTextColor();//�ָ�ԭ��������ɫ����ɫ
};
#endif // !__COLORSYS_H__