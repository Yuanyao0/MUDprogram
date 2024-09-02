#include"YourPet.h"
#include <iostream>
using namespace std;
yourPet::yourPet(){}
yourPet::yourPet(const Pet& pet) : nowLife(nowLife), level(level) ,nowPP(nowPP),aseed(aseed){
	init(aseed);
	initSkills(aseed);
}


yourPet::~yourPet() {
}
void yourPet::showInfo() const
{
	cout << name << "\t\t" << "元素:" << ELEMENT[element] << endl
		<< "HP:" << getNowLife() << "/" << getLife() << "\t\t" << "攻击力:" << getPower() << "\t" << "防御力:" << getProtectPower() << endl
		<< "等级:" << getLevel() << "\t\t"  << "PP:" << getNowPP() << "/" << getNowPP() << endl;
	for (int i = 0; i < skillCount; i++)cout << i + 1 << "." << Skills[i]->getName() << "\t";
	cout << "\n";
}
