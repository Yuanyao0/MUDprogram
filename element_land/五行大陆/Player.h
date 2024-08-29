#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Attackable.h"
#include "Player.h"
#include "Container.h"
#include <string>
class Player :public Attackable
{
public:
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
	class Release
	{
	public:
		~Release();
	};
	static Release  release;
	virtual ~Player();

};
#endif // !__PLAYER_H__