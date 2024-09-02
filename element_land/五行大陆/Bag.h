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
	Bag(int capacity);
	Bag(const Bag& bag);
	bool add(Pet * pet);//��������,�ɹ��棻װ���·��ؼ�;
	void remove(Pet* pet);//ɾ��pet
	void showInfo();//��ʾ��������
	void EggshowInfo();//��ʾ���е�
	int getNowSize()const;//��ȡ��ǰ����
	int getCapacity()const;//��ȡ�������ܴ�С
	int getNowEggSize()const;//��ȡ��ǰ��׽������
	int getEggCapacity()const;//��ȡ��׽������
	Pet* getPetByIndex(int index);//ͨ����Ż�ȡ����
	~Bag();
	void setNowEggNum(int x);//���ò�׽������
	bool add(Egg*);//��������,�ɹ��棻װ���·��ؼ�;
	void remove(Egg*);//ɾ��egg
	Egg* getEggByIndex(int index);//ͨ����Ż�ȡ��׽��

private:
	int capacity;//������������
	std::vector<Pet*> pets;//�����ڵĳ���
	std::vector<Egg*> eggs;//�����ڵĳ���
	int eggCapacity;//������׽������
	int num;//��������
	int eggNum;//������׽��
};

#endif // !__BAG_H__