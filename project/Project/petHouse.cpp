#include "petHouse.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


petHouse::petHouse(int capacity) :capacity(capacity) {}

petHouse::petHouse(const petHouse& wareho)
{
	this->capacity = wareho.capacity;
	for (unsigned i = 0; i < wareho.pets.size(); i++) {
		(this->pets).push_back(wareho.pets[i]);
	}
}

bool petHouse::add(Pet* pet) {
	if (pets.size() <= capacity) {
		pets.push_back(pet);//����Ʒ���뱳��
		//cout << "The good has been put in your bag!" << endl;
		return true;
	}
	else {
		cout << "�ֿ�����!" << endl;
		return false;
	}
}

void petHouse::remove(Pet* pet) {
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

void petHouse::showInfo()
{
	//cout << "����������" << endl;
	//int index = 0;
	for (unsigned i = 0; i < pets.size(); i++)
		cout << i + 1 << "." << pets[i]->getName() << "\t";
	cout << endl;
	/*for (vector<Item*>::iterator it = goods.begin(); it != goods.end(); ++it)
		cout << (++index) << "." << *it << "\t\t";
	cout << endl;*/
}

int petHouse::getNowSize() const
{
	return static_cast<int>(pets.size());
}

int petHouse::getCapacity() const
{
	return this->capacity;
}

Pet* petHouse::getPetByIndex(int index)
{
	return pets[index];
}

petHouse::~petHouse() {

}
