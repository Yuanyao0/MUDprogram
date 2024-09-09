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
}

bool Battle::choosePet() {
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
				initPOWER= player.getBag()->getPetByIndex(choose - 1)->getPower();
				initPROTECT = player.getBag()->getPetByIndex(choose - 1)->getProtectPower();
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
		return true;
	}
	else {
		cout << "宠物全部阵亡，您做个人吧！\n";
		return false;
	}
	
}

void Battle::showAttrPanel()
{
	ColorContainer* c = new ColorSys();
	ostringstream oss;
	wildPet->showInfo();
	cout << endl;
	oss << "\n"<<player.getName()<<"的宠物:\n";
	c->changeTextColor('Y', oss);
	yourPet->showInfo();
	cout << endl;
}
void Battle::Aremove(int j) {
	vector<Skill*> ASkill_;
	for (int i = 0; i < ASkill.size(); i++) {
		if (j == i) {
			ASkill[i]->setRound(SKILLround[ASkill[i]->getaseed()]);
			continue;
		}
			
		ASkill_.push_back(ASkill[i]);
	}

	ASkill = ASkill_;
}
void Battle::Bremove(int j) {
	vector<Skill*> BSkill_;
	for (int i = 0; i < BSkill.size(); i++) {
		if (j == i) {
			BSkill[i]->setRound(SKILLround[BSkill[i]->getaseed()]);
			continue;
		}
		BSkill_.push_back(BSkill[i]);
	}

	BSkill = BSkill_;
}
void Battle::playerChooseSkill() {
	system("cls");
	showAttrPanel();
	if (BSkill.size() == 0){}
	else{
		cout << "\n‘" << wildPet->getName() << "’的技能：";
		for (int i = 0; i < BSkill.size(); i++) {
			if(BSkill[i]->getRound())
			cout << BSkill[i]->getName() << "\t";
		}
		cout << endl;
		cout << "即将发挥作用，想想如何应对...\n";
	}
	cout << "\n请选择技能(按0查看技能图鉴)：";
	//判断技能选择是否可行
	while (true) {

		char b = getchar();
		choice = b - 48;
		if (choice == 0) {
			Pet::showSkillInfo(wildPet->getaseed());
			Pet::showSkillInfo(yourPet->getaseed());
			cout << "按任意键退出图鉴...\n";
			getchar();
			while(1)if(getchar()=='\n')break;
			system("cls");
			showAttrPanel();
			if (BSkill.size() == 0) {}
			else {
				cout << "\n‘" << wildPet->getName() << "’的技能：";
				for (int i = 0; i < BSkill.size(); i++) {
					cout << BSkill[i]->getName() << "\t";
				}
				cout << endl;
				cout << "即将发挥作用，想想如何应对...\n";
			}
			cout << "\n请选择技能(按0查看技能图鉴)：";
		}
		else if (choice > 0 && choice <= yourPet->getSkillCount()) {
			int PPkey = yourPet->getNowPP() - yourPet->getSkill(choice - 1)->getPPconsume();
			if (PPkey < 0)
			{
				cout << "PP值不足！请重新选择！(按任意键返回)\n";
				Sleep(1000);
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
				Sleep(1000);
				break;
			}
		}
		else {
			while (true)if (getchar() == '\n')break;
			system("cls");
			showAttrPanel();
			cout << "\n请输入正确的选项！\n\n";
			Sleep(1000);
			if (BSkill.size() == 0) {}
			else {
				cout << "\n‘" << wildPet->getName() << "’的技能：";
				for (int i = 0; i < BSkill.size(); i++) {
					cout << BSkill[i]->getName() << "\t";
				}
				cout << endl;
				cout << "即将发挥作用，想想如何应对...\n";
			}
			cout << "\n请选择技能(按0查看技能图鉴)：";
		}
	}
}

