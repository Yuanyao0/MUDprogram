#pragma once
#ifndef _YOURPET_H
#define _YOURPET_H
#include "Pet.h"

class yourPet :public Pet{
public:
	yourPet();
	yourPet(const Pet & pet);
	

	~yourPet();
	void showInfo()const;//打印属性
private:
	std::string name;
	int element;
	int nowPP;
	int life;//满生命值
	int nowLife;//生命值
	int power;//攻击力
	int protectPower;//护甲
	int level;//等级
	int PP;
	int skillCount;
	int aseed;
	std::vector<Skill*> Skills;//宠物技能
};

#endif // !__YOURPET_H__