#include "Item.h"
#include <iostream>


Item::Item(std::string name, int price) : name(name), price(price) {}
Item::~Item() {}
std::string Item::getName() const { return name; }
int Item::getPrice() const { return price; }

// HPPotion类实现
HPPotion::HPPotion() : Item("HP Potion", 10) {}

void HPPotion::use(Pet* pet) {
    int hp = pet->getLife();
    pet->setLife(hp + hp / 2);  // 回复50%HP
    std::cout << "使用了一瓶HP药水，宠物的HP恢复了50%!" << std::endl;
}

// PPPotion类实现
PPPotion::PPPotion() : Item("PP Potion", 10) {}

void PPPotion::use(Pet* pet) {
    // Pet类restoreSkillPP()
    pet->restoreSkillPP();  // 恢复宠物的技能使用次数
    std::cout << "使用了一瓶PP药水，宠物的技能使用次数恢复了!" << std::endl;
}

// PokeBall类实现
PokeBall::PokeBall() : Item("Poke Ball", 20) {}

bool PokeBall::use(Pet* pet) {
    int maxHP = pet->getMaxLife();  // pet类getMaxLife()
    int currentHP = pet->getLife();
    double captureChance = 0.7 * (3 * maxHP - 2 * currentHP) / (3 * maxHP);
    if (captureChance >= 0.5) {
        std::cout << "捕捉成功!" << std::endl;
        return true;  
    }
    else {
        std::cout << "捕捉失败。" << std::endl;
        return false;  
    }
}