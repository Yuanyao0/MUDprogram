#include "Battle.h"
#include "ConstTable.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "ConstTable.h"
using namespace std;

Battle::Battle(Player& player) :player(player) {
	//������ɹ���
	unsigned seed = static_cast<unsigned>(time(NULL));
	srand(seed);
	int theSeed = player.getPos() + (rand() % MAXPETCOUNT) * 5;		//��������
	wildPet = new Pet(theSeed);
}
Battle::~Battle()
{
	if (wildPet != NULL)
		delete wildPet;
}

void Battle::choosePet() {
	cout << "��ѡ����ĳ��";
	player.showBag();
	int choose = -1;
	cin >> choose;
	while (true) {
		if (choose > 0 && choose <= player.getBag()->getCapacity()) {
			yourPet = player.getBag()->getPetByIndex(choose - 1);
			break;
		}
		else {
			system("cls");
			player.showBag();
			cout << "��������ȷ��ѡ�";
		}
	}
	
}

void Battle::savePetInfo() {
	initPOWER = yourPet->getPower();
	initPROTECT = yourPet->getProtectPower();
}

void Battle::showAttrPanel()
{
	wildPet->showInfo();
	cout << endl;
	cout << "\n��ĳ���:\n";
	yourPet->showInfo();
	cout << endl;
}
void Battle::Aremove(int j) {
	vector<Skill*> ASkill_;
	unsigned i;
	for (unsigned i = 0; i < Acount; i++) {
		if (j == i)
			continue;
		ASkill_.push_back(ASkill[i]);
	}

	ASkill = ASkill_;
	Acount--;
}
void Battle::Bremove(int j) {
	vector<Skill*> BSkill_;
	unsigned i;
	for (unsigned i = 0; i < Bcount; i++) {
		if (j == i)
			continue;
		BSkill_.push_back(BSkill[i]);
	}

	BSkill = BSkill_;
	Bcount--;
}
void Battle::playerChooseSkill() {
	for (int i = 0; i < yourPet->getSkillCount(); i++) {
		cout << i + 1 << "." << yourPet->getSkill(i)->getName() << "\t";
	}
	cout << "\n��ѡ���ܣ�";
}

