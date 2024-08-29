#include "Player.h"

Player::Player(std::string name, int money) : name(name), money(money), bag(new Bag(10)) {
    // ��ʼ����ҵ����ֺͽ��
}

int Player::getMoney() const {
    return money;
}

void Player::reduceMoney(int amount) {
    if (money >= amount) {
        money -= amount;
    }
}

Bag* Player::getBag() const {
    return bag;
}