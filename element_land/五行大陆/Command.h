#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "petHouse.h"
#include "Player.h"
class Command {
public:
	static void newGame();//ѡ������Ϸ
	static void newerCountry(Player* player, Bag * ware = NULL);//���ִ�
	static void petHouse( Player* player);//���вֿ�Ի�
	static void shop(Player* player);//�����̵�Ի�
	static void clearCin();//�����������Ϣ�Լ�������Ϣ

};
#endif // !__COMMAND_H__