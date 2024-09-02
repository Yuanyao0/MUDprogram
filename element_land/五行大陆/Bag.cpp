#include "Bag.h"
#include "Pet.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Bag::Bag(int capacity) :capacity(capacity) {}

Bag::Bag(const Bag& bag)
{
	this->capacity = bag.capacity;
	this->num = bag.num;
	for (unsigned i = 0; i < bag.pets.size(); i++) {
		(this->pets).push_back(bag.pets[i]);
	}
}


int Bag::getNowEggSize()const
{
	return eggNum;
}
int Bag::getEggCapacity()const
{
	return eggCapacity;
}

bool Bag::add(Pet * pet) {
	num++;
	if (num <= capacity) {
		pets.push_back(pet);//将物品放入背包
		//cout << "The good has been put in your bag!" << endl;
		return true;
	}
	else {
		//cout << "Sorry,your bag is full!" << endl;
		num--;
		return false;
	}
}

void Bag::remove(Pet* pet) {
	vector<Pet*> pets_;
	unsigned i;
	for (i = 0; i < pets.size(); i++)
		if (pets[i] == pet)
			break;
	for (unsigned j = 0; j < pets.size(); j++) {
		if (j == i)
			continue;
		pets_.push_back(pets[j]);
	}

	pets = pets_;
	//删除参数物品并且调整顺序，再开一个VECTOR push 进去其他的item，换一下goods的指向
}

void Bag::setNowEggNum(int x)//设置捕捉蛋数量
{
	eggNum = x;
}
bool Bag::add(Egg*egg)//加入容器,成功真；装不下返回假;
{
	eggNum++;
	if (eggNum <= eggCapacity) {
		eggs.push_back(egg);//将物品放入背包
		//cout << "The good has been put in your bag!" << endl;
		return true;
	}
	else {
		//cout << "Sorry,your bag is full!" << endl;
		eggNum--;
		return false;
	}
}

void Bag::remove(Egg*egg)//删除egg
{
	vector<Egg*> eggs_;
	unsigned i;
	for (i = 0; i < eggs.size(); i++)
		if (eggs[i] == egg)
			break;
	for (unsigned j = 0; j < eggs.size(); j++) {
		if (j == i)
			continue;
		eggs_.push_back(eggs[j]);
	}

	eggs = eggs_;
}

void Bag::showInfo()
{
	for (unsigned i = 0; i < pets.size(); i++)
		cout << i + 1 << "." << pets[i]->getName() << "\t";
	cout << endl;
}
void Bag::EggshowInfo()
{
	for (unsigned i = 0; i < eggs.size(); i++)
		cout << i + 1 << "." << eggs[i]->getName() << "\t";
	cout << endl;
}

int Bag::getNowSize() const
{
	return static_cast<int>(pets.size());
}

int Bag::getCapacity() const
{
	return this->capacity;
}

Egg* Bag::getEggByIndex(int index)
{
	return eggs[index];
}
Pet* Bag::getPetByIndex(int index)
{
	return pets[index];
}

Bag::~Bag() {

}

