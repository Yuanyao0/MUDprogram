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
	cout << "金钱:" << getMoney() << "\t\t"
		<< "目前位置:" << getPos() << "\t\t";
	this->showBag();
	
}

void Player::showBag()const
{
	bag.showInfo();
	if (!bag.getNowSize())
		cout << "无" << endl;
}

int Player::getMoney() const
{
	return money;
}

int Player::getPos() const
{
	return pos;
}

bool Player::pushBag(Pet * pet)
{
	if(bag.add(pet))
	{
		return true;
	}
	else {
		return false;
	}
}

void Player::removeBag(Pet * pet)
{
	bag.remove(pet);
}

void Player::setPos(int x)
{
	pos = x;
}

Player * Player::creatPlayer(std::string name, int pos ,int money, Bag & bag)
{
	if (instance != NULL)
		return instance;
	else
		return instance= new Player( name,  pos,  money,   bag);
}

bool Player::pushEgg()//放入蛋
{
	if (bag.getNowEggSize() == bag.getEggCapacity()) {
		cout << "背包已满！\n";
		return false;
	}
	else {
		bag.setEgg(bag.getNowEggSize() + 1)  ;
		return true;
	}
	


}
void Player::removeEgg()//取出蛋
{
	if (bag.getNowEggSize() == 0) {
		cout <<"你没有蛋！\n";
	
	}
	else {
		bag.setEgg(bag.getNowEggSize() - 1);
	}


}


void Player::deletePlayer()
{
	if (Player::instance) {
		delete Player::instance;
		Player::instance = NULL;
	}
}
Bag * Player::getBag() const
{
	return &bag;
}

Player* Player::instance = NULL;

Player::Release::~Release()
{
	if (Player::instance)
		delete Player::instance;
}
