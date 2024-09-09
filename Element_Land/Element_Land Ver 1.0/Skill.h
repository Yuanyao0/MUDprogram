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
	int getMissKey();			//本回合miss
	int getLifeKey();			//保1滴血
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
	int UnavoidableHurt;//普通真伤(不能躲，能防御)
	int	AvoidableHurt;//追踪真伤(不能躲，不能防御)
	double AvoidableHurtPercent;//追踪真伤百分比
	double UnavoidableHurtPercent;//普通真伤百分比
	bool powerBuffKey;
	double powerBuff;//攻击加成百分比(能躲，能防御)
	bool protectPowerBuffKey;
	double protectPowerBuff;		//防御力加成百分比
	bool HPaddKey;
	int HPadd;						//HP加成 或消耗
	double HPaddPercent;			//HP加成 或消耗百分比
	int round;						//持续回合数
	int PPconsume;					//PP消耗
	bool lifeKey;					//保血1滴开关
	int MissKey;					//miss开关
};
#endif // !__SKILL_H__