
#include "Command.h"

using namespace std;
ostringstream oss;
ColorContainer* c = new ColorSys();
void Command::showShop(){
    system("cls");
    oss << "Ŀǰ���ڵ�ͼ��" << "��ӭ�����̵꣡" << std::endl
        << "1.���������  2.�ظ�HP  3.�ظ�PP 0.�뿪�̵�" << std::endl;
    c->changeTextColor('Y', oss);
    
}

static void showMenu() {
    Utill::changeForeground('R');
    ifstream fin;
    fin.open("welcomemenu.txt", ios::in);
    if (!fin.is_open())cout << "�ļ���ʧ��" << endl;
    //��ȡ����ʾ��ӭ����
    string dataline;
    for (int i = 0; i < 13; i++) {
        getline(fin, dataline);
        cout << dataline << endl;
        if (i == 10)
            Utill::ForegroundRGS();
    }
    Utill::ForegroundALL();
    fin.close();
}


void Command::showShopEgg(Player* player) {
    system("cls");
    for (int i = 0; i < EGGKINDCOUNT; i++)cout << i + 1 << "." << EGGNAME[i] << "(��׽����" 
        << EGGPROBABILITY[i] << ")\t" << "�۸�" << EGGPRICE[i] << endl;
    std::cout << "�������У�\n";
    player->getBag()->EggshowInfo();
    cout << "�������У�" << player->getMoney()<<"��ҡ�" << endl;
    
}
void Command::House(Player * player,petHouse* house) {
    char ch;
    int choice = -1;
    while (true) {
        house->showInfo();
        cout << endl;
        cout << "�����г��\n";
        player->getBag()->showInfo();
        cout << "\n1.ȡ������  2.�������  3.��������"<<endl
            <<"4.�鿴��������  0.�뿪�ֿ�\n\n";
        cout << "���س������ѡ��...\n";
        if (getchar() != '\n')
            while (true)if (getchar() == '\n')break;
        ch = getchar();
        choice = ch - 48;
        if (ch != '\n')
            while (true)if (getchar() == '\n')break;
          
        if (!choice) {
            return;
        }
        if (choice > 0 && choice <= 4) {
            break;
        }
        cout << "��������ȷ��ѡ�\n";
        Sleep(1000);
    }
   
    switch (choice) {
    case 1:
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "�����г��\n";
            player->getBag()->showInfo();
            cout << "\n�س���������ȡ���ĳ���...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= house->getNowSize()) {
                break;
            }
            cout << "��������ȷ��ѡ�\n";
            Sleep(1000);
        }
        player->getBag()->add(house->getPetByIndex(choice - 1));
        house->remove(house->getPetByIndex(choice - 1));
        cout << "�ƶ��ɹ���\n";
        break;
    case 2:
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "�����г��\n";
            player->getBag()->showInfo();
            cout << "\n�س������������ĳ���...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= player->getBag()->getNowSize()) {
                break;
            }
            cout << "��������ȷ��ѡ�\n";
            Sleep(1000);
        }
        house->add(player->getBag()->getPetByIndex(choice - 1));
        player->getBag()->remove(player->getBag()->getPetByIndex(choice - 1));
        cout << "�ƶ��ɹ���\n";
        break;
    case 3:
        if (player->getBag()->getNowSize() + house->getNowSize() == 1) {
            cout << "ֻ��һ���������������\n";
            Sleep(1000);
            break;
        }
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "�����г��\n";
            player->getBag()->showInfo();
            cout << "1.�����ֿ��г���  2.���������г���\n";
            cout << "\n�س�������ѡ��...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= 2) {
                break;
            }
            cout << "��������ȷ��ѡ�\n";
            Sleep(1000);
        }
        if (choice == 1) {
            while (true) {
                house->showInfo();
                cout << endl;
                cout << "\n�س���ѡ����...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= house->getNowSize()) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }
            house->remove(house->getPetByIndex(choice - 1));
            cout << "�����ɹ���\n";
            Sleep(1000);
        }
        else {
            while (true) {
                cout << "�����г��\n";
                player->getBag()->showInfo();
                cout << endl;
                cout << "\n�س���ѡ����...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= player->getBag()->getNowSize()) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }
            player->getBag()->remove(house->getPetByIndex(choice - 1));
            cout << "�����ɹ���\n";
            Sleep(1000);
        }
        break;
    case 4:
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "�����г��\n";
            player->getBag()->showInfo();
            cout << "1.�鿴�ֿ��г���  2.�鿴�����г���\n";
            cout << "\n�س�������ѡ��...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= 2) {
                break;
            }
            cout << "��������ȷ��ѡ�\n";
            Sleep(1000);
        }
        if (choice == 1) {
            if (house->getNowSize() == 0) {
                cout << "�ֿ����޳��\n";
                Sleep(1000);
                break;
            }
            while (true) {
                house->showInfo();
                cout << endl;
                cout << "\n�س���ѡ��鿴...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= house->getNowSize()) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }
            house->getPetByIndex(choice - 1)->showInfo();
            cout << endl;
            Sleep(1000);
            cout << "\n�س������...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
        }
        else {
            if (player->getBag()->getNowSize() == 0) {
                cout << "�������޳��\n";
                Sleep(1000);
                break;
            }
            while (true) {
                cout << "�����г��\n";
                player->getBag()->showInfo();
                cout << "\n�س���ѡ��鿴...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= player->getBag()->getNowSize()) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }
            player->getBag()->getPetByIndex(choice - 1)->showInfo();
            cout << endl;
            Sleep(1000);
            cout << "\n�س������...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;

        }
        break;
    }
    House( player,  house);
}

