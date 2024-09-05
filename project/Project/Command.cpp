#include "Command.h"
using namespace std;
void Command::showShop(){
    system("cls");
    std::cout << "��ӭ�����̵꣡" << std::endl;
    std::cout << "1.���������  2.�ظ�HP  3.�ظ�PP" << std::endl;
    std::cout << "��ѡ��(�������)��";
}
void Command::showShopEgg(Player* player) {
    system("cls");
    std::cout << "��������Ҫ��������ࣺ" << std::endl;
    for (int i = 0; i < EGGKINDCOUNT; i++)cout << i + 1 << "." << EGGNAME[i] << "(��׽����" 
        << EGGPROBABILITY[i] << ")\t" << "�۸�" << EGGPRICE[i] << endl;
    std::cout << "�������У�\n";
    player->getBag()->EggshowInfo();
    cout << "�������У�" << player->getMoney()<<endl;
}

void Command::shop(Player* player) {
    char ch;
    int choice=-1;
    while (true) { //��ȡѡ���ж������Ƿ���ȷ
        showShop();
        ch = getchar();
        choice = ch - 48;
        while (true)if (getchar() == '\n')break;
        if (choice > 0 && choice <=3) {
            break;
        }
        cout << "��������ȷ��ѡ�\n";
        Sleep(1000);
    }
    int noweggsize=-1;
    int capacity = -1;
    int k = 0 ;
    int m = 0 ;
    switch (choice) {
    case 1:
        noweggsize = player->getBag()->getNowEggSize();
        capacity = player->getBag()->getEggCapacity();

        if (noweggsize >= capacity) //�жϱ����Ƿ�����
        {
            player->getBag()->EggshowInfo();
            std::cout << "����������" << std::endl;
            Sleep(1000);
        }
        else
        {
            
            char ch;
            int kind = -1;
            int num=-1;
            while (true) { //��ȡѡ���ж������Ƿ���ȷ
                showShopEgg(player);
                ch = getchar();
                kind = ch - 48;
                while (true)if (getchar() == '\n')break;
                if (kind > 0 && kind <= 3) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }
            
            while (true) { //�жϱ��������Ƿ��㹻
                std::cout <<"��ѡ����"<< EGGNAME[kind-1] << "����������Ҫ�����������" << std::endl;
                ch = getchar();
                num = ch - 48;
                while (true)if (getchar() == '\n')break;
                if (num > 0 && num+player->getBag()->getNowEggSize()<= player->getBag()->getEggCapacity()) {
                    break;
                }
                
                cout << "�������/�����������㣡\n";
                Sleep(1000);
                cout << "���������룺\n";
                Sleep(500);
            }
            
            if (player->getMoney() < EGGPRICE[kind - 1] * num) { //�жϽ���Ƿ��㹻
                std::cout << "��Ҳ��㣡" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - EGGPRICE[kind - 1] * num);
                for (int i = 0; i < num; i++) //�������봴��������
                {
                    Egg * egg = new Egg(kind);
                    player->getBag()->addEgg(egg);
                }
            }
            cout << "�ɹ�����" << num << "��" << EGGNAME[kind - 1] << "!" << std::endl;
        }
        shop(player);
        break;
    case 2:
        for (int i = 1; i <= player->getBag()->getNowSize(); i++) //�жϳ���HP�Ƿ���Ҫ�ظ�
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife())
            {
                k = 1;
            }
        }
        if (k == 0)
            std::cout << "���г���HP������ظ���" << std::endl;
        else
        {
            if (player->getMoney() < HPPRICE) { //�жϽ���Ƿ��㹻
                std::cout << "��Ҳ��㣡" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - HPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //�ظ����г���HP
                {
                    player->getBag()->getPetByIndex(i)->setNowLife(player->getBag()->getPetByIndex(i)->getLife());
                }
                std::cout << "���г���HP���ѻظ���" << std::endl;
            }
        }
        shop(player);
        break;
    case 3:

        for (int i = 1; i <= player->getBag()->getNowSize(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife()) //�жϳ���PP�Ƿ���Ҫ�ظ�
            {
                m = 1;
            }
        }
        if (m == 0)
            std::cout << "���г���PP������ظ���" << std::endl;
        else
        {
            if (player->getMoney() < PPPRICE) { // �жϽ���Ƿ��㹻
                std::cout << "��Ҳ��㣡" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - PPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //�ظ����г���PP
                {
                    player->getBag()->getPetByIndex(i)->setNowPP(player->getBag()->getPetByIndex(i)->getPP());
                }
                std::cout << "���г���PP���ѻظ���" << std::endl;
            }
        }
        shop(player);
        break;
    default:
        std::cout << "����" << std::endl;
        break;
    }

}

