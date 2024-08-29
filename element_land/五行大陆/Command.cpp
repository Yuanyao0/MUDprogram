#include "Command.h"
#include "Item.h"
#include <iostream>

void Command::shop(Player* player) {
    std::cout << "欢迎来到商店！你可以购买以下物品：" << std::endl;
    std::cout << "1. HP药水 - 10金币" << std::endl;
    std::cout << "2. PP药水 - 10金币" << std::endl;
    std::cout << "3. 宠物球 - 20金币" << std::endl;
    std::cout << "请选择你要购买的物品 (输入序号)：";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        if (player->getMoney() >= 10) {
            player->reduceMoney(10);
            player->getBag()->add(new HPPotion());
            std::cout << "你购买了一瓶HP药水。" << std::endl;
        }
        else {
            std::cout << "金币不足！" << std::endl;
        }
        break;
    case 2:
        if (player->getMoney() >= 10) {
            player->reduceMoney(10);
            player->getBag()->add(new PPPotion());
            std::cout << "你购买了一瓶PP药水。" << std::endl;
        }
        else {
            std::cout << "金币不足！" << std::endl;
        }
        break;
    case 3:
        if (player->getMoney() >= 20) {
            player->reduceMoney(20);
            player->getBag()->add(new PokeBall());
            std::cout << "你购买了一个宠物球。" << std::endl;
        }
        else {
            std::cout << "金币不足！" << std::endl;
        }
        break;
    default:
        std::cout << "无效的选择。" << std::endl;
        break;
    }
}