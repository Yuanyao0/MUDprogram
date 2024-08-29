#include <iostream>
#include <ctime>
#include "Pet.h"
#include "ConstTable.h"
using namespace std;
Pet::Pet()
{
}

Pet::Pet(std::string name, int life,int power, int exp,
	int protectPower, int level, int count) :
	 life(life), power(power), exp(exp), protectPower(protectPower), level(level), money(money) {}

Pet::~Pet()
{
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

int Pet::getExp()const
{
	return this->exp;
}

void Pet::setExp(int exp)
{
	this->exp = exp;
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

