#include "Battle.h"
#include "ConstTable.h"
#include <iostream>
using namespace std;

Battle::Battle(Player& player) :player(player) {
	//������ɹ���
	unsigned seed = static_cast<unsigned>(time(NULL));
	srand(seed);
	int aseed = rand() % MAXPETCOUNT;
	int theSeed = player.getPos() + aseed * 5;		//��������
	wildPet = new Pet(theSeed);
	beginBattle();
}
Battle::~Battle()
{
	if (wildPet != NULL)
		delete wildPet;
	cout << "����ս��������" << endl;
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
			cout << "��ѡ����ĳ��";
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
						<< "Ѫ��Ϊ0����ѡ��������ѡ�";
					
				}
					
			}
			else {
				cout << "��������ȷ��ѡ�\n";
				while (true)if (getchar() == '\n')break;
				Sleep(1000);
				
			}
		}
	}
	else {
		cout << "����ȫ���������������˰ɣ�\n";
	}
	
}

void Battle::showAttrPanel()
{
	wildPet->showInfo();
	cout << endl;
	cout << "\n"<<player.getName()<<"�ĳ���:\n";
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
	
	cout << "\n��ѡ���ܣ�";
	//�жϼ���ѡ���Ƿ����
	while (true) {
		char b = getchar();
		choice = b - 48;
		if (choice > 0 && choice <= yourPet->getSkillCount()) {
			int PPkey = yourPet->getNowPP() - yourPet->getSkill(choice - 1)->getPPconsume();
			if (PPkey < 0)
			{
				cout << "PPֵ���㣡������ѡ��(�����������)\n";
				getchar();
				system("cls");
				showAttrPanel();
				playerChooseSkill();
			}
			else {
				yourPet->setNowPP(PPkey);
				ASkill.push_back(yourPet->getSkill(choice - 1));
				cout << "��ĳ��" << yourPet->getName() << "��ʹ���˼��ܡ�"
					<< yourPet->getSkill(choice - 1)->getName() << "����\n" << endl;
				Acount++;
				Sleep(1000);
				break;
			}
		}
		else {
			while (true)if (getchar() == '\n')break;
			system("cls");
			showAttrPanel();
			cout << "\n��������ȷ��ѡ�\n";
			cout << "��ѡ���ܣ�";
		}
	}
}

