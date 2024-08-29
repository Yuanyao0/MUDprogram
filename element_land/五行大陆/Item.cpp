#include "Item.h"
#include <iostream>


Item::Item(std::string name, int price) : name(name), price(price) {}
Item::~Item() {}
std::string Item::getName() const { return name; }
int Item::getPrice() const { return price; }

// HPPotion��ʵ��
HPPotion::HPPotion() : Item("HP Potion", 10) {}

void HPPotion::use(Pet* pet) {
    int hp = pet->getLife();
    pet->setLife(hp + hp / 2);  // �ظ�50%HP
    std::cout << "ʹ����һƿHPҩˮ�������HP�ָ���50%!" << std::endl;
}

// PPPotion��ʵ��
PPPotion::PPPotion() : Item("PP Potion", 10) {}

void PPPotion::use(Pet* pet) {
    // Pet��restoreSkillPP()
    pet->restoreSkillPP();  // �ָ�����ļ���ʹ�ô���
    std::cout << "ʹ����һƿPPҩˮ������ļ���ʹ�ô����ָ���!" << std::endl;
}

// PokeBall��ʵ��
PokeBall::PokeBall() : Item("Poke Ball", 20) {}

bool PokeBall::use(Pet* pet) {
    int maxHP = pet->getMaxLife();  // pet��getMaxLife()
    int currentHP = pet->getLife();
    double captureChance = 0.7 * (3 * maxHP - 2 * currentHP) / (3 * maxHP);
    if (captureChance >= 0.5) {
        std::cout << "��׽�ɹ�!" << std::endl;
        return true;  
    }
    else {
        std::cout << "��׽ʧ�ܡ�" << std::endl;
        return false;  
    }
}