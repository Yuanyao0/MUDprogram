#pragma once
#ifndef __BAG_H__
#define __BAG_H__
#include <vector>
#include <string>
#include "Pet.h"
class Bag
{
public:
	Bag(int capacity);
	Bag(const Bag& bag);
<<<<<<< HEAD
	bool add(Pet * pet);//��������,�ɹ��棻װ���·��ؼ�;
	void remove(Pet* pet);//ɾ��pet
	void showInfo();//��ʾ�������� 
	void setEgg(int x);//���ò�׽������
=======
	bool add(Item* item);
	void remove(Item* item);
	Item* getItemByIndex(int index)const;
	bool add(Pet * pet);//��������,�ɹ��棻װ���·��ؼ�;
	void remove(Pet* pet);//ɾ��pet
	void showInfo();//��ʾ�������� 
>>>>>>> 06e52ffab56565c9416ca77253b3e1b46f06ac85
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
<<<<<<< HEAD
	int eggCapacity;//������׽������
	int eggNum;//�������в�׽������
=======
	std::vector<Item*>items;//��������Ʒ�б�
	int eggCapacity;//������׽������
	int eggNum;//�������в�׽������

>>>>>>> 06e52ffab56565c9416ca77253b3e1b46f06ac85
};

#endif // !__BAG_H__