#pragma once
#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include "Pet.h"  
class Item {
public:
    Item(std::string name, int price);
    virtual ~Item();

    std::string getName() const;
    int getPrice() const;
    virtual void use(Pet* pet) = 0;  

private:
    std::string name;
    int price;
};

class HPPotion : public Item {
public:
    HPPotion();
    void use(Pet* pet) override;  // 实现使用HP药水的功能
};

class PPPotion : public Item {
public:
    PPPotion();
    void use(Pet* pet) override;  // 实现使用PP药水的功能
};

class PokeBall : public Item {
public:
    PokeBall();
    bool use(Pet* pet) override;  // 实现使用宠物球的功能
};

#endif