#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "petHouse.h"
#include "Player.h"
class Command {
public:
	static void newGame();//选择新游戏
	static void newerCountry(Player* player, Bag * ware = NULL);//新手村
	static void petHouse( Player* player);//进行仓库对话
	static void shop(Player* player);//进行商店对话
	static void clearCin();//清除缓冲区信息以及错误信息

};
#endif // !__COMMAND_H__