void Battle::beginBattle()
{
	choosePet();
	int nowAttacker = 1;
	int PLAYER = 1; 
	showAttrPanel();
	cout << wildPet->getName() << ":��Ҫ��ʼ�����ˣ�" << endl;
	cout << yourPet->getName() << ":come on!\n" <<"�����������...";
	getchar();
	while (!judegeEnd()) {
		if (nowAttacker == PLAYER) {
			playerChooseSkill();
			int choice = 0;
			cin >> choice;
			//�жϼ���ѡ���Ƿ����
			while (true) {
				if (choice > 0 && choice <= yourPet->getSkillCount()) {
					int PPkey= yourPet->getNowPP()-yourPet->getSkill(choice-1)->getPPconsume() ;
					if (PPkey<0)
					{
						cout << "PPֵ���㣡������ѡ��(�����������)\n";
						getchar();
						system("cls");
						showAttrPanel();
						playerChooseSkill();
					}
					else {
						yourPet->setNowPP(PPkey);
						ASkill.push_back(yourPet->getSkill(choice-1));
						Acount++;
						break;
					}
				}
				else {
					cout << "��������ȷ��ѡ�(�����������)\n";
					getchar();
					system("cls");
					showAttrPanel();
					playerChooseSkill();
				}
			}
			//��������ϻغ�ʹ�ü���
			for (int j = 0; j < Bcount; j++)
				{	//���˺�=����ֵ*
					//��׷������+׷�����˰ٷֱ�+miss*������+���˰ٷֱ�+��1-������*��������
					int allhurt=(BSkill[j]->getUnavoidableHurt() 
						+ BSkill[j]->getUnavoidableHurtPercent() 
						* yourPet->getLife()
						+ yourPet->getSkill(choice - 1)->getMissKey() 
						*(BSkill[j]->getAvoidableHurt() 
						+ BSkill[j]->getAvoidableHurtPercent()
						* yourPet->getLife()
						+(1- yourPet->getProtectPower()*0.001)
						*wildPet->getPower()))
						* wildPet->ElementFight(yourPet);
					cout << "����" << BSkill[j]->getName() << "���" << allhurt << "���˺���\n";
					if (allhurt >= yourPet->getNowLife()) {
						yourPet->setNowLife(0);
						break;
					}
					else yourPet->setNowLife(yourPet->getNowLife()- allhurt);
					BSkill[j]->setRound(BSkill[j]->getRound()-1);
					
				}
			cout << endl;
			if (yourPet->getNowLife() > 0) {
					//����B������
					for (int j = Bcount - 1; j >= 0; j--)if (BSkill[j]->getRound() == 0)Bremove(j);
					//Aû��������A�����������������
					Acount++;
					ASkill.push_back(yourPet->getSkill(choice - 1));
					for (int j = 0; j < Acount; j++) {
						if (ASkill[j]->getHPaddKey()) {
							int allHPadd = ASkill[j]->getHPadd() + ASkill[j]->getHPaddPercent() * yourPet->getLife();
							if (yourPet->getNowLife() + allHPadd > yourPet->getLife()) {
								yourPet->setNowLife(yourPet->getLife());
								allHPadd = yourPet->getLife() - yourPet->getNowLife();
							}
							else {
								yourPet->setNowLife(yourPet->getNowLife() + allHPadd);
							}
							cout<< ASkill[j]->getName()<<"����Ϊ"<< yourPet->getName() << "����"<< allHPadd << "HP\n";
							if (ASkill[j]->getLifeKey())
								if (yourPet->getNowLife() <= 0) {
									yourPet->setNowLife(1);
									cout << "����" << ASkill[j]->getName() << "�ı������ܣ�����" << yourPet->getName() << "����1��Ѫ\n";
								}
							if (yourPet->getNowLife() <= 0)break;
						}
						if (ASkill[j]->getPowerBuffKey()) {
							int allPoweradd = yourPet->getPower() * ASkill[j]->getPowerBuff();
							yourPet->setPower(yourPet->getPower() + allPoweradd);
							cout << ASkill[j]->getName() << "����Ϊ" << yourPet->getName() << "����" << allPoweradd << "������\n";
						}
						if (ASkill[j]->getProtectPowerBuffKey()) {
							int allProtectPoweradd = yourPet->getProtectPower() * ASkill[j]->getProtectPowerBuff();
							yourPet->setPower(yourPet->getPower() + allProtectPoweradd);
							cout << ASkill[j]->getName() << "����Ϊ" << yourPet->getName() << "����" << allProtectPoweradd << "������\n";
						}
						ASkill[j]->setRound(ASkill[j]->getRound()-1);
						
					}
				}
			//Sleep(1000);
		}
		else {
			//�жϼ���ѡ���Ƿ����
			int choose=-1;
			while (true) {
				unsigned seed = static_cast<unsigned>(time(NULL));
				//��ʼ���������
				srand(seed);
				int choice =  rand() % wildPet->getSkillCount()+1;

				if (choice > 0 && choice <= wildPet->getSkillCount()) {
					int PPkey = wildPet->getNowPP() - wildPet->getSkill(choice-1)->getPPconsume();
					if (PPkey < 0){}
					else {
						choose = choice;
						wildPet->setNowPP(PPkey);
						BSkill.push_back(wildPet->getSkill(choice-1));
						Bcount++;
						break;
					}
				}
				else {
					cout << "��������ȷ��ѡ�(�����������)\n";
					getchar();
					system("cls");
					showAttrPanel();
					playerChooseSkill();
				}
			}
			//��������ϻغ�ʹ�ü���
			for (int j = 0; j < Acount; j++)
			{	//���˺�=����ֵ*
				//��׷������+׷�����˰ٷֱ�+miss*������+���˰ٷֱ�+��1-������*��������
				int allhurt = (ASkill[j]->getUnavoidableHurt()
					+ ASkill[j]->getUnavoidableHurtPercent()
					* wildPet->getLife()
					+ wildPet->getSkill(choose - 1)->getMissKey()
					* (ASkill[j]->getAvoidableHurt()
						+ ASkill[j]->getAvoidableHurtPercent()
						* wildPet->getLife()
						+ (1 - wildPet->getProtectPower() * 0.001)
						* yourPet->getPower()))
					* yourPet->ElementFight(wildPet);
				cout << "����" << ASkill[j]->getName() << "���" << allhurt << "���˺���\n";
				if (allhurt >= wildPet->getNowLife()) {
					wildPet->setNowLife(0);
					break;
				}
				else wildPet->setNowLife(wildPet->getNowLife() - allhurt);
				ASkill[j]->setRound(ASkill[j]->getRound() - 1);

			}
			cout << endl;
			if (wildPet->getNowLife() > 0) {
				//����A������
				for (int j = Acount - 1; j >= 0; j--)if (ASkill[j]->getRound() == 0)Aremove(j);
				//Bû��������B�����������������
				Bcount++;
				BSkill.push_back(wildPet->getSkill(choose - 1));
				for (int j = 0; j < Bcount; j++) {
					if (BSkill[j]->getHPaddKey()) {
						int allHPadd = BSkill[j]->getHPadd() + BSkill[j]->getHPaddPercent() * wildPet->getLife();
						if (wildPet->getNowLife() + allHPadd > wildPet->getLife()) {
							wildPet->setNowLife(wildPet->getLife());
							allHPadd = wildPet->getLife() - wildPet->getNowLife();
						}
						else {
							wildPet->setNowLife(wildPet->getNowLife() + allHPadd);
						}
						cout << BSkill[j]->getName() << "����Ϊ" << wildPet->getName() << "����" << allHPadd << "HP\n";
						if (BSkill[j]->getLifeKey())
							if (wildPet->getNowLife() <= 0) {
								wildPet->setNowLife(1);
								cout << "����" << BSkill[j]->getName() << "�ı������ܣ�����" << wildPet->getName() << "����1��Ѫ\n";
							}
						if (wildPet->getNowLife() <= 0)break;
					}
					if (BSkill[j]->getPowerBuffKey()) {
						int allPoweradd = wildPet->getPower() * BSkill[j]->getPowerBuff();
						wildPet->setPower(wildPet->getPower() + allPoweradd);
						cout << BSkill[j]->getName() << "����Ϊ" << wildPet->getName() << "����" << allPoweradd << "������\n";
					}
					if (BSkill[j]->getProtectPowerBuffKey()) {
						int allProtectPoweradd = wildPet->getProtectPower() * BSkill[j]->getProtectPowerBuff();
						wildPet->setPower(wildPet->getPower() + allProtectPoweradd);
						cout << BSkill[j]->getName() << "����Ϊ" << wildPet->getName() << "����" << allProtectPoweradd << "������\n";
					}
					BSkill[j]->setRound(BSkill[j]->getRound() - 1);

				}
			}
			//Sleep(1000);

		}
		//ת��������
		nowAttacker = -nowAttacker;
	}
	yourPet->setPower(initPOWER);
	yourPet->setProtectPower( initPROTECT );
	showAttrPanel();
	showResult();
}

