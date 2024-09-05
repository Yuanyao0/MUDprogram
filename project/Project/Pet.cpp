#include <iostream>
#include <ctime>
#include "Pet.h"

using namespace std;
Pet::Pet(){}
Pet::Pet( Pet * pet){
	
	nowLife = pet->getNowLife();
	nowPP = pet->getNowPP();
	level = pet->getLevel();
	aseed = pet->getaseed();
	init(aseed);

}

Pet::Pet(int aseed) {
	//根据种子随机生成野怪--种子、等级、生命PP
	unsigned seed = static_cast<unsigned>(time(NULL));
	srand(seed);
	int theLevel = rand() % MAXPETLEVEL + 1;
	level = theLevel;
	this->aseed = aseed;
	init( aseed);

	nowLife = life;
	nowPP = PP;

}

void Pet::init(int AnowLife,int AnowPP, int Alevel,int Aaseed){
	 
	nowLife = AnowLife;
	nowPP = AnowPP;
	level = Alevel;
	aseed = Aaseed;
	init(aseed);
}
void Pet::setaseed(int a) {
	aseed = a;
}
void Pet::init(int aseed) {
	life = INITPETLIFE[aseed] + level * 3;
	name=PETLIST[aseed];
	power = INITPETPOWER[aseed] + level;
	protectPower = INITPETPROTECT[aseed] + level;
	PP = INITPETPP[aseed] + level * 3;
	money=INITPETMONEY[aseed]+ level * 10;
	element= INITPETELEMENT[aseed];
	initSkills(aseed);
}

int Pet::getaseed()const {
	return aseed;
}

Pet::~Pet()
{
}

double Pet::ElementFight(Pet * pet) {
	if (getElement() != 0) {
		if (getElement() - pet->getElement() == 1)return 0.7;
		if (pet->getElement() - getElement() == 1)return 1.3;
		if (getElement() == 4 && pet->getElement() == 0)return 1.3;
		return 1;
	}
	else {
		if (pet->getElement() == 1)return 1.3;
		if (pet->getElement() == 4)return 0.7;
		return 1;
	}
}

int Pet::getNowLife()const {
	return nowLife;
}
void Pet::setNowLife(int x) {
	nowLife = x;
}
void Pet::setNowPP(int x) {
	nowPP = x;
}
int  Pet::getNowPP()const {
	return nowPP;
}



void Pet::initSkills(int aseed) {
	skillCount = SKILLCOUNT[aseed];
	int skillseed = 0;
	for (int i = 0; i < aseed; i++)skillseed += SKILLCOUNT[i];
	for (int i = 0; i < skillCount; i++) {
		Skill* newskill = new Skill(skillseed + i);
		Skills.push_back(newskill);
	}

}

int  Pet::getSkillCount() {
	return skillCount;
}

Skill* Pet::getSkill(int i)const {
	return Skills[i];
}

void Pet::showInfo() const
{
	cout << name << "\t\t" << "元素:" << ELEMENT[element] << endl
		<< "HP:" << getNowLife()<<"/"<< getLife()<< "\t" << "攻击力:" << getPower() << "\t" << "防御力:" << getProtectPower() << endl
		<< "等级:" << getLevel() << "\t\t"   << "PP:" << getNowPP() << "/" << getPP() << endl;
	for(int i=0;i< skillCount;i++)cout<<i+1<<"."<< Skills[i]->getName() << "\t";
	cout << "\n";
}

string Pet::getName() {
	return name;
}
void Pet::setName(std::string name) {
	this->name = name;
}

void Pet::setPP(int SkillPP)
{
	this->PP = SkillPP;
}
int Pet::getPP()const {
	return PP;
}



int Pet::getLife()const
{
	return this->life;
}

void Pet::setLife(int life)
{
	this->life = life;
}

int Pet::getPower()const
{
	return this->power;
}

void Pet::setPower(int power)
{
	this->power = power;
}

int Pet::getProtectPower()const
{
	return protectPower;
}

void Pet::setProtectPower(int protectPower)
{
	this->protectPower = protectPower;
}

int Pet::getLevel()const
{
	return this->level;
}

void Pet::setLevel(int level)
{
	this->level = level;
}

int Pet::getMoney()const
{
	return this->money;
}

void Pet::setMoney(int money)
{
	this->money = money;
}
void Pet::setElement(int element) {
	this->element = element;
}
int Pet::getElement()const {
	return element;
}