void Command::changeMap(int& pos, Player& player) {
    
    int k[6], j = 1;
    for (int i = 0; i < 6; i++) { //չʾ��ͼ
        if (i != pos) {
            cout << j << ". " << MAP[i] << endl;
            k[j++] = i;
        }
    }

    char ch;
    int  mapchoice = -1;
    while (true) {
        cout << "��ѡ����Ҫ�л��ĵ�ͼ��" << endl;
        ch = getchar(); // ��ȡ��ͼѡ��
        mapchoice = ch - 48;
        while (true)if (getchar() == '\n')break; //�ж������Ƿ���ȷ
        if (mapchoice > 0 && mapchoice <= 6) {
            break;
        }
        cout << "��������ȷ��ѡ�\n";
        Sleep(1000);
    }
    player.setPos(k[mapchoice]);
}

void Command::newshow() {
    system("cls");
    cout << "************************************************************\n"
        << " * *��ӭ���������д�½��MUD��Ϸ * *\n"
        << " * ***********************************************************" << endl;
    cout << "����ǰ��һ�����ص�����ϯ����������½����½�ϵĵĳ��ﶼ�����˱��죬����������֮����\n��Ϊ��������ʿ�������ȥ�������������������Դ�����ǣ���̤�����ó�......" << endl;
    cout << "��ѡ��" << endl;
    cout << "1. ����Ϸ\n" << "2.������Ϸ" << endl;
}
void Command::showChoice(int pos) {
    system("cls");
    cout << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << endl;
    cout << "1. �л���ͼ" << endl;
    cout << "2. �̵�" << endl;
    cout << "3. ��ս����Boss" << endl;
    cout << "4. �˳���Ϸ" << endl;
}
void Command::showMapChoice(int pos) {
    system("cls");
    cout << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << endl;
    cout << "1. �л���ͼ" << endl;
    cout << "2. ս��������׽����" << endl;
    cout << "3. �˳���Ϸ" << endl;
}
void Command::newGame()
{
    string filename = "data.txt";
    Bag* bag = new Bag(CAPACITY);
    Player* player = Player::creatPlayer("a", 5, 100, *bag);
    petHouse* house = new petHouse(20);
    
    char ch;
    int  iscontinue = -1;
    int choice=-1;
    int pos = -1;
    Battle* battle;
    while (true) {
        newshow();
        ch = getchar();
        iscontinue = ch - 48;
        while (true)if (getchar() == '\n')break; //�ж������Ƿ���ȷ
        if (iscontinue > 0 && iscontinue <= 2) {
            break;
        }
        cout << "��������ȷ��ѡ�\n";
        Sleep(1000);
    }

    if (!(iscontinue - 1))
    {
        string name;
        cout << "����������ǳƣ�" << endl;
        std::cin >> name; //��ȡ����ǳ�
        player->setName(name);

        std::cout << "��ѡ����ĳ�ʼ���" << std::endl;
        std::cout << "1.�ƽ���  2.Գ��  3.Сˮ��  4.����ʨ  5.������" << std::endl;
        char ch;
        int  petnum = -1;
        while (true) {
            //...
            getchar();
            ch = getchar(); //��ȡ����ѡ��
            petnum = ch - 48;
            while (true)if (getchar() == '\n')break;
            if (petnum > 0 && petnum <= 5 ) {
                break;
            }
            cout << "��������ȷ��ѡ�\n";
            Sleep(1000);
        }
        
        Pet* pet = new Pet(petnum - 1);
        player->getBag()->add(pet);
    }
    if (iscontinue - 1) {
        readGameData(player, house, filename);
    }

    while (1) {
        pos = player->getPos();
        switch (pos) {
        case 5:
            
            
            while (true) {
                showChoice(pos);
                ch = getchar();
                choice = ch - 48;
                while (true)if (getchar() == '\n')break; //�ж������Ƿ���ȷ
                if (choice > 0 && choice <= 4) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }

            switch (choice) {
            case 1:
                changeMap(pos, *player); //�л���ͼ
                continue;
            case 2:
                shop(player); //�����̵�
                break;
            case 3:
                battle = new Battle(*player); //������ս��
                battle->beginBattle();
                break;
            case 4:
                saveGameData(player, house, filename); //������Ϸ
                break;
            default:
                cout << "������Ч���������룡����" << endl;
                break;
            }
            break;
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            showMapChoice(pos);
            char ch;
            int choice;
            while (true) {
                showMapChoice(pos);
                ch = getchar();
                choice = ch - 48;
                while (true)if (getchar() == '\n')break; //�ж������Ƿ���ȷ
                if (choice > 0 && choice <= 3) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }
            switch (choice) {
            case 1:
                changeMap(pos, *player); //�л���ͼ
                continue;
            case 2:
                battle = new Battle(*player); //������ս��
                battle->beginBattle();
                break;
            case 3:
                saveGameData(player, house, filename); //������Ϸ�浵
                break;
            default:
                cout << "�˳�����" << endl;
                break;
            }
            break;
        default:
            cout << "��ͼ�л�����" << endl;
            break;
        }
    }

}