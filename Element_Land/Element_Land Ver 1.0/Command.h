#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "petHouse.h"
#include "Battle.h"
#include "FileStore.h"
#include "Utill.h"
class Command {
public:
	static void showShop();
	static void newGame();//选择新游戏
	static void changeMap(int& pos, Player& player);
	static void shop(Player* player);//进行商店对话
	static void showShopEgg(Player* player);
	static void newshow();
	static void showChoice(int x);
	static void showMapChoice(int x);
	static void clearCin();
	static void House(Player* player,petHouse* );
};
#endif // !__COMMAND_H__