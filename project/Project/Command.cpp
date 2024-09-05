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

    switch (choice) { 
    case 1:
        int noweggsize = player->getBag()->getNowEggSize(), capacity = player->getBag()->getEggCapacity();

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
                for (int i = 0; i < num; i++)  //�������봴��������
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
        int k = 0;
        for (int i = 1; i <= player->getBag()->getNowSize(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife()) //�жϳ���HP�Ƿ���Ҫ�ظ�
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
        break;
    case 3:
        int m = 0;
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
            if (player->getMoney() < PPPRICE) {
               std::cout << "��Ҳ��㣡" << std::endl; //�жϽ���Ƿ��㹻
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
        break;
    default:
        std::cout << "��Ч��ѡ��" << std::endl;
        break;
    }

}

void Command::changeMap(int& pos, Player& player) {
    cout << "��ѡ����Ҫ�л��ĵ�ͼ��" << endl;
    int k[6], j = 1;
    for (int i = 0; i < 6; i++) { //չʾ��ͼ
        if (i != pos) {
            cout << j++ << ". " << MAP[i] << endl;
            k[j] = i;
        }
    }
    int mapchoice;
    cin >> mapchoice; //��ȡ��ͼѡ��
    player.setPos(k[mapchoice]);
}
void Command::newGame()
{
    cout << "************************************************************\n" << " * *��ӭ���������д�½��MUD��Ϸ * *\n" << " * ***********************************************************" << endl;
    cout << "����ǰ��һ�����ص�����ϯ����������½����½�ϵĵĳ��ﶼ�����˱��죬����������֮����\n��Ϊ��������ʿ�������ȥ�������������������Դ�����ǣ���̤�����ó�......" << endl;
    cout << "��ѡ��" << endl;
    cout << "1. ����Ϸ\n" << "2.������Ϸ" << endl;
    int iscontinue;
    Player* player;
    cin >> iscontinue;
    if (!(iscontinue - 1))
    {
        string name;
        cout << "����������ǳƣ�" << endl;
        std::cin >> name; //��ȡ����ǳ�
        Bag bag = Bag(CAPACITY);
        player = new Player(name, 5, 100, bag);
        std::cout << "��ѡ����ĳ�ʼ���" << std::endl;
        std::cout << "1."<<PETLIST[0]<<"  2."<<PETLIST[1]<<"  3."<<PETLIST[2]<<"  4."<<PETLIST[3]<<"  5."<<PETLIST[4] << std::endl;
        int petnum;
        cin >> petnum; //��ȡ����ѡ��
        Pet* pet = new Pet(petnum - 1); //�����������
        player->getBag()->add(pet);
    }
    if (iscontinue - 1) {
        Player* player = new Player(); //������Ҷ���Ӷ��̳д浵����
        player = readGameData(); //��ȡ��Ҵ浵
    }
    while (1) {
        int pos = player->getPos(); //��ȡ�����һ������
        switch (pos) { //��������ִ�ж�Ӧ�Ĳ���
        case '5':
            cout << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << endl;
            cout << "1. �л���ͼ" << endl;
            cout << "2. �̵�" << endl;
            cout << "3. ��ս����Boss" << endl;
            cout << "4. �˳���Ϸ" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
            case '1':
                changeMap(pos, *player);
                continue;
            case '2':
                shop(player);
                break;
            case '3':
                Battle * battle = new Battle(*player);
                battle->beginBattle();
                break;
            case '4':
                saveGameData();
                break;
            default:
                cout << "������Ч���������룡����" << endl;
                break;
            }
            break;
        case '4':
        case '3':
        case '2':
        case '1':
        case '0':
            cout << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << endl;
            cout << "1. �л���ͼ" << endl;
            cout << "2. ս��������׽����" << endl;
            cout << "3. �˳���Ϸ" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
            case '1':
                changeMap(pos, *player);
                continue;
            case '2':
                Battle * battle = new Battle(*player);
                battle->beginBattle();
                break;
            case '3':
                saveGameData();
                break;
            default:
                cout << "������Ч���������룡����" << endl;
                break;
            }
            break;
        default:
            cout << "��ͼ�����ڣ�����" << endl;
            break;
        }
    }

}