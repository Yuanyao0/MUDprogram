#include "FileStore.h"
#include "Battle.h"
using namespace std;

int main() {
	string filename = "data.txt";
	cout << "new--Y   load--������\n";
	string a;
	cin >> a;
	Bag* bag = new Bag(CAPACITY);
	Player* player = Player::creatPlayer("a", 0, 0, *bag);
	petHouse* house = new petHouse(20);

	if (a == "Y") {
		cout << "name:";
		string b;
		cin >> b;
		player->setName(b);
		player->setMoney(1000);
		Pet* pet = new Pet(10);
		player->getBag()->add(pet);
		player->setPos(0);
		Egg* egg = new Egg(2);
		player->getBag()->addEgg(egg);
	}
	else {
		readGameData(player, house, filename);
	}
	cout << "�Ƿ����ս��������--Y  ��--��������\n";
	string choice = "";
	cin >> choice;
	if (choice == "Y") 
		while (true)if (getchar() == '\n')break;
		Battle battle(*player);


	saveGameData(player, house, filename);

}