int Battle::judegeEnd()
{
	if (yourPet->getLife() <= 0)
		return -1;
	if (wildPet->getLife() <= 0)
		return 1;
	return 0;
}

void Battle::showResult()
{
	if (judegeEnd() == 1) {
		cout << "����ս��������" << endl;
		yourPet->setLevel(yourPet->getLevel() + 1);
		player.setMoney(player.getMoney() + wildPet->getMoney());
		cout << "��ϲ����ʤ��!" << endl;
		cout << "���" << wildPet->getMoney() << "\t��Ǯ\n"
			<< yourPet->getName() << "\t�ȼ�+1";
		cout << "�Ƿ�ץ�������y/n)" << endl;
		string choice;
		cin >> choice;
		if (choice == "y"|| choice == "Y") {
			//��������г���û������Ҳ���еĻ�
			if (player.getBag()->getNowEggSize() && player.getBag()->getCapacity() > player.getBag()->getNowSize())
			{
				while (true) {
					system("cls");
					showAttrPanel();
					player.getBag()->EggshowInfo();
					cout << "��0ȡ����׽\n";
					cout << "����ѡ��һ�׽���������룺";
					int choice=-1;
					cin >> choice;
					if (player.removeEgg(choice - 1)) {
					//����һ�������Ϊ���˳�ս��ϵͳ��ʱ��MONSTER����������Ʒָ����ʧ
						Pet* NewPet = new Pet(*wildPet);
						player.pushBag(NewPet);
						cout <<"����"<< wildPet->getName()<<"�Ѳ�׽!\n";
						break;
					}
					else {
						if (choice == 0)break;
						cout << "��������ȷ��ѡ��!";
						Sleep(1000);
					}

				}
			}
			else cout << "�������г�������/�����������ܲ�׽��\n";
		}
		//�ص����֮ǰ��һ��ͼ��������һ��ͼ������ʧ
	}
	else {
		cout << "����Ѫ���Ѻľ����Ƿ����ս������y/n��" << endl
			<<"������ѡ��";
		string choice;
		cin >> choice;
		if (choice == "y" || choice == "Y")beginBattle();
		else cout << "����ս��ʧ�ܣ�" << endl;
		
	}
}


