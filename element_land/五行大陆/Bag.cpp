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

<<<<<<< HEAD
void Bag::setEgg(int x) {
	this->eggNum = x;
}

int Bag::getNowEggSize()const
{
	return eggNum;
}
int Bag::getEggCapacity()const
{
	return eggCapacity;
}


=======
>>>>>>> 06e52ffab56565c9416ca77253b3e1b46f06ac85
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
	//vector<Item*>::iterator it;
	//for (it = goods.begin(); it != goods.end(); ++it)
	//	if (*it == item)
	//		break;
	//for (vector<Item*>::iterator it1 = goods.begin(); it1 != goods.end(); ++it1) {
	//	if (it1 == it)
	//		continue;
	//	goods_.push_back(*it1);
	//}
	//用迭代器蜜汁出错，fuck
	unsigned i ;
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

void Bag::showInfo()
{
	//cout << "函数调试中" << endl;
	//int index = 0;
	for (unsigned i = 0; i < pets.size(); i++)
		cout << i + 1 << "." << pets[i]->getName() << "\t";
	cout << endl;
	/*for (vector<Item*>::iterator it = goods.begin(); it != goods.end(); ++it)
		cout << (++index) << "." << *it << "\t\t";
	cout << endl;*/
}

int Bag::getNowSize() const
{
	return static_cast<int>(pets.size());
}

int Bag::getCapacity() const
{
	return this->capacity;
}


Pet* Bag::getPetByIndex(int index)
{
	return pets[index];
}

Bag::~Bag() {

}


