#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
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
	class Release
	{
	public:
		~Release();
	};
	static Release  release;
	virtual ~Player();
	
};


#endif // !__PLAYER_H__