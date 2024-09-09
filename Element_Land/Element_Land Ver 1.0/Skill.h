#pragma once
#ifndef _SKILL_H
#define _SKILL_H
#include <string>

using namespace std;

class Skill {
public:
	int getaseed();
	Skill(int seed);
	std::string getName();	
	int getMissKey();			//���غ�miss
	int getLifeKey();			//��1��Ѫ
	int getUnavoidableHurt()const;
	int getAvoidableHurt()const;
	double getUnavoidableHurtPercent()const;
	double getAvoidableHurtPercent()const;

	int getHPadd()const;
	int getRound()const;
	void setRound(int);
	int getPPconsume()const;
	double getHPaddPercent()const;

	double getPowerBuff()const;
	double getProtectPowerBuff()const;
	bool getPowerBuffKey()const;
	bool getProtectPowerBuffKey()const;
	bool getHPaddKey()const;


private:
	int seed = -1;
	std::string name;
	int UnavoidableHurt;//��ͨ����(���ܶ㣬�ܷ���)
	int	AvoidableHurt;//׷������(���ܶ㣬���ܷ���)
	double AvoidableHurtPercent;//׷�����˰ٷֱ�
	double UnavoidableHurtPercent;//��ͨ���˰ٷֱ�
	bool powerBuffKey;
	double powerBuff;//�����ӳɰٷֱ�(�ܶ㣬�ܷ���)
	bool protectPowerBuffKey;
	double protectPowerBuff;		//�������ӳɰٷֱ�
	bool HPaddKey;
	int HPadd;						//HP�ӳ� ������
	double HPaddPercent;			//HP�ӳ� �����İٷֱ�
	int round;						//�����غ���
	int PPconsume;					//PP����
	bool lifeKey;					//��Ѫ1�ο���
	int MissKey;					//miss����
};
#endif // !__SKILL_H__