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
	bool add(Pet * pet);//加入容器,成功真；装不下返回假;
	void remove(Pet* pet);//删除pet
	void showInfo();//显示所有名字 
	int getNowSize()const;//获取当前数量
	int getCapacity()const;//获取容器的总大小
	int getNowEggSize()const;//获取当前捕捉蛋数量
	int getEggCapacity()const;//获取捕捉蛋容量
	Pet* getPetByIndex(int index);//通过编号获取宠物
	~Bag();
private:
	int capacity;//背包宠物容量
	int num;//背包现有宠物数量
	std::vector<Pet*> pets;//背包内的宠物
	int eggCapacity;//背包捕捉蛋容量
	int eggNum;//背包现有捕捉蛋数量
};

#endif // !__BAG_H__