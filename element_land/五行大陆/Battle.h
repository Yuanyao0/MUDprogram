#pragma once
//http://blog.csdn.net/u012424148/article/details/52792472  ����̨��ɫ
#ifndef __BATTLE_H__
#define __BATTLE_H__
#include "Pet.h"
#include "Player.h"
class Battle {
public:
	//����ս��ϵͳ��������ɹ���������
	Battle(Player& player);
	~Battle();
	void choosePet(Player& player);
	void beginBattle();
	bool showResult();//չʾ������Ҵ���ս��Ʒ������ֵ���棺���ﱻ����   �٣��������ֱ�ӻسǣ���ʼ״̬
private:
	Pet * wildPet;
	Player& player;
	void showAttrPanel();//��ʾ�������
	int judegeEnd();//1 ���Ӯ  -1 ����Ӯ  0 ����ս��
};
#endif // !__BATTLE_H__
