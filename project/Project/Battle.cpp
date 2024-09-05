#include "Battle.h"
#include "ConstTable.h"
#include <iostream>
using namespace std;

Battle::Battle(Player& player) :player(player) {
	//随机生成怪物
	unsigned seed = static_cast<unsigned>(time(NULL));
	srand(seed);
	int aseed = rand() % MAXPETCOUNT;
	int theSeed = player.getPos() + aseed * 5;		//怪物种子
	wildPet = new Pet(theSeed);
	beginBattle();
}
Battle::~Battle()
{
	if (wildPet != NULL)
		delete wildPet;
	cout << "本次战斗结束！" << endl;
}

void Battle::choosePet() {
	int k = 0;
	for (int i = 0; i < player.getBag()->getNowSize(); i++) {
		if (player.getBag()->getPetByIndex(i)->getNowLife() > 0)k = 1;
	}
	if (k) {
		
		while (true) {
			system("cls");
			player.showBag();
			cout << "请选择你的宠物：";
			char a = getchar();
			int choose=a-48;
			if (choose > 0 && choose <= player.getBag()->getNowSize()) {
				yourPet = player.getBag()->getPetByIndex(choose - 1) ;
				if (yourPet->getNowLife()) {
					system("cls");
					break;
				}
					
				else {
					system("cls");
					player.showBag();
					cout<<"\n"<<choose << "." << player.getBag()->getPetByIndex(choose - 1)->getName() 
						<< "血量为0，请选择其他的选项：";
					
				}
					
			}
			else {
				cout << "请输入正确的选项！\n";
				while (true)if (getchar() == '\n')break;
				Sleep(1000);
				
			}
		}
	}
	else {
		cout << "宠物全部阵亡，您做个人吧！\n";
	}
	
}

void Battle::showAttrPanel()
{
	wildPet->showInfo();
	cout << endl;
	cout << "\n"<<player.getName()<<"的宠物:\n";
	yourPet->showInfo();
	cout << endl;
}
void Battle::Aremove(int j) {
	vector<Skill*> ASkill_;
	for (int i = 0; i < Acount; i++) {
		if (j == i)
			continue;
		ASkill_.push_back(ASkill[i]);
	}

	ASkill = ASkill_;
	Acount--;
}
void Battle::Bremove(int j) {
	vector<Skill*> BSkill_;
	for (int i = 0; i < Bcount; i++) {
		if (j == i)
			continue;
		BSkill_.push_back(BSkill[i]);
	}

	BSkill = BSkill_;
	Bcount--;
}
void Battle::playerChooseSkill() {
	system("cls");
	showAttrPanel();
	
	cout << "\n请选择技能：";
	//判断技能选择是否可行
	while (true) {
		char b = getchar();
		choice = b - 48;
		if (choice > 0 && choice <= yourPet->getSkillCount()) {
			int PPkey = yourPet->getNowPP() - yourPet->getSkill(choice - 1)->getPPconsume();
			if (PPkey < 0)
			{
				cout << "PP值不足！请重新选择！(按任意键返回)\n";
				getchar();
				system("cls");
				showAttrPanel();
				playerChooseSkill();
			}
			else {
				yourPet->setNowPP(PPkey);
				ASkill.push_back(yourPet->getSkill(choice - 1));
				cout << "你的宠物‘" << yourPet->getName() << "’使用了技能‘"
					<< yourPet->getSkill(choice - 1)->getName() << "’！\n" << endl;
				Acount++;
				Sleep(1000);
				break;
			}
		}
		else {
			while (true)if (getchar() == '\n')break;
			system("cls");
			showAttrPanel();
			cout << "\n请输入正确的选项！\n";
			cout << "请选择技能：";
		}
	}
}

