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
	void choosePet();
	void playerChooseSkill();
	void beginBattle();
	void Aremove(int j);
	void Bremove(int j);
	void showResult();//չʾ������Ҵ���ս��Ʒ
private:
	Pet* wildPet;
	Player& player;
	Pet* yourPet;
	vector<Skill*> ASkill;	//Aδ�ͷ���ļ���
	int Acount = 0;
	vector<Skill*> BSkill;	//Bδ�ͷ���ļ���
	int Bcount = 0;
	int initPOWER;
	int initPROTECT;
	int choice;
	void showAttrPanel();//��ʾ�������
	int judegeEnd();//1 ���Ӯ  -1 ����Ӯ  0 ����ս��
};
#endif // !__BATTLE_H__