void Command::shop(Player* player) {
    char ch;
    int choice=-1;
    while (true) { //��ȡѡ���ж������Ƿ���ȷ
        showShop();
        cout << "���س������ѡ��...\n";
        if (getchar() != '\n')
            while (true)if (getchar() == '\n')break;
        ch = getchar();
        choice = ch - 48;
        if (ch != '\n')
            while (true)if (getchar() == '\n')break;
        if (!choice) {
            return;
        }
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
                std::cout << "��������Ҫ��������ࣺ" << std::endl;
                cout << "���س������...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                kind = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;

                if (kind > 0 && kind <= 3) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                Sleep(1000);
            }
            
            while (true) {//�жϱ��������Ƿ��㹻
                showShopEgg(player);
                std::cout <<"��ѡ����"<< EGGNAME[kind-1] << "����������Ҫ�����������" << std::endl;
                cout << "���س������...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                num = ch - 48;

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
                Sleep(1000);
            }
            else {
                player->setMoney(player->getMoney() - EGGPRICE[kind - 1] * num);
                for (int i = 0; i < num; i++) //�������봴��������
                {
                    Egg * egg = new Egg(kind);
                    player->getBag()->addEgg(egg);
                }
                cout << "�ɹ�����" << num << "��" << EGGNAME[kind - 1] << "!" << std::endl;
                Sleep(1000);
            }
            
        }
        shop(player);
        break;
    case 2:
        for (int i = 0; i < player->getBag()->getNowSize(); i++) //�жϳ���HP�Ƿ���Ҫ�ظ�
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife())
            {
                k = 1;
            }
        }
        if (k == 0) {
            std::cout << "���г���HP������ظ���" << std::endl;
            Sleep(1000);
        }
            
        else
        {
            if (player->getMoney() < HPPRICE) { //�жϽ���Ƿ��㹻
                std::cout << "��Ҳ��㣡" << std::endl;
                Sleep(1000);
            }
            else {
                player->setMoney(player->getMoney() - HPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //�ظ����г���HP
                {
                    player->getBag()->getPetByIndex(i)->setNowLife(player->getBag()->getPetByIndex(i)->getLife());
                }
                std::cout << "���г���HP���ѻظ���" << std::endl;
                Sleep(1000);
            }
        }
        shop(player);
        break;
    case 3:

        for (int i = 0; i < player->getBag()->getNowSize(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowPP() < player->getBag()->getPetByIndex(i)->getPP()) //�жϳ���PP�Ƿ���Ҫ�ظ�
            {
                m = 1;
            }
        }
        if (m == 0) {
            std::cout << "���г���PP������ظ���" << std::endl;
            Sleep(1000);
        }
            
        else
        {
            if (player->getMoney() < PPPRICE) { // �жϽ���Ƿ��㹻
                std::cout << "��Ҳ��㣡" << std::endl;
                Sleep(1000);
            }
            else {
                player->setMoney(player->getMoney() - PPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //�ظ����г���PP
                {
                    player->getBag()->getPetByIndex(i)->setNowPP(player->getBag()->getPetByIndex(i)->getPP());
                }
                std::cout << "���г���PP���ѻظ���" << std::endl;
                Sleep(1000);
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
    
    char ch;
    int  mapchoice = -1;
    int k[6] = { 0 };
    int round = 0;
    while (true) {
        system("cls");
        int j = 1 ;
        for (int i = 0; i < 6; i++) { //չʾ��ͼ
            if (i != pos) {
                switch (i) {
                case 0:
                    oss << j << ". " << MAP[i] << "(��)" << endl;
                    c->changeTextColor('Y', oss);
                    k[j++] = i;
                    break;
                case 1:
                    oss << j << ". " << MAP[i] << "(ľ)" << endl;
                    c->changeTextColor('G', oss);
                    k[j++] = i;
                    break;
                case 2:
                    oss << j << ". " << MAP[i] << "(ˮ)" << endl;
                    c->changeTextColor('B', oss);
                    k[j++] = i;
                    break;
                case 3:
                    oss << j << ". " << MAP[i] << "(��)" << endl;
                    c->changeTextColor('R', oss);
                    k[j++] = i;
                    break;
                case 4:
                    oss << j << ". " << MAP[i] << "(��)" << endl;
                    c->changeTextColor('O', oss);
                    k[j++] = i;
                    break;
                case 5:
                    oss << j << ". " << MAP[i] << endl;
                    c->changeTextColor('W', oss);
                    k[j++] = i;
                    break;
                }
            }
        }
        cout << "��ѡ����Ҫ�л��ĵ�ͼ��" << endl;
        cout << "���س���ѡ��...";
        if (getchar() != '\n')
            while (true)if (getchar() == '\n')break;
        ch = getchar(); // ��ȡ��ͼѡ��
        mapchoice = ch - 48;
        if (ch != '\n')
            while (true)if (getchar() == '\n')break;

        if (mapchoice > 0 && mapchoice < 6) {
            break;
        }
        cout << "��������ȷ��ѡ�\n";
        Sleep(1000);
    }
    player.setPos(k[mapchoice]);
}

void Command::newshow() {
    system("cls");
    showMenu();
    oss << "************************************************************\n"
        << "* *��ӭ���������д�½��MUD��Ϸ * *\n"
        << "************************************************************" << endl;
    c->changeTextColor('Y', oss);
    cout << endl;
    cout << "����ǰ��һ�����ص�����ϯ����������½����½�ϵĵĳ��ﶼ�����˱��죬����������֮����\n��Ϊ��������ʿ�������ȥ�������������������Դ�����ǣ���̤�����ó�......" << endl;
    cout << "��ѡ��" << endl;
    cout << "1.����Ϸ\n" << "2.������Ϸ" << endl;
}
void showMapColor(int pos) {
    switch (pos) {
        case 0:
            oss << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << "(��)" << endl;
            c->changeTextColor('Y', oss);
            break;
        case 1:
            oss << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << "(ľ)" << endl;
            c->changeTextColor('G', oss);
            break;
        case 2:
            oss << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << "(ˮ)" << endl;
            c->changeTextColor('B', oss);
            break;
        case 3:
            oss << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << "(��)" << endl;
            c->changeTextColor('R', oss);
            break;
        case 4:
            oss << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << "(��)" << endl;
            c->changeTextColor('O', oss);
            break;
        case 5:
            oss << "Ŀǰ���ڵ�ͼ��" << MAP[pos] << endl;            
            c->changeTextColor('W', oss);
            break;
    }
}
void Command::showChoice(int pos) {
    system("cls");
    showMapColor(pos);
    cout << "1. �л���ͼ�����Կ��ƣ���->ľ->ˮ->��->��->��->...��" << endl;
    cout << "2. �̵�" << endl;
    cout << "3. �ֿ�" << endl;
    cout << "4. ��ս����Boss(������Сආ�)" << endl;
    cout << "5. (�������ݲ�)�˳���Ϸ" << endl;
}
void Command::showMapChoice(int pos) {
    system("cls");
    showMapColor(pos);
    cout << "1. �л���ͼ�����Կ��ƣ���->ľ->ˮ->��->��->��->...��" << endl;
    cout << "2. ս��������׽����" << endl;
    cout << "3. (�������ݲ�)�˳���Ϸ" << endl;
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
    int k = 0;
    Battle* battle;
    while (true) {
        newshow();
        ch = getchar();
        iscontinue = ch - 48;
        if (ch != '\n') 
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
        std::cout << "1." << PETLIST[0] << "  2." << PETLIST[1] << "  3." << PETLIST[2]
            << "  4." << PETLIST[3] << "  5." << PETLIST[4] << std::endl;
        char ch;
        int  petnum = -1;
        int round = 0;
        while (true) {
            system("cls");
            std::cout << "��ѡ����ĳ�ʼ���" << std::endl;
            std::cout << "1." << PETLIST[0] << "  2." << PETLIST[1] << "  3." << PETLIST[2]
                << "  4." << PETLIST[3] << "  5." << PETLIST[4] << std::endl;
            if (round)cout << "���س������ѡ��...\n";
            if(getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar(); //��ȡ����ѡ��
            petnum = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;

            if (petnum > 0 && petnum <= 5 ) {
                break;
            }
            cout << "��������ȷ��ѡ�\n";
            round++;
            Sleep(1000);
        }
        
        Pet* pet = new Pet(petnum - 1);
        player->getBag()->add(pet);
    }
    if (iscontinue - 1) {
        readGameData(player, house, filename);
    }
    bool isplay = true;
    while (isplay) {
        int round=0;
        pos = player->getPos();
        switch (pos) {
        case 5:
            
            
            while (true) {
                
                showChoice(pos);
                cout << "���س������ѡ��...\n";
                if (getchar() != '\n')
                   while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if(ch!='\n')
                    while (true)if (getchar() == '\n')break; //�ж������Ƿ���ȷ
                if (choice > 0 && choice <= 5) {
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
            case 4:
                battle = new Battle(*player); //������ս��
                break;
            case 5:
                saveGameData(player, house, filename); //������Ϸ
                isplay = false;
                break;
            case 3:
                House(player,house);
                break;
            default:
                cout << "������Ч���������룡����" << endl;
                Sleep(1000);
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
            round = 0;
            
            while (true) {//�ж������Ƿ���ȷ
                showMapChoice(pos);
                cout<<"���س������ѡ��...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                
                if (choice > 0 && choice <= 3) {
                    break;
                }
                cout << "��������ȷ��ѡ�\n";
                round++;
                Sleep(1000);
            }
            switch (choice) {
            case 1:
                changeMap(pos, *player); //�л���ͼ
                continue;
            case 2:
                
                for (int i = 0; i < player->getBag()->getNowSize(); i++) {
                    if (player->getBag()->getPetByIndex(i)->getNowLife() > 0)k = 1;
                }
                if (k)
                    battle = new Battle(*player); //������ս��
                else
                    cout << "����ȫ��������������ﵽ�̵�ظ�HP/PPֵ��\n";
                Sleep(1000);
                break;
            case 3:
                saveGameData(player, house, filename); //������Ϸ�浵
                isplay = false;
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
void Command::clearCin()
{
    //����������ĳ�����Ϣ
    cin.clear();
    //�������������Ч������Ϣ

    // numeric_limits<streamsize>::max() �������뻺��Ĵ�С��
    // ignore �����ڴ˽����������е�������ա�
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    //system("pause");
    //system("cls");

}