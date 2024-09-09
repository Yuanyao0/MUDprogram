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

/*Ҫ����ģ�

std::string playerName;//�������
    int money;

    int num;//��������
    int eggNum;
    int nowLife[CAPACITY];//������������
    int nowPP[CAPACITY];
    int level[CAPACITY];
    int aseed[CAPACITY];
    int kind[EGGCAPACITY];//����������

    int houseNum;//�ֿ�����
    int nowLife[CAPACITY];//�ֿ��������
    int nowPP[CAPACITY];
    int level[CAPACITY];
    int aseed[CAPACITY];
*/
    


// ���ڶ�ȡ��д����Ϸ���ݵĺ���
static void saveGameData( Player* player,petHouse* pethouse, const std::string& filename) {
    std::ofstream file(filename);               //���ļ�(ֻд)
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
        std::cout << "��Ϸ�����ѱ��档\n";
    }
    else {
        std::cerr << "�޷����ļ����б��档\n";
    }
}


static void readGameData(Player* player, petHouse* pethouse, const std::string& filename) {
    std::ifstream file(filename);                       //���ļ���ֻ��
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
        std::cerr << "�޷����ļ����ж�ȡ��\\n";
    }
}

#endif // !FILESTORE_H