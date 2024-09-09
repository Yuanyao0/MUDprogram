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
	bool add(Pet* pet);//加入容器,成功真；装不下返回假;
	void remove(Pet* pet);//删除pet
	void showInfo();//显示所有名字 
	int getNowSize()const;//获取当前数量
	int getCapacity()const;//获取容器的总大小
	Pet* getPetByIndex(int index);//通过编号获取宠物
	~petHouse();
private:
	int capacity=HOUSECAPACITY;//背包容量
	std::vector<Pet*> pets;//仓库内的宠物
};

#endif // !__WAREHOUSE_H__