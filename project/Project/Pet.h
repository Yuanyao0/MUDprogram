#pragma once
#ifndef _PET_H
#define _PET_H
#include <string>
#include <vector>
#include<iostream>
#include"Skill.h"
#include "ConstTable.h"
class Pet
{
public:
	Pet();
	Pet( Pet* pet);
	Pet(int aseed);
	void init(int nowLife,int nowPP,int level,int aseed);
	~Pet();
	std::string getName();
	void setName(std::string name);
	int getLife()const;
	void setLife(int life);
	void setaseed(int a);
	int getaseed()const;
	int getNowLife()const;
	void setNowLife(int);

	int getPower()const;
	void setPower(int power);
	int getProtectPower()const;
	void setProtectPower(int protectPower);

	
	int getLevel()const;
	void setLevel(int level);

	void setPP(int PP);//技能使用次数
	int getPP()const;
	void setNowPP(int PP);
	int getNowPP()const;

	int getMoney()const;
	void setMoney(int money);
	virtual void showInfo()const;//打印属性
	Skill* getSkill(int i)const;
	int getSkillCount();
	void setElement(int);
	int getElement()const;
	void initSkills(int aseed);
	void init(int aseed);
	
	
	double ElementFight(Pet* pet);	//属性相克
private:
	std::string name;
	int element;
	int nowLife;//它的生命值
	int life;//满生命值
	int power;//攻击力
	int protectPower;//护甲
	int level;//等级
	int money;//金钱
	int PP;
	int nowPP;
	int skillCount;	//技能数
	int aseed;
	
	std::vector<Skill*> Skills;//宠物技能
};
#endif // !__PET_H__