#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "Pet.h"
#include "petHouse.h"
#include "Player.h"
class Command {
public:
	static void newGame();//ѡ������Ϸ
	static void newerCountry(Player* player, int(&backupMap)[MAPROW][MAPCOLUMN], Container* ware = NULL);//���ִ�
	static void wareshop(Map& map, Player* player);//���вֿ�Ի�
	static void weapon(Player* player);//����������Ի�
	static void hospital(Player* player);//����ҽ�ݶԻ�
	static void shop(Player* player);  // �̵깦�ܵ�����
	static void useItem(Player* player);  // ʹ����Ʒ���ܵ�����
	static void clearCin();//�����������Ϣ�Լ�������Ϣ

};
#endif // !__COMMAND_H__