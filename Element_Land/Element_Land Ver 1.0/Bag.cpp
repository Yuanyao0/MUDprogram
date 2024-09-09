#include "Bag.h"
#include "Pet.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Bag::Bag(){}

Bag::Bag(int capacity) :capacity(capacity) {}

Bag::Bag(const Bag& bag)
{
	this->capacity = bag.capacity;
	for (unsigned i = 0; i < bag.pets.size(); i++) {
		(this->pets).push_back(bag.pets[i]);
	}
}


int Bag::getNowEggSize()const
{
	return static_cast<int>(eggs.size());
}
int Bag::getEggCapacity()const
{
	return eggCapacity;
}

bool Bag::add(Pet * pet) {
	if (pets.size() < capacity) {
		pets.push_back(pet);//将物品放入背包
		//cout << "The good has been put in your bag!" << endl;
		return true;
	}
	else {
		//cout << "Sorry,your bag is full!" << endl;
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

bool Bag::addEgg(Egg*egg)//加入容器,成功真；装不下返回假;
{
	if (eggs.size() < eggCapacity) {
		eggs.push_back(egg);//将物品放入背包
		//cout << "The good has been put in your bag!" << endl;
		return true;
	}
	else {
		//cout << "Sorry,your bag is full!" << endl;
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
	for (unsigned i = 0; i < eggs.size(); i++) {
		cout << i + 1 << "." << eggs[i]->getName() << "\t";
		if ((i - 1) % 2 == 0)cout << "\n";

	}
	cout<<eggs.size() <<"/"<<eggCapacity <<endl;
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
	if (index  < eggs.size())
		return eggs[index];
	else cout << "蛋的INDEX超出范围！\n";
	return NULL;
}
Pet* Bag::getPetByIndex(int index)
{
	if (index  < pets.size())
		return pets[index];
	else cout << "宠物的INDEX超出范围！\n";
	return NULL;
	
}

Bag::~Bag() {

}

