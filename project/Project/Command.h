#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "petHouse.h"
#include "Battle.h"
#include "FileStore.h"
class Command {
public:
	static void showShop();
	static void newGame();//ѡ������Ϸ
	static void changeMap(int& pos, Player& player);
	static void shop(Player* player);//�����̵�Ի�
	static void showShopEgg(Player* player);
};
#endif // !__COMMAND_H__