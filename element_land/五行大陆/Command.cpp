#include "Command.h"
#include"constTable.h"
#include "Player.h"
#include <iostream>

void Command::newGame()
{

   string name;
   std::cin >> name;
   Bag bag = Bag(CAPACITY);
   Player * player = new Player(name, 5, 100, bag);
   std::cout << "请选择你的初始宠物：" << std::endl;
   std::cout<<"1.黄金兽  2.猿神  3.小水怪  4.烈焰狮"<<std::endl;
   int petnum;
   cin >> petnum;
   Pet* pet = new Pet(petnum - 1);
   player->getBag()->add(pet);
}




void Command::shop(Player* player) {
    std::cout << "欢迎来到商店！你可以选择购买宠物球或回复HP和PP：" << std::endl;
    std::cout << "1.购买宠物球  2.回复HP  3.回复PP" << std::endl;
    std::cout << "请选择你要进行的操作(输入序号)：";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        int noweggsize = player->getBag()->getEggCapacity(), capacity = player->getBag()->getCapacity();

        if (noweggsize >= capacity)
        {
            std::cout << "背包已满！" << std::endl;
        }
        else
        {
            std::cout << "请输入你要购买的数量：" << std::endl;
            int num;
            std::cin >> num;
            std::cout << "请输入你要购买的种类：" << std::endl;
            std::cout << "1.普通球  2.精英球  3.大师球" << std::endl;
            int kind;
            std::cin >> kind;
            while (num > capacity - noweggsize)
            {
                std::cout << "背包容量不足！请重新输入：" << std::endl;
                std::cin >> num;
            }
            if (player->getMoney() < EGGPRICE[kind-1] * num ) {
                std::cout << "金币不足！" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - EGGPRICE[kind - 1] * num);
                for (int i=0; i < num; i++)
                {
                    Egg* egg = new Egg(kind);
                    player->getBag()->add(egg);
                }
            }
            cout << "成功购买" << num << "个" << EGGNAME[kind - 1] << "!" << std::endl;
        }
        break;
    case 2:
        int k = 0;
        for (int i = 1; i <= player->getBag()->getCapacity(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife())
            {
                k = 1;
            }               
        }
        if (k == 0)
            std::cout << "所有宠物HP均无需回复！" << std::endl;
        else 
        {
            if (player->getMoney() < HPPRICE) {
                std::cout << "金币不足！" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - HPPRICE);
                for (int i = 0; i <player->getBag()->getEggCapacity() ; i++)
                {
                    player->getBag()->getPetByIndex(i)->setNowLife(player->getBag()->getPetByIndex(i)->getLife());
                }
                std::cout << "所有宠物HP均已回复！" << std::endl;
            }
        }    
        break;
    case 3:
        int m = 0;
        for (int i = 1; i <= player->getBag()->getCapacity(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife())
            {
                m = 1;
            }
        }
        if (m == 0)
            std::cout << "所有宠物PP均无需回复！" << std::endl;
        else
        {
            if (player->getMoney() < PPPRICE) {
                std::cout << "金币不足！" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - PPPRICE);
                for (int i = 0; i < player->getBag()->getEggCapacity(); i++)
                {
                    player->getBag()->getPetByIndex(i)->setNowPP(player->getBag()->getPetByIndex(i)->getPP());
                }
                std::cout << "所有宠物PP均已回复！" << std::endl;
            }
        }
        break;
    default:
        std::cout << "无效的选择。" << std::endl;
        break;
    }

}