void Battle::beginBattle()
{
	choosePet();
	int nowAttacker = 1;
	int PLAYER = 1; 
	showAttrPanel();
	cout << wildPet->getName() << ":我要开始攻击了！" << endl;
	cout << yourPet->getName() << ":come on!\n\n" <<"按回车键继续...";
	getchar();
	while (true)if (getchar() == '\n')break;
	system("cls");
	while (!judegeEnd()) {
		if (nowAttacker == PLAYER) {
			choice = -1;
			playerChooseSkill();
			
			//清算敌人上回合使用技能
			for (int j = 0; j < Bcount; j++)
				{	//总伤害=种族值*
					//（追踪真伤+追踪真伤百分比+miss*（真伤+真伤百分比+（1-防御）*攻击））
					int allhurt=(BSkill[j]->getUnavoidableHurt() 
						+ BSkill[j]->getUnavoidableHurtPercent() 
						* yourPet->getLife()
						+ (1-yourPet->getSkill(choice - 1)->getMissKey()) 
						*(BSkill[j]->getAvoidableHurt() 
						+ BSkill[j]->getAvoidableHurtPercent()
						* yourPet->getLife()
						+(1- yourPet->getProtectPower()*0.001)
						*wildPet->getPower()))
						* wildPet->ElementFight(yourPet);
					cout << "技能‘" << BSkill[j]->getName()<<"’对‘"<< yourPet-> getName()<< "’造成 " << allhurt << " 点伤害！\n";
					Sleep(1000);
					
					if (allhurt >= yourPet->getNowLife()) {
						yourPet->setNowLife(0);
						cout << "按任意键继续...\n";
						while (true)if (getchar() == '\n')break;
						system("cls");

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
					for (int j = 0; j < Acount; j++) {
						if (ASkill[j]->getHPaddKey()) {
							int allHPadd = ASkill[j]->getHPadd() + ASkill[j]->getHPaddPercent() * yourPet->getLife();
							if (yourPet->getNowLife() + allHPadd > yourPet->getLife()) {
								cout << "HP已满！";
								allHPadd = yourPet->getLife() - yourPet->getNowLife();
								yourPet->setNowLife(yourPet->getLife());
							}
							else {
								yourPet->setNowLife(yourPet->getNowLife() + allHPadd);
							}
							cout << "‘" << ASkill[j]->getName()<<"’技能为‘"<< yourPet->getName() << "’加了 "<< allHPadd << " HP！\n";
							if (ASkill[j]->getLifeKey())
								if (yourPet->getNowLife() <= 0) {
									yourPet->setNowLife(1);
									cout << "由于‘" << ASkill[j]->getName() << "’的保命功能，现在‘" << yourPet->getName() << "’还有1滴血\n";
								}
							if (yourPet->getNowLife() <= 0)break;
						}
						if (ASkill[j]->getPowerBuffKey()) {
							int allPoweradd = yourPet->getPower() * ASkill[j]->getPowerBuff();
							yourPet->setPower(yourPet->getPower() + allPoweradd);
							cout<<"‘" << ASkill[j]->getName() << "’技能为‘" << yourPet->getName() << "’加了 " << allPoweradd << " 点攻击力\n";
						}
						if (ASkill[j]->getProtectPowerBuffKey()) {
							int allProtectPoweradd = yourPet->getProtectPower() * ASkill[j]->getProtectPowerBuff();
							yourPet->setProtectPower(yourPet->getProtectPower() + allProtectPoweradd);
							cout << "‘" << ASkill[j]->getName() << "’技能为‘" << yourPet->getName() << "’加了 " << allProtectPoweradd << " 点防御力\n";
						}
						
						
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
						cout <<"\n"<< wildPet->getName() << "使用了技能‘"
							<< wildPet->getSkill(choice - 1)->getName() << "'！\n\n";
						Sleep(1000);
						wildPet->setNowPP(PPkey);
						BSkill.push_back(wildPet->getSkill(choice-1));
						Bcount++;
						break;
					}
				}
				else {
					cout << "请输入正确的选项！(按任意键返回)\n";
					getchar();
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
					+(1- wildPet->getSkill(choose - 1)->getMissKey())
					* (ASkill[j]->getAvoidableHurt()
						+ ASkill[j]->getAvoidableHurtPercent()
						* wildPet->getLife()
						+ (1 - wildPet->getProtectPower() * 0.001)
						* yourPet->getPower()))
					* yourPet->ElementFight(wildPet);
				cout << "技能‘" << ASkill[j]->getName() << "’"<<"对‘" << wildPet->getName() << "’造成 " << allhurt << " 点伤害！\n";
				Sleep(1000);
				
				
				if (allhurt >= wildPet->getNowLife()) {
					cout << "按任意键继续...\n";
					getchar();
					getchar();
					system("cls");
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
				BSkill.push_back(wildPet->getSkill(choose - 1));
				for (int j = 0; j < Bcount; j++) {
					if (BSkill[j]->getHPaddKey()) {
						int allHPadd = BSkill[j]->getHPadd() + BSkill[j]->getHPaddPercent() * wildPet->getLife();
						if (wildPet->getNowLife() + allHPadd > wildPet->getLife()) {
							
							allHPadd = wildPet->getLife() - wildPet->getNowLife();
							wildPet->setNowLife(wildPet->getLife());
							cout << "HP已满！";
						}
						else {
							wildPet->setNowLife(wildPet->getNowLife() + allHPadd);
						}
						cout << "技能‘" << BSkill[j]->getName() << "为‘" << wildPet->getName() << "’加了 " << allHPadd << " HP\n";
						if (BSkill[j]->getLifeKey())
							if (wildPet->getNowLife() <= 0) {
								wildPet->setNowLife(1);
								cout << "由于‘" << BSkill[j]->getName() << "’的保命功能，现在‘" << wildPet->getName() << "’还有1滴血\n";
							}
						if (wildPet->getNowLife() <= 0)break;
					}
					if (BSkill[j]->getPowerBuffKey()) {
						int allPoweradd = wildPet->getPower() * BSkill[j]->getPowerBuff();
						wildPet->setPower(wildPet->getPower() + allPoweradd);
						cout<<"技能‘" << BSkill[j]->getName() << "’为‘" << wildPet->getName() << "’加了 " << allPoweradd << " 点攻击力\n";
					}
					if (BSkill[j]->getProtectPowerBuffKey()) {
						int allProtectPoweradd = wildPet->getProtectPower() * BSkill[j]->getProtectPowerBuff();
						wildPet->setPower(wildPet->getPower() + allProtectPoweradd);
						cout << "技能‘" << BSkill[j]->getName() << "’为‘" << wildPet->getName() << "’加了 " << allProtectPoweradd << " 点防御力\n";
					}

				}
				if (wildPet->getNowLife() <= 0)break;
				cout << "按任意键继续...";
				getchar();
				getchar();
			}
			//Sleep(1000);
			else break;
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
	if (yourPet->getNowLife() <= 0) {
		yourPet->setNowLife(0);
return -1;
	}
		
	if (wildPet->getNowLife() <= 0) {
		wildPet->setNowLife(0);
		return 1;
	}
		
	return 0;
}

void Battle::showResult()
{
	if (judegeEnd() == 1) {
		
		yourPet->setLevel(yourPet->getLevel() + 1);
		player.setMoney(player.getMoney() + wildPet->getMoney());
		cout << "恭喜你获得胜利!" << endl;
		cout << "获得 " << wildPet->getMoney() << "金钱\t‘"
			<< yourPet->getName() << "’的等级+1\n\n";
		cout << "是否抓捕宠物"<< wildPet->getName()<<"？（是--Y   否--其他键）\n" ;
		char a=getchar();
		if (a == 'y' || a=='Y') {
			while (true)if (getchar() == '\n')break;
			//如果背包中宠物没满，蛋也还有的话
			if (player.getBag()->getNowEggSize() && player.getBag()->getCapacity() > player.getBag()->getNowSize())
			{
				while (true) {
					system("cls");
					showAttrPanel();
					player.getBag()->EggshowInfo();
					cout << "按0取消捕捉\n";
					cout << "您想选哪一款捕捉蛋？请输入：";
					char ch = getchar();
					choice=ch-48;
					if (choice ==0) {
						cout << "取消捕捉成功！\n";
						break;
					}
					else if (choice < 0||choice>player.getBag()->getEggCapacity()) {
						cout << "请输入正确的选项！\n";
						while (true)if (getchar() == '\n')break;
						Sleep(1000);
					}
					else {
						int eggkind = player.getBag()->getEggByIndex(choice - 1)->getKind();
						if (player.removeEgg(choice - 1)) {
							if (catchPet(eggkind)) {
								//复制一个宠物，因为在退出战斗系统的时候MONSTER被析构，PET指针消失
								Pet* NewPet = new Pet(*wildPet);
								player.pushBag(NewPet);
								cout << "宠物" << wildPet->getName() << "已捕捉!\n";
								break;
							}
							else {
								cout << "宠物" << wildPet->getName() << "捕捉失败!\n";
								break;
							}

						}

					}
					
					

				}
			}
			else cout << "您背包中宠物已满/蛋不够，不能捕捉！\n";
		}
	}
	else {
		cout << "宠物血量已耗尽！是否继续战斗？（是--Y   否--其他键）" << endl
			<<"请输入选择：";
		char a = getchar();
		if (a == 'y' || a == 'Y') {
			while (true)if (getchar() == '\n')break;
			beginBattle();
		}

		else cout << "本次战斗失败！" << endl;
		
	}
}


