#include "Skill.h"

Skill::Skill(){}
Skill::Skill(    ) {


}

int Skill::getMissKey()			//±¾»ØºÏmiss
{
	return MissKey;

}
int Skill::getLifeKey() {
	return lifeKey;
}
string Skill::getName() {
	return name;
}
int Skill::getUnavoidableHurt()const {
	return UnavoidableHurt;
}
int Skill::getAvoidableHurt()const {
	return AvoidableHurt;
}
double Skill::getUnavoidableHurtPercent()const {
	return UnavoidableHurtPercent;
}
double Skill::getAvoidableHurtPercent()const {
	return AvoidableHurtPercent;
}

int Skill::getHPadd()const {
	return HPadd;
}
int Skill::getRound()const {
	return round;
}
void Skill::setRound(int x) {
	round = x;
}
int Skill::getPPconsume()const {
	return PPconsume;
}
double Skill::getHPaddPercent()const {
	return HPaddPercent;
}

double Skill::getPowerBuff()const {
	return powerBuff;
}
double Skill::getProtectPowerBuff()const {
	return protectPowerBuff;
}
bool Skill::getPowerBuffKey()const {
	return powerBuffKey;
}
bool Skill::getProtectPowerBuffKey()const {
	return protectPowerBuffKey;
}
bool Skill::getHPaddKey()const {
	return HPaddKey;
}

