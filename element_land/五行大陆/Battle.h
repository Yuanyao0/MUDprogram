#pragma once
//http://blog.csdn.net/u012424148/article/details/52792472  控制台颜色
#ifndef __BATTLE_H__
#define __BATTLE_H__
#include "Pet.h"
#include "Player.h"
class Battle {
public:
	//创建战斗系统，随机生成怪物，引入玩家
	Battle(Player& player);
	~Battle();
	void choosePet(Player& player);
	void beginBattle();
	bool showResult();//展示结果并且处理战利品，返回值，真：怪物被打死   假：玩家死亡直接回城，初始状态
private:
	Pet * wildPet;
	Player& player;
	void showAttrPanel();//显示属性面板
	int judegeEnd();//1 玩家赢  -1 怪物赢  0 继续战斗
};
#endif // !__BATTLE_H__
