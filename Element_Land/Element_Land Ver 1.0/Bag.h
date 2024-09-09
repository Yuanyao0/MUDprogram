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
	bool add(Pet * pet);//加入容器,成功真；装不下返回假;
	bool addEgg(Egg* egg);
	void remove(Pet* pet);//删除pet
	void showInfo();//显示所有名字
	void EggshowInfo();//显示所有蛋
	int getNowSize()const;//获取当前数量
	int getCapacity()const;//获取容器的总大小
	int getNowEggSize()const;//获取当前捕捉蛋数量
	int getEggCapacity()const;//获取捕捉蛋容量
	Pet* getPetByIndex(int index);//通过编号获取宠物
	~Bag();
	void remove(Egg*);//删除egg
	Egg* getEggByIndex(int index);//通过编号获取捕捉蛋

private:
	int capacity=CAPACITY;//背包宠物容量
	std::vector<Pet*> pets;//背包内的宠物
	std::vector<Egg*> eggs;//背包内的宠物
	int eggCapacity= EGGCAPACITY;//背包捕捉蛋容量
};

#endif // !__BAG_H__