void Battle::beginBattle()
{
	choosePet();
	int nowAttacker = 1;
	int PLAYER = 1; 
	showAttrPanel();
	cout << wildPet->getName() << ":��Ҫ��ʼ�����ˣ�" << endl;
	cout << yourPet->getName() << ":come on!\n\n" <<"���س�������...";
	getchar();
	while (true)if (getchar() == '\n')break;
	system("cls");
	while (!judegeEnd()) {
		if (nowAttacker == PLAYER) {
			choice = -1;
			playerChooseSkill();
			
			//��������ϻغ�ʹ�ü���
			for (int j = 0; j < Bcount; j++)
				{	//���˺�=����ֵ*
					//��׷������+׷�����˰ٷֱ�+miss*������+���˰ٷֱ�+��1-������*��������
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
					cout << "���ܡ�" << BSkill[j]->getName()<<"���ԡ�"<< yourPet-> getName()<< "����� " << allhurt << " ���˺���\n";
					Sleep(1000);
					
					if (allhurt >= yourPet->getNowLife()) {
						yourPet->setNowLife(0);
						cout << "�����������...\n";
						while (true)if (getchar() == '\n')break;
						system("cls");

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
					for (int j = 0; j < Acount; j++) {
						if (ASkill[j]->getHPaddKey()) {
							int allHPadd = ASkill[j]->getHPadd() + ASkill[j]->getHPaddPercent() * yourPet->getLife();
							if (yourPet->getNowLife() + allHPadd > yourPet->getLife()) {
								cout << "HP������";
								allHPadd = yourPet->getLife() - yourPet->getNowLife();
								yourPet->setNowLife(yourPet->getLife());
							}
							else {
								yourPet->setNowLife(yourPet->getNowLife() + allHPadd);
							}
							cout << "��" << ASkill[j]->getName()<<"������Ϊ��"<< yourPet->getName() << "������ "<< allHPadd << " HP��\n";
							if (ASkill[j]->getLifeKey())
								if (yourPet->getNowLife() <= 0) {
									yourPet->setNowLife(1);
									cout << "���ڡ�" << ASkill[j]->getName() << "���ı������ܣ����ڡ�" << yourPet->getName() << "������1��Ѫ\n";
								}
							if (yourPet->getNowLife() <= 0)break;
						}
						if (ASkill[j]->getPowerBuffKey()) {
							int allPoweradd = yourPet->getPower() * ASkill[j]->getPowerBuff();
							yourPet->setPower(yourPet->getPower() + allPoweradd);
							cout<<"��" << ASkill[j]->getName() << "������Ϊ��" << yourPet->getName() << "������ " << allPoweradd << " �㹥����\n";
						}
						if (ASkill[j]->getProtectPowerBuffKey()) {
							int allProtectPoweradd = yourPet->getProtectPower() * ASkill[j]->getProtectPowerBuff();
							yourPet->setProtectPower(yourPet->getProtectPower() + allProtectPoweradd);
							cout << "��" << ASkill[j]->getName() << "������Ϊ��" << yourPet->getName() << "������ " << allProtectPoweradd << " �������\n";
						}
						
						
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
						cout <<"\n"<< wildPet->getName() << "ʹ���˼��ܡ�"
							<< wildPet->getSkill(choice - 1)->getName() << "'��\n\n";
						Sleep(1000);
						wildPet->setNowPP(PPkey);
						BSkill.push_back(wildPet->getSkill(choice-1));
						Bcount++;
						break;
					}
				}
				else {
					cout << "��������ȷ��ѡ�(�����������)\n";
					getchar();
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
					+(1- wildPet->getSkill(choose - 1)->getMissKey())
					* (ASkill[j]->getAvoidableHurt()
						+ ASkill[j]->getAvoidableHurtPercent()
						* wildPet->getLife()
						+ (1 - wildPet->getProtectPower() * 0.001)
						* yourPet->getPower()))
					* yourPet->ElementFight(wildPet);
				cout << "���ܡ�" << ASkill[j]->getName() << "��"<<"�ԡ�" << wildPet->getName() << "����� " << allhurt << " ���˺���\n";
				Sleep(1000);
				
				
				if (allhurt >= wildPet->getNowLife()) {
					cout << "�����������...\n";
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
				//����A������
				for (int j = Acount - 1; j >= 0; j--)if (ASkill[j]->getRound() == 0)Aremove(j);
				//Bû��������B�����������������
				BSkill.push_back(wildPet->getSkill(choose - 1));
				for (int j = 0; j < Bcount; j++) {
					if (BSkill[j]->getHPaddKey()) {
						int allHPadd = BSkill[j]->getHPadd() + BSkill[j]->getHPaddPercent() * wildPet->getLife();
						if (wildPet->getNowLife() + allHPadd > wildPet->getLife()) {
							
							allHPadd = wildPet->getLife() - wildPet->getNowLife();
							wildPet->setNowLife(wildPet->getLife());
							cout << "HP������";
						}
						else {
							wildPet->setNowLife(wildPet->getNowLife() + allHPadd);
						}
						cout << "���ܡ�" << BSkill[j]->getName() << "Ϊ��" << wildPet->getName() << "������ " << allHPadd << " HP\n";
						if (BSkill[j]->getLifeKey())
							if (wildPet->getNowLife() <= 0) {
								wildPet->setNowLife(1);
								cout << "���ڡ�" << BSkill[j]->getName() << "���ı������ܣ����ڡ�" << wildPet->getName() << "������1��Ѫ\n";
							}
						if (wildPet->getNowLife() <= 0)break;
					}
					if (BSkill[j]->getPowerBuffKey()) {
						int allPoweradd = wildPet->getPower() * BSkill[j]->getPowerBuff();
						wildPet->setPower(wildPet->getPower() + allPoweradd);
						cout<<"���ܡ�" << BSkill[j]->getName() << "��Ϊ��" << wildPet->getName() << "������ " << allPoweradd << " �㹥����\n";
					}
					if (BSkill[j]->getProtectPowerBuffKey()) {
						int allProtectPoweradd = wildPet->getProtectPower() * BSkill[j]->getProtectPowerBuff();
						wildPet->setPower(wildPet->getPower() + allProtectPoweradd);
						cout << "���ܡ�" << BSkill[j]->getName() << "��Ϊ��" << wildPet->getName() << "������ " << allProtectPoweradd << " �������\n";
					}

				}
				if (wildPet->getNowLife() <= 0)break;
				cout << "�����������...";
				getchar();
				getchar();
			}
			//Sleep(1000);
			else break;
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
		cout << "��ϲ����ʤ��!" << endl;
		cout << "��� " << wildPet->getMoney() << "��Ǯ\t��"
			<< yourPet->getName() << "���ĵȼ�+1\n\n";
		cout << "�Ƿ�ץ������"<< wildPet->getName()<<"������--Y   ��--��������\n" ;
		char a=getchar();
		if (a == 'y' || a=='Y') {
			while (true)if (getchar() == '\n')break;
			//��������г���û������Ҳ���еĻ�
			if (player.getBag()->getNowEggSize() && player.getBag()->getCapacity() > player.getBag()->getNowSize())
			{
				while (true) {
					system("cls");
					showAttrPanel();
					player.getBag()->EggshowInfo();
					cout << "��0ȡ����׽\n";
					cout << "����ѡ��һ�׽���������룺";
					char ch = getchar();
					choice=ch-48;
					if (choice ==0) {
						cout << "ȡ����׽�ɹ���\n";
						break;
					}
					else if (choice < 0||choice>player.getBag()->getEggCapacity()) {
						cout << "��������ȷ��ѡ�\n";
						while (true)if (getchar() == '\n')break;
						Sleep(1000);
					}
					else {
						int eggkind = player.getBag()->getEggByIndex(choice - 1)->getKind();
						if (player.removeEgg(choice - 1)) {
							if (catchPet(eggkind)) {
								//����һ�������Ϊ���˳�ս��ϵͳ��ʱ��MONSTER��������PETָ����ʧ
								Pet* NewPet = new Pet(*wildPet);
								player.pushBag(NewPet);
								cout << "����" << wildPet->getName() << "�Ѳ�׽!\n";
								break;
							}
							else {
								cout << "����" << wildPet->getName() << "��׽ʧ��!\n";
								break;
							}

						}

					}
					
					

				}
			}
			else cout << "�������г�������/�����������ܲ�׽��\n";
		}
	}
	else {
		cout << "����Ѫ���Ѻľ����Ƿ����ս��������--Y   ��--��������" << endl
			<<"������ѡ��";
		char a = getchar();
		if (a == 'y' || a == 'Y') {
			while (true)if (getchar() == '\n')break;
			beginBattle();
		}

		else cout << "����ս��ʧ�ܣ�" << endl;
		
	}
}


