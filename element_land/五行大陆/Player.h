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
	void showInfo()const;//�鿴��������
	void showBag();//�鿴����
	bool pushBag(Item* item);//������Ʒ
	void removeBag(Item* item);//ȡ����Ʒ
	int getSkillPower()const;//���ؼ��ܼӳ�
	int getSkillComsume()const; //���ؼ�������
	void initRevive(int life, int energy);//ս���������ص�ս��ǰ״̬��
	virtual void setExp(int exp); //���þ��鲢�Ҹ��µȼ�
	int getNowPos() const;
	void setNowPos(int x);
	//����ģʽ
	static Player* creatPlayer(std::string name, int pos_x, int pos_y, int life,
		int power, int exp, int protectPower,
		int level, int money, int energy, int miss,
		int moveSpeed, int nowPos, Container& bag);
	static void deletePlayer();
	Container* getBag()const;//��ȡ����

private:
	int miss;//����ֵ
	int moveSpeed;//����
	int energy;//����ֵ
	Container& bag;
	static int skillList[10];//�����б�
	static int skillComsume[10];//ʹ�ü��ܵ�������
	static int rankExp[10];//��¼�������辭�飬ʮ������

	int nowPos;  //���ﵱǰλ��
	//����ģʽ
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