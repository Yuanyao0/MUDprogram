#include "Command.h"
#include "Item.h"
#include <iostream>

void Command::shop(Player* player) {
    std::cout << "��ӭ�����̵꣡����Թ���������Ʒ��" << std::endl;
    std::cout << "1. HPҩˮ - 10���" << std::endl;
    std::cout << "2. PPҩˮ - 10���" << std::endl;
    std::cout << "3. ������ - 20���" << std::endl;
    std::cout << "��ѡ����Ҫ�������Ʒ (�������)��";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        if (player->getMoney() >= 10) {
            player->reduceMoney(10);
            player->getBag()->add(new HPPotion());
            std::cout << "�㹺����һƿHPҩˮ��" << std::endl;
        }
        else {
            std::cout << "��Ҳ��㣡" << std::endl;
        }
        break;
    case 2:
        if (player->getMoney() >= 10) {
            player->reduceMoney(10);
            player->getBag()->add(new PPPotion());
            std::cout << "�㹺����һƿPPҩˮ��" << std::endl;
        }
        else {
            std::cout << "��Ҳ��㣡" << std::endl;
        }
        break;
    case 3:
        if (player->getMoney() >= 20) {
            player->reduceMoney(20);
            player->getBag()->add(new PokeBall());
            std::cout << "�㹺����һ��������" << std::endl;
        }
        else {
            std::cout << "��Ҳ��㣡" << std::endl;
        }
        break;
    default:
        std::cout << "��Ч��ѡ��" << std::endl;
        break;
    }
}