#include "Player.h"
#include "Error.h"
#include <iostream>
using namespace std;


Player::Player(string name, int pos, int money, Bag& bag) : name(name), pos(pos), money(money), bag(bag) {}


Player::~Player()
{
	/*if (instance != NULL)
	delete instance;*/
}

void Player::showInfo() const
{
	cout << "��Ǯ:" << getMoney() << "\t\t"
		<< "Ŀǰλ��:" << getPos() << "\t\t";
	this->showBag();

}
void Player::setMoney(int x) {
	money += x;
}

void Player::showBag()const
{
	bag.showInfo();
	if (!bag.getNowSize())
		cout << "��" << endl;
}

int Player::getMoney() const
{
	return money;
}

int Player::getPos() const
{
	return pos;
}

bool Player::pushBag(Pet* pet)
{
	if (bag.add(pet))
	{
		return true;
	}
	else {
		return false;
	}
}

void Player::removeBag(Pet* pet)
{
	bag.remove(pet);
}

void Player::setPos(int x)
{
	pos = x;
}

Player* Player::creatPlayer(std::string name, int pos, int money, Bag& bag)
{
	if (instance != NULL)
		return instance;
	else
		return instance = new Player(name, pos, money, bag);
}

bool Player::pushEgg(Egg* egg)//���뵰
{
	if (bag.add(egg))return true;
	else {
		cout << "����������\n";
		return false;
	}
}


bool Player::removeEgg(int index)//ȡ����
{
	if (index<0||index>=bag.getNowEggSize()) {
		return false;
	}
	else {
		bag.remove(bag.getEggByIndex(index));
		return true;
	}


}


void Player::deletePlayer()
{
	if (Player::instance) {
		delete Player::instance;
		Player::instance = NULL;
	}
}
Bag* Player::getBag() const
{
	return &bag;
}

Player* Player::instance = NULL;

Player::Release::~Release()
{
	if (Player::instance)
		delete Player::instance;
}
