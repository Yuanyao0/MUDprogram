#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "Pet.h"
#include "petHouse.h"
#include "Player.h"
class Command {
public:
	static void newGame();//选择新游戏
	static void newerCountry(Player* player, int(&backupMap)[MAPROW][MAPCOLUMN], Container* ware = NULL);//新手村
	static void wareshop(Map& map, Player* player);//进行仓库对话
	static void weapon(Player* player);//进行武器店对话
	static void hospital(Player* player);//进行医馆对话
	static void shop(Player* player);  // 商店功能的声明
	static void useItem(Player* player);  // 使用物品功能的声明
	static void clearCin();//清除缓冲区信息以及错误信息

};
#endif // !__COMMAND_H__