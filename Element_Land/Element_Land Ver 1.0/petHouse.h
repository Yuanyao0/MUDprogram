#pragma once
#ifndef __PETHOUSE_H__
#define __PETHOUSE_H__
#include <vector>
#include <string>
#include "Pet.h"
class petHouse
{
public:
	petHouse(int capacity);
	petHouse(const petHouse& wareho);
	bool add(Pet* pet);//��������,�ɹ��棻װ���·��ؼ�;
	void remove(Pet* pet);//ɾ��pet
	void showInfo();//��ʾ�������� 
	int getNowSize()const;//��ȡ��ǰ����
	int getCapacity()const;//��ȡ�������ܴ�С
	Pet* getPetByIndex(int index);//ͨ����Ż�ȡ����
	~petHouse();
private:
	int capacity=HOUSECAPACITY;//��������
	std::vector<Pet*> pets;//�ֿ��ڵĳ���
};

#endif // !__WAREHOUSE_H__