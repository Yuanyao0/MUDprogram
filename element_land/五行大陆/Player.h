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
	void showInfo()const;//�鿴��������
	void showBag()const;//�鿴����
	bool pushBag(Pet *item);//������Ʒ
	void removeBag(Pet *item);//ȡ����Ʒ
	int getMoney()const;
	int getPos()const;
	void setPos(int x);
	bool pushEgg();//���뵰
	void removeEgg();//ȡ����
	static Player *creatPlayer(std::string name,int  nowPos,int money,Bag &bag);
	static void deletePlayer();
	Bag *getBag()const;//��ȡ����
	
private:
	
	Bag &bag;
	int pos;  //���ﵱǰλ��
	int money;
	string name;
	//����ģʽ
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