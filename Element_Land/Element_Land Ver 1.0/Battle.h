#pragma once
//http://blog.csdn.net/u012424148/article/details/52792472  ����̨��ɫ
#ifndef __BATTLE_H__
#define __BATTLE_H__
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include "ColorContainer.h"
#include "ColorSys.h"
#include "Pet.h"
#include "Player.h"
class Battle {
public:
	//����ս��ϵͳ��������ɹ���������
	Battle(Player& player);
	~Battle();
	bool choosePet();
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
	vector<Skill*> BSkill;	//Bδ�ͷ���ļ���
	int initPOWER;
	int initPROTECT;
	int choice;
	void showAttrPanel();//��ʾ�������
	int judegeEnd();//1 ���Ӯ  -1 ����Ӯ  0 ����ս��
};
#endif // !__BATTLE_H__
