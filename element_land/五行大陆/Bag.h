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
	bool add(Pet * pet);//加入容器,成功真；装不下返回假;
	void remove(Pet* pet);//删除pet
	void showInfo();//显示所有名字 
	void setEgg(int x);//设置捕捉蛋数量
=======
	bool add(Item* item);
	void remove(Item* item);
	Item* getItemByIndex(int index)const;
	bool add(Pet * pet);//加入容器,成功真；装不下返回假;
	void remove(Pet* pet);//删除pet
	void showInfo();//显示所有名字 
>>>>>>> 06e52ffab56565c9416ca77253b3e1b46f06ac85
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
<<<<<<< HEAD
	int eggCapacity;//背包捕捉蛋容量
	int eggNum;//背包现有捕捉蛋数量
=======
	std::vector<Item*>items;//背包中物品列表
	int eggCapacity;//背包捕捉蛋容量
	int eggNum;//背包现有捕捉蛋数量

>>>>>>> 06e52ffab56565c9416ca77253b3e1b46f06ac85
};

#endif // !__BAG_H__