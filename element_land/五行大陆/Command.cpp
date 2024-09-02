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
   std::cout << "��ѡ����ĳ�ʼ���" << std::endl;
   std::cout<<"1.�ƽ���  2.Գ��  3.Сˮ��  4.����ʨ"<<std::endl;
   int petnum;
   cin >> petnum;
   Pet* pet = new Pet(petnum - 1);
   player->getBag()->add(pet);
}




void Command::shop(Player* player) {
    std::cout << "��ӭ�����̵꣡�����ѡ����������ظ�HP��PP��" << std::endl;
    std::cout << "1.���������  2.�ظ�HP  3.�ظ�PP" << std::endl;
    std::cout << "��ѡ����Ҫ���еĲ���(�������)��";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        int noweggsize = player->getBag()->getEggCapacity(), capacity = player->getBag()->getCapacity();

        if (noweggsize >= capacity)
        {
            std::cout << "����������" << std::endl;
        }
        else
        {
            std::cout << "��������Ҫ�����������" << std::endl;
            int num;
            std::cin >> num;
            std::cout << "��������Ҫ��������ࣺ" << std::endl;
            std::cout << "1.��ͨ��  2.��Ӣ��  3.��ʦ��" << std::endl;
            int kind;
            std::cin >> kind;
            while (num > capacity - noweggsize)
            {
                std::cout << "�����������㣡���������룺" << std::endl;
                std::cin >> num;
            }
            if (player->getMoney() < EGGPRICE[kind-1] * num ) {
                std::cout << "��Ҳ��㣡" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - EGGPRICE[kind - 1] * num);
                for (int i=0; i < num; i++)
                {
                    Egg* egg = new Egg(kind);
                    player->getBag()->add(egg);
                }
            }
            cout << "�ɹ�����" << num << "��" << EGGNAME[kind - 1] << "!" << std::endl;
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
            std::cout << "���г���HP������ظ���" << std::endl;
        else 
        {
            if (player->getMoney() < HPPRICE) {
                std::cout << "��Ҳ��㣡" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - HPPRICE);
                for (int i = 0; i <player->getBag()->getEggCapacity() ; i++)
                {
                    player->getBag()->getPetByIndex(i)->setNowLife(player->getBag()->getPetByIndex(i)->getLife());
                }
                std::cout << "���г���HP���ѻظ���" << std::endl;
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
            std::cout << "���г���PP������ظ���" << std::endl;
        else
        {
            if (player->getMoney() < PPPRICE) {
                std::cout << "��Ҳ��㣡" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - PPPRICE);
                for (int i = 0; i < player->getBag()->getEggCapacity(); i++)
                {
                    player->getBag()->getPetByIndex(i)->setNowPP(player->getBag()->getPetByIndex(i)->getPP());
                }
                std::cout << "���г���PP���ѻظ���" << std::endl;
            }
        }
        break;
    default:
        std::cout << "��Ч��ѡ��" << std::endl;
        break;
    }

}