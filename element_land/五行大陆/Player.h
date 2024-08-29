#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
<<<<<<< HEAD
#include "Bag.h"
#include <string>
using namespace std;
class Player
{
public:
	Player(string name, int pos, int money,Bag & bag);
	void showInfo()const;//查看人物属性
	void showBag()const;//查看背包
	bool pushBag(Pet *item);//放入物品
	void removeBag(Pet *item);//取出物品
	int getMoney()const;
	int getPos()const;
	void setPos(int x);
	bool pushEgg();//放入蛋
	void removeEgg();//取出蛋
	static Player *creatPlayer(std::string name,int  nowPos,int money,Bag &bag);
	static void deletePlayer();
	Bag *getBag()const;//获取背包
	
private:
	
	Bag &bag;
	int pos;  //人物当前位置
	int money;
	string name;
	//单例模式
	static Player *instance;
	Player(std::string name, int  nowPos,Bag &bag);
=======
#include "Attackable.h"
#include "Player.h"
#include "Container.h"
#include <string>
class Player :public Attackable
{
public:
	int getMoney()const;
	int reduceMoney()const;
	int getMiss()const;
	void setMiss(int miss);
	int getMoveSpeed()const;
	int getEnergy()const;
	void setEnergy(int energy);
	void setMoveSpeed(int moveSpeed);
	void showInfo()const;//查看人物属性
	void showBag();//查看背包
	bool pushBag(Item* item);//放入物品
	void removeBag(Item* item);//取出物品
	int getSkillPower()const;//返回技能加成
	int getSkillComsume()const; //返回技能消耗
	void initRevive(int life, int energy);//战斗致死，回到战斗前状态。
	virtual void setExp(int exp); //设置经验并且更新等级
	int getNowPos() const;
	void setNowPos(int x);
	//单例模式
	static Player* creatPlayer(std::string name, int pos_x, int pos_y, int life,
		int power, int exp, int protectPower,
		int level, int money, int energy, int miss,
		int moveSpeed, int nowPos, Container& bag);
	static void deletePlayer();
	Container* getBag()const;//获取背包

private:
	int miss;//闪避值
	int moveSpeed;//移速
	int energy;//法力值
	Container& bag;
	static int skillList[10];//技能列表
	static int skillComsume[10];//使用技能的消耗蓝
	static int rankExp[10];//记录升级所需经验，十级满级

	int nowPos;  //人物当前位置
	//单例模式
	static Player* instance;
	Player(std::string name, int pos_x, int pos_y, int life,
		int power, int exp, int protectPower,
		int level, int money, int energy, int miss,
		int moveSpeed, int  nowPos, Container& bag);
>>>>>>> 06e52ffab56565c9416ca77253b3e1b46f06ac85
	class Release
	{
	public:
		~Release();
	};
	static Release  release;
	virtual ~Player();
<<<<<<< HEAD
	
};


=======

};
>>>>>>> 06e52ffab56565c9416ca77253b3e1b46f06ac85
#endif // !__PLAYER_H__