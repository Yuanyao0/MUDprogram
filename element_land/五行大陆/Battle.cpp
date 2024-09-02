#include "Battle.h"
#include "ConstTable.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "ConstTable.h"
using namespace std;

Battle::Battle(Player& player) :player(player) {
	//随机生成怪物
	unsigned seed = static_cast<unsigned>(time(NULL));
	srand(seed);
	int theSeed = player.getPos() + (rand() % MAXPETCOUNT) * 5;		//怪物种子
	wildPet = new Pet(theSeed);
}
Battle::~Battle()
{
	if (wildPet != NULL)
		delete wildPet;
}

void Battle::choosePet() {
	cout << "请选择你的宠物：";
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
			cout << "请输入正确的选项：";
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
	cout << "\n你的宠物:\n";
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
	cout << "\n请选择技能：";
}

void Battle::beginBattle()
{
	choosePet();
	int nowAttacker = 1;
	int PLAYER = 1; 
	showAttrPanel();
	cout << wildPet->getName() << ":我要开始攻击了！" << endl;
	cout << yourPet->getName() << ":come on!\n" <<"按任意键继续...";
	getchar();
	while (!judegeEnd()) {
		if (nowAttacker == PLAYER) {
			playerChooseSkill();
			int choice = 0;
			cin >> choice;
			//判断技能选择是否可行
			while (true) {
				if (choice > 0 && choice <= yourPet->getSkillCount()) {
					int PPkey= yourPet->getNowPP()-yourPet->getSkill(choice-1)->getPPconsume() ;
					if (PPkey<0)
					{
						cout << "PP值不足！请重新选择！(按任意键返回)\n";
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
					cout << "请输入正确的选项！(按任意键返回)\n";
					getchar();
					system("cls");
					showAttrPanel();
					playerChooseSkill();
				}
			}
			//清算敌人上回合使用技能
			for (int j = 0; j < Bcount; j++)
				{	//总伤害=种族值*
					//（追踪真伤+追踪真伤百分比+miss*（真伤+真伤百分比+（1-防御）*攻击））
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
					cout << "技能" << BSkill[j]->getName() << "造成" << allhurt << "点伤害！\n";
					if (allhurt >= yourPet->getNowLife()) {
						yourPet->setNowLife(0);
						break;
					}
					else yourPet->setNowLife(yourPet->getNowLife()- allhurt);
					BSkill[j]->setRound(BSkill[j]->getRound()-1);
					
				}
			cout << endl;
			if (yourPet->getNowLife() > 0) {
					//整理B技能区
					for (int j = Bcount - 1; j >= 0; j--)if (BSkill[j]->getRound() == 0)Bremove(j);
					//A没被打死，A的增益可以起作用了
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
							cout<< ASkill[j]->getName()<<"技能为"<< yourPet->getName() << "加了"<< allHPadd << "HP\n";
							if (ASkill[j]->getLifeKey())
								if (yourPet->getNowLife() <= 0) {
									yourPet->setNowLife(1);
									cout << "由于" << ASkill[j]->getName() << "的保命功能，现在" << yourPet->getName() << "还有1滴血\n";
								}
							if (yourPet->getNowLife() <= 0)break;
						}
						if (ASkill[j]->getPowerBuffKey()) {
							int allPoweradd = yourPet->getPower() * ASkill[j]->getPowerBuff();
							yourPet->setPower(yourPet->getPower() + allPoweradd);
							cout << ASkill[j]->getName() << "技能为" << yourPet->getName() << "加了" << allPoweradd << "攻击力\n";
						}
						if (ASkill[j]->getProtectPowerBuffKey()) {
							int allProtectPoweradd = yourPet->getProtectPower() * ASkill[j]->getProtectPowerBuff();
							yourPet->setPower(yourPet->getPower() + allProtectPoweradd);
							cout << ASkill[j]->getName() << "技能为" << yourPet->getName() << "加了" << allProtectPoweradd << "防御力\n";
						}
						ASkill[j]->setRound(ASkill[j]->getRound()-1);
						
					}
				}
			//Sleep(1000);
		}
		else {
			//判断技能选择是否可行
			int choose=-1;
			while (true) {
				unsigned seed = static_cast<unsigned>(time(NULL));
				//初始化随机种子
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
					cout << "请输入正确的选项！(按任意键返回)\n";
					getchar();
					system("cls");
					showAttrPanel();
					playerChooseSkill();
				}
			}
			//清算敌人上回合使用技能
			for (int j = 0; j < Acount; j++)
			{	//总伤害=种族值*
				//（追踪真伤+追踪真伤百分比+miss*（真伤+真伤百分比+（1-防御）*攻击））
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
				cout << "技能" << ASkill[j]->getName() << "造成" << allhurt << "点伤害！\n";
				if (allhurt >= wildPet->getNowLife()) {
					wildPet->setNowLife(0);
					break;
				}
				else wildPet->setNowLife(wildPet->getNowLife() - allhurt);
				ASkill[j]->setRound(ASkill[j]->getRound() - 1);

			}
			cout << endl;
			if (wildPet->getNowLife() > 0) {
				//整理A技能区
				for (int j = Acount - 1; j >= 0; j--)if (ASkill[j]->getRound() == 0)Aremove(j);
				//B没被打死，B的增益可以起作用了
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
						cout << BSkill[j]->getName() << "技能为" << wildPet->getName() << "加了" << allHPadd << "HP\n";
						if (BSkill[j]->getLifeKey())
							if (wildPet->getNowLife() <= 0) {
								wildPet->setNowLife(1);
								cout << "由于" << BSkill[j]->getName() << "的保命功能，现在" << wildPet->getName() << "还有1滴血\n";
							}
						if (wildPet->getNowLife() <= 0)break;
					}
					if (BSkill[j]->getPowerBuffKey()) {
						int allPoweradd = wildPet->getPower() * BSkill[j]->getPowerBuff();
						wildPet->setPower(wildPet->getPower() + allPoweradd);
						cout << BSkill[j]->getName() << "技能为" << wildPet->getName() << "加了" << allPoweradd << "攻击力\n";
					}
					if (BSkill[j]->getProtectPowerBuffKey()) {
						int allProtectPoweradd = wildPet->getProtectPower() * BSkill[j]->getProtectPowerBuff();
						wildPet->setPower(wildPet->getPower() + allProtectPoweradd);
						cout << BSkill[j]->getName() << "技能为" << wildPet->getName() << "加了" << allProtectPoweradd << "防御力\n";
					}
					BSkill[j]->setRound(BSkill[j]->getRound() - 1);

				}
			}
			//Sleep(1000);

		}
		//转换攻击者
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
		cout << "本次战斗结束！" << endl;
		yourPet->setLevel(yourPet->getLevel() + 1);
		player.setMoney(player.getMoney() + wildPet->getMoney());
		cout << "恭喜你获得胜利!" << endl;
		cout << "获得" << wildPet->getMoney() << "\t金钱\n"
			<< yourPet->getName() << "\t等级+1";
		cout << "是否抓捕宠物？（y/n)" << endl;
		string choice;
		cin >> choice;
		if (choice == "y"|| choice == "Y") {
			//如果背包中宠物没满，蛋也还有的话
			if (player.getBag()->getNowEggSize() && player.getBag()->getCapacity() > player.getBag()->getNowSize())
			{
				while (true) {
					system("cls");
					showAttrPanel();
					player.getBag()->EggshowInfo();
					cout << "按0取消捕捉\n";
					cout << "您想选哪一款捕捉蛋？请输入：";
					int choice=-1;
					cin >> choice;
					if (player.removeEgg(choice - 1)) {
					//复制一个宠物，因为在退出战斗系统的时候MONSTER被析构，物品指针消失
						Pet* NewPet = new Pet(*wildPet);
						player.pushBag(NewPet);
						cout <<"宠物"<< wildPet->getName()<<"已捕捉!\n";
						break;
					}
					else {
						if (choice == 0)break;
						cout << "请输入正确的选项!";
						Sleep(1000);
					}

				}
			}
			else cout << "您背包中宠物已满/蛋不够，不能捕捉！\n";
		}
		//回到打怪之前上一幅图，并且上一幅图怪物消失
	}
	else {
		cout << "宠物血量已耗尽！是否继续战斗？（y/n）" << endl
			<<"请输入选择：";
		string choice;
		cin >> choice;
		if (choice == "y" || choice == "Y")beginBattle();
		else cout << "本次战斗失败！" << endl;
		
	}
}


