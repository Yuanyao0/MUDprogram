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
	void showInfo()const;//�鿴��������
	void showBag()const;//�鿴����
	bool pushBag(Pet* );//�������
	void removeBag(Pet*);//�Ƴ�����
	string getName();
	void setName(string b);
	int getMoney()const;
	void setMoney(int );
	int getPos()const;
	void setPos(int x);
	bool pushEgg(Egg*);//���뵰
	bool removeEgg(int);//ȡ����
	static Player* creatPlayer(std::string name, int  nowPos, int money, Bag& bag);
	static void deletePlayer();
	Bag* getBag()const;//��ȡ����
	void setBag(Bag& bag);

private:

	Bag& bag;
	int pos;  //���ﵱǰλ��
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