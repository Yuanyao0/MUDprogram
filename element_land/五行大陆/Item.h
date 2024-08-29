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
    void use(Pet* pet) override;  // ʵ��ʹ��HPҩˮ�Ĺ���
};

class PPPotion : public Item {
public:
    PPPotion();
    void use(Pet* pet) override;  // ʵ��ʹ��PPҩˮ�Ĺ���
};

class PokeBall : public Item {
public:
    PokeBall();
    bool use(Pet* pet) override;  // ʵ��ʹ�ó�����Ĺ���
};

#endif