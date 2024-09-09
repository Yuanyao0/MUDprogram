#pragma once
#ifndef FILESTORE_H
#define FILESTORE_H
#include "constTable.h"
#include "Player.h"
#include "petHouse.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*要保存的：

std::string playerName;//玩家数据
    int money;

    int num;//背包数据
    int eggNum;
    int nowLife[CAPACITY];//背包宠物数据
    int nowPP[CAPACITY];
    int level[CAPACITY];
    int aseed[CAPACITY];
    int kind[EGGCAPACITY];//背包蛋数据

    int houseNum;//仓库容量
    int nowLife[CAPACITY];//仓库宠物数据
    int nowPP[CAPACITY];
    int level[CAPACITY];
    int aseed[CAPACITY];
*/
    


// 用于读取和写入游戏数据的函数
static void saveGameData( Player* player,petHouse* pethouse, const std::string& filename) {
    std::ofstream file(filename);               //打开文件(只写)
    if (file.is_open()) {
        file << player->getName()<<"\n";
        file << player->getMoney() << "\n";
        file << player->getBag()->getNowSize() << "\n";
        file << player->getBag()->getNowEggSize() << "\n";
        for (int i = 0; i < player->getBag()->getNowSize(); i++) {
            file << player->getBag()->getPetByIndex(i)->getNowLife() << "\n";
        }
        for (int i = 0; i < player->getBag()->getNowSize(); i++) {
            file << player->getBag()->getPetByIndex(i)->getNowPP() << "\n";
        }
        for (int i = 0; i < player->getBag()->getNowSize(); i++) {
            file << player->getBag()->getPetByIndex(i)->getLevel() << "\n";
        }
        for (int i = 0; i < player->getBag()->getNowSize(); i++) {
            file << player->getBag()->getPetByIndex(i)->getaseed() << "\n";
        }

        for (int i = 0; i < player->getBag()->getNowEggSize(); i++) {
            file << player->getBag()->getEggByIndex(i)->getKind() << "\n";
        }
        
        file << pethouse->getNowSize() << "\n";
        for (int i = 0; i < pethouse->getNowSize(); i++) {
            file << pethouse->getPetByIndex(i)->getNowLife() << "\n";
        }
        for (int i = 0; i < pethouse->getNowSize(); i++) {
            file << pethouse->getPetByIndex(i)->getNowPP() << "\n";
        }
        for (int i = 0; i < pethouse->getNowSize(); i++) {
            file << pethouse->getPetByIndex(i)->getLevel() << "\n";
        }
        for (int i = 0; i < pethouse->getNowSize(); i++) {
            file << pethouse->getPetByIndex(i)->getaseed() << "\n";
        }
        
        file.close();
        std::cout << "游戏数据已保存。\n";
    }
    else {
        std::cerr << "无法打开文件进行保存。\n";
    }
}


static void readGameData(Player* player, petHouse* pethouse, const std::string& filename) {
    std::ifstream file(filename);                       //打开文件，只读
    int EggNum = 0;
    int Num = 0;
    int houseNum = 0;
    if (file.is_open()) {
        int a=-1;
        string b = "";
        if(file >> b)
            player->setName(b);
        if(file >> a)
            player->setMoney(a) ;
        if (file >> a) {
            Bag* bag = new Bag(CAPACITY);
            player->setBag(*bag);
            Num=a;
        }
            
        for (int i = 0; i < Num; i++) {
                Pet* newpet = new Pet();
                player->getBag()->add(newpet);
        }

        if(file >> a)
            EggNum=a;

        for (int i = 0; i < Num; i++) {
            if(file >>a)
                player->getBag()->getPetByIndex(i)->setNowLife(a);
        }
        for (int i = 0; i < Num; i++) {
            if (file >> a)
                player->getBag()->getPetByIndex(i)->setNowPP(a);
        }
        for (int i = 0; i < Num; i++) {
            if (file >> a)
                player->getBag()->getPetByIndex(i)->setLevel(a);
        }
        for (int i = 0; i < Num; i++) {
            if (file >> a)
                player->getBag()->getPetByIndex(i)->setaseed(a);
        }

        for (int i = 0; i < player->getBag()->getNowSize(); i++)player->getBag()->getPetByIndex(i)->init(
            player->getBag()->getPetByIndex(i)->getNowLife(),
            player->getBag()->getPetByIndex(i)->getNowPP(),
            player->getBag()->getPetByIndex(i)->getLevel(),
            player->getBag()->getPetByIndex(i)->getaseed());

        for (int i = 0; i < EggNum; i++) {
            if (file >> a) {
                Egg* newegg = new Egg(a);
                player->getBag()->addEgg(newegg);
            }
        }

        if (file >> a)houseNum=a;


        for (int i = 0; i < houseNum; i++) {
                Pet* newpet = new Pet();
                pethouse->add(newpet);
        }

        for (int i = 0; i < houseNum; i++) {
            if(file >>a)
                pethouse->getPetByIndex(i)->setNowLife(a);
        }
        for (int i = 0; i < houseNum; i++) {
            if (file >> a)pethouse->getPetByIndex(i)->setNowPP(a);
        }
        for (int i = 0; i < houseNum; i++) {
            if (file >> a)pethouse->getPetByIndex(i)->setLevel(a);
        }
        for (int i = 0; i < houseNum; i++) {
            if (file >> a)pethouse->getPetByIndex(i)->setaseed(a);
        }
        for (int i = 0; i < Num; i++) {
            player->getBag()->getPetByIndex(i)->init(
                player->getBag()->getPetByIndex(i)->getNowLife(),
                player->getBag()->getPetByIndex(i)->getNowPP(), 
                player->getBag()->getPetByIndex(i)->getLevel(),
                player->getBag()->getPetByIndex(i)->getaseed());
        }
        for (int i = 0; i < houseNum; i++) {
            pethouse->getPetByIndex(i)->init(
                pethouse->getPetByIndex(i)->getNowLife(),
                pethouse->getPetByIndex(i)->getNowPP(),
                pethouse->getPetByIndex(i)->getLevel(),
                pethouse->getPetByIndex(i)->getaseed());
        }

        file.close();
    }
    else {
        std::cerr << "无法打开文件进行读取。\\n";
    }
}

#endif // !FILESTORE_H