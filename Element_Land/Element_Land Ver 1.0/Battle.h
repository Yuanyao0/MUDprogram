#pragma once
//http://blog.csdn.net/u012424148/article/details/52792472  控制台颜色
#ifndef __BATTLE_H__
#define __BATTLE_H__
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include "ColorContainer.h"
#include "ColorSys.h"
#include "Pet.h"
#include "Player.h"
class Battle {
public:
	//创建战斗系统，随机生成怪物，引入玩家
	Battle(Player& player);
	~Battle();
	bool choosePet();
	void playerChooseSkill();
	void beginBattle();
	void Aremove(int j);
	void Bremove(int j);
	void showResult();//展示结果并且处理战利品
private:
	Pet* wildPet;
	Player& player;
	Pet* yourPet;
	vector<Skill*> ASkill;	//A未释放完的技能
	vector<Skill*> BSkill;	//B未释放完的技能
	int initPOWER;
	int initPROTECT;
	int choice;
	void showAttrPanel();//显示属性面板
	int judegeEnd();//1 玩家赢  -1 怪物赢  0 继续战斗
};
#endif // !__BATTLE_H__