void Battle::beginBattle()
{
	if (player.getBag()->getNowSize()) {
		if(!choosePet())return;
	}
		
	else {
		cout << "背包无宠物！\n";
		Sleep(1000);
		return;
	}
	int nowAttacker = 1;
	int PLAYER = 1; 
	showAttrPanel();
	Sleep(1000);
	cout << wildPet->getName() << ":我要开始攻击了！" << endl;
	Sleep(500); 
	cout << yourPet->getName() << ":come on!\n\n";
	Sleep(500);
	cout  <<"按回车键继续...";
	getchar();
	while (true)if (getchar() == '\n')break;
	system("cls");
	while (!judegeEnd()) {
		if (nowAttacker == PLAYER) {
			choice = -1;
			playerChooseSkill();
			
			//清算敌人上回合使用技能
			for (int j = 0; j < BSkill.size(); j++)
				{
				if (BSkill[j]->getRound() <= 0)continue;;
				//总伤害=种族值*
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
					for (int i = 0; i < BSkill.size(); i++)if (BSkill[j]->getRound() == 0)Bremove(j);
				}
			cout << endl;
			if (yourPet->getNowLife() > 0) {
					//A没被打死，A的增益可以起作用了
					for (int j = 0; j < ASkill.size(); j++) {
						if (ASkill[j]->getRound() <= 0)continue;
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
							if (yourPet->getNowLife() <= 0) {
								cout << "‘" << yourPet->getName() << "’使用‘" << ASkill[j]->getName() << "’导致自己阵亡！\n";
								Sleep(1000);
								system("cls");
								break;
							}
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
						break;
					}
				}
				else {
					cout << "敌方随机技能报错！(按任意键返回)\n";
					Sleep(1000);
					while (true)if (getchar() == '\n')break;
					system("cls");
					showAttrPanel();
					playerChooseSkill();
				}
			}
			//清算敌人上回合使用技能
			for (int j = 0; j < ASkill.size(); j++)
			{	
				if (ASkill[j]->getRound() <= 0)continue;
				//总伤害=种族值*
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
					Sleep(1000);
					getchar();
					while (true)if (getchar() == '\n')break;
					system("cls");
					wildPet->setNowLife(0);
					
					break;
				}
				else wildPet->setNowLife(wildPet->getNowLife() - allhurt);
				ASkill[j]->setRound(ASkill[j]->getRound() - 1);
				for (int i = 0; i < ASkill.size(); i++)if (ASkill[j]->getRound() == 0)Aremove(j);
			}
			cout << endl;
			if (wildPet->getNowLife() > 0) {
				//B没被打死，B的增益可以起作用了
				for (int j = 0; j < BSkill.size(); j++) {
					if (BSkill[j]->getRound() <= 0)continue;
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
						Sleep(1000);
						if (BSkill[j]->getLifeKey())
							if (wildPet->getNowLife() <= 0) {
								wildPet->setNowLife(1);
								cout << "由于‘" << BSkill[j]->getName() << "’的保命功能，现在‘" << wildPet->getName() << "’还有1滴血\n";
								Sleep(1000);
							}
						if (wildPet->getNowLife() <= 0) {
							cout << "‘" << wildPet->getName() << "’使用‘" << BSkill[j]->getName() << "’导致自己阵亡！\n";
							Sleep(1000);
							system("cls");
							break;
						}
					}
					if (BSkill[j]->getPowerBuffKey()) {
						int allPoweradd = wildPet->getPower() * BSkill[j]->getPowerBuff();
						wildPet->setPower(wildPet->getPower() + allPoweradd);
						cout<<"技能‘" << BSkill[j]->getName() << "’为‘" << wildPet->getName() << "’加了 " << allPoweradd << " 点攻击力\n";
						Sleep(1000);
					}
					if (BSkill[j]->getProtectPowerBuffKey()) {
						int allProtectPoweradd = wildPet->getProtectPower() * BSkill[j]->getProtectPowerBuff();
						wildPet->setPower(wildPet->getPower() + allProtectPoweradd);
						cout << "技能‘" << BSkill[j]->getName() << "’为‘" << wildPet->getName() << "’加了 " << allProtectPoweradd << " 点防御力\n";
						Sleep(1000);
					}

				}
				if (wildPet->getNowLife() <= 0)break;
				cout << "按任意键继续...";
				getchar();
				while(true)if(getchar()=='\n')break;
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
	if (yourPet->getNowLife() <= 0|| yourPet->getNowPP()<5) {
		yourPet->setNowLife(0);
return -1;
	}
		
	if (wildPet->getNowLife() <= 0 || wildPet->getNowPP() < 5) {
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
			<< yourPet->getName() << "’的等级+1\n";
		Sleep(1000);
		cout << "按任意键继续...";
		while (true)if (getchar() == '\n')break;
		cout << "是否抓捕宠物"<< wildPet->getName()<<"？（是--Y   否--双击回车键）\n" ;
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
								Sleep(1000);
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
			else {
				cout << "您背包中宠物已满/蛋不够，不能捕捉！\n";
				Sleep(1000);
				cout << "自动退出战斗...";
				Sleep(1000);
			}
		}
	}
	else {
		cout << "宠物血量/PP值已耗尽！是否继续战斗？（是--Y   否--双击回车键）" << endl
			<<"请输入选择：";
		char a = getchar();
		if (a == 'y' || a == 'Y') {
			while (true)if (getchar() == '\n')break;
			beginBattle();
		}

		else {
			while (true)if (getchar() == '\n')break;
			cout << "本次战斗失败！" << endl;
			Sleep(1000);
		}
	}
}


