#pragma once
#ifndef __BAG_H__
#define __BAG_H__
#include <vector>
#include <string>
#include "Pet.h"
#include "Egg.h"
class Bag
{
public:
	Bag();
	Bag(int capacity);
	Bag(const Bag& bag);
	bool add(Pet * pet);//��������,�ɹ��棻װ���·��ؼ�;
	bool addEgg(Egg* egg);
	void remove(Pet* pet);//ɾ��pet
	void showInfo();//��ʾ��������
	void EggshowInfo();//��ʾ���е�
	int getNowSize()const;//��ȡ��ǰ����
	int getCapacity()const;//��ȡ�������ܴ�С
	int getNowEggSize()const;//��ȡ��ǰ��׽������
	int getEggCapacity()const;//��ȡ��׽������
	Pet* getPetByIndex(int index);//ͨ����Ż�ȡ����
	~Bag();
	void remove(Egg*);//ɾ��egg
	Egg* getEggByIndex(int index);//ͨ����Ż�ȡ��׽��

private:
	int capacity=CAPACITY;//������������
	std::vector<Pet*> pets;//�����ڵĳ���
	std::vector<Egg*> eggs;//�����ڵĳ���
	int eggCapacity= EGGCAPACITY;//������׽������
};

#endif // !__BAG_H__