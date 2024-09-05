#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Bag.h"
#include <string>
using namespace std;
class Player
{
public:
	Player(string name, int pos, int money, Bag& bag);
	void showInfo()const;//查看人物属性
	void showBag()const;//查看背包
	bool pushBag(Pet* );//放入宠物
	void removeBag(Pet*);//移除宠物
	string getName();
	void setName(string b);
	int getMoney()const;
	void setMoney(int );
	int getPos()const;
	void setPos(int x);
	bool pushEgg(Egg*);//放入蛋
	bool removeEgg(int);//取出蛋
	static Player* creatPlayer(std::string name, int  nowPos, int money, Bag& bag);
	static void deletePlayer();
	Bag* getBag()const;//获取背包
	void setBag(Bag& bag);

private:

	Bag& bag;
	int pos;  //人物当前位置
	int money;
	string name;
	static Player* instance;
	class Release
	{
	public:
		~Release();
	};
	static Release  release;
	virtual ~Player();
};
#endif // !__PLAYER_H__