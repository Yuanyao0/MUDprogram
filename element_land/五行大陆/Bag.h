#pragma once
#ifndef __BAG_H__
#define __BAG_H__
#include <vector>
#include <string>
#include "Pet.h"
// jsffjajfoajfoajf
class Bag
{
public:
	Bag(int capacity);
	Bag(const Bag& bag);
	bool add(Pet * pet);//��������,�ɹ��棻װ���·��ؼ�;
	void remove(Pet* pet);//ɾ��pet
	void showInfo();//��ʾ�������� 
	int getNowSize()const;//��ȡ��ǰ����
	int getCapacity()const;//��ȡ�������ܴ�С
	int getNowEggSize()const;//��ȡ��ǰ��׽������
	int getEggCapacity()const;//��ȡ��׽������
	Pet* getPetByIndex(int index);//ͨ����Ż�ȡ����
	~Bag();
private:
	int capacity;//������������
	int num;//�������г�������
	std::vector<Pet*> pets;//�����ڵĳ���
	int eggCapacity;//������׽������
	int eggNum;//�������в�׽������
};

#endif // !__BAG_H__