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
		pets.push_back(pet);//����Ʒ���뱳��
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
	//ɾ��������Ʒ���ҵ���˳���ٿ�һ��VECTOR push ��ȥ������item����һ��goods��ָ��
}

bool Bag::addEgg(Egg*egg)//��������,�ɹ��棻װ���·��ؼ�;
{
	if (eggs.size() < eggCapacity) {
		eggs.push_back(egg);//����Ʒ���뱳��
		//cout << "The good has been put in your bag!" << endl;
		return true;
	}
	else {
		//cout << "Sorry,your bag is full!" << endl;
		return false;
	}
}

void Bag::remove(Egg*egg)//ɾ��egg
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
	else cout << "����INDEX������Χ��\n";
	return NULL;
}
Pet* Bag::getPetByIndex(int index)
{
	if (index  < pets.size())
		return pets[index];
	else cout << "�����INDEX������Χ��\n";
	return NULL;
	
}

Bag::~Bag() {

}

