
#include "Command.h"

using namespace std;
ostringstream oss;
ColorContainer* c = new ColorSys();
void Command::showShop(){
    system("cls");
    oss << "目前所在地图：" << "欢迎来到商店！" << std::endl
        << "1.购买宠物球  2.回复HP  3.回复PP 0.离开商店" << std::endl;
    c->changeTextColor('Y', oss);
    
}

static void showMenu() {
    Utill::changeForeground('R');
    ifstream fin;
    fin.open("welcomemenu.txt", ios::in);
    if (!fin.is_open())cout << "文件打开失败" << endl;
    //读取并显示欢迎界面
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
    for (int i = 0; i < EGGKINDCOUNT; i++)cout << i + 1 << "." << EGGNAME[i] << "(捕捉概率" 
        << EGGPROBABILITY[i] << ")\t" << "价格：" << EGGPRICE[i] << endl;
    std::cout << "背包现有：\n";
    player->getBag()->EggshowInfo();
    cout << "你现在有：" << player->getMoney()<<"金币。" << endl;
    
}
void Command::House(Player * player,petHouse* house) {
    char ch;
    int choice = -1;
    while (true) {
        house->showInfo();
        cout << endl;
        cout << "背包中宠物：\n";
        player->getBag()->showInfo();
        cout << "\n1.取出宠物  2.放入宠物  3.丢弃宠物"<<endl
            <<"4.查看宠物属性  0.离开仓库\n\n";
        cout << "按回车后继续选择...\n";
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
        cout << "请输入正确的选项！\n";
        Sleep(1000);
    }
   
    switch (choice) {
    case 1:
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "背包中宠物：\n";
            player->getBag()->showInfo();
            cout << "\n回车后输入想取出的宠物...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= house->getNowSize()) {
                break;
            }
            cout << "请输入正确的选项！\n";
            Sleep(1000);
        }
        player->getBag()->add(house->getPetByIndex(choice - 1));
        house->remove(house->getPetByIndex(choice - 1));
        cout << "移动成功！\n";
        break;
    case 2:
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "背包中宠物：\n";
            player->getBag()->showInfo();
            cout << "\n回车后输入想存入的宠物...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= player->getBag()->getNowSize()) {
                break;
            }
            cout << "请输入正确的选项！\n";
            Sleep(1000);
        }
        house->add(player->getBag()->getPetByIndex(choice - 1));
        player->getBag()->remove(player->getBag()->getPetByIndex(choice - 1));
        cout << "移动成功！\n";
        break;
    case 3:
        if (player->getBag()->getNowSize() + house->getNowSize() == 1) {
            cout << "只有一个宠物，不允许丢弃！\n";
            Sleep(1000);
            break;
        }
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "背包中宠物：\n";
            player->getBag()->showInfo();
            cout << "1.丢弃仓库中宠物  2.丢弃背包中宠物\n";
            cout << "\n回车后输入选择...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= 2) {
                break;
            }
            cout << "请输入正确的选项！\n";
            Sleep(1000);
        }
        if (choice == 1) {
            while (true) {
                house->showInfo();
                cout << endl;
                cout << "\n回车后选择丢弃...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= house->getNowSize()) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                Sleep(1000);
            }
            house->remove(house->getPetByIndex(choice - 1));
            cout << "丢弃成功！\n";
            Sleep(1000);
        }
        else {
            while (true) {
                cout << "背包中宠物：\n";
                player->getBag()->showInfo();
                cout << endl;
                cout << "\n回车后选择丢弃...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= player->getBag()->getNowSize()) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                Sleep(1000);
            }
            player->getBag()->remove(house->getPetByIndex(choice - 1));
            cout << "丢弃成功！\n";
            Sleep(1000);
        }
        break;
    case 4:
        while (true) {
            house->showInfo();
            cout << endl;
            cout << "背包中宠物：\n";
            player->getBag()->showInfo();
            cout << "1.查看仓库中宠物  2.查看背包中宠物\n";
            cout << "\n回车后输入选择...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar();
            choice = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;
            if (choice > 0 && choice <= 2) {
                break;
            }
            cout << "请输入正确的选项！\n";
            Sleep(1000);
        }
        if (choice == 1) {
            if (house->getNowSize() == 0) {
                cout << "仓库中无宠物！\n";
                Sleep(1000);
                break;
            }
            while (true) {
                house->showInfo();
                cout << endl;
                cout << "\n回车后选择查看...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= house->getNowSize()) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                Sleep(1000);
            }
            house->getPetByIndex(choice - 1)->showInfo();
            cout << endl;
            Sleep(1000);
            cout << "\n回车后继续...";
            if (getchar() != '\n')
                while (true)if (getchar() == '\n')break;
        }
        else {
            if (player->getBag()->getNowSize() == 0) {
                cout << "背包中无宠物！\n";
                Sleep(1000);
                break;
            }
            while (true) {
                cout << "背包中宠物：\n";
                player->getBag()->showInfo();
                cout << "\n回车后选择查看...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                if (choice > 0 && choice <= player->getBag()->getNowSize()) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                Sleep(1000);
            }
            player->getBag()->getPetByIndex(choice - 1)->showInfo();
            cout << endl;
            Sleep(1000);
            cout << "\n回车后继续...";
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
    while (true) { //获取选择并判断输入是否正确
        showShop();
        cout << "按回车后继续选择...\n";
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
        cout << "请输入正确的选项！\n";
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

        if (noweggsize >= capacity) //判断背包是否已满
        {
            player->getBag()->EggshowInfo();
            std::cout << "背包已满！" << std::endl;
            Sleep(1000);
        }
        else
        {
            
            char ch;
            int kind = -1;
            int num=-1;
            while (true) { //获取选择并判断输入是否正确
                showShopEgg(player);
                std::cout << "请输入你要购买的种类：" << std::endl;
                cout << "按回车后继续...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                kind = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;

                if (kind > 0 && kind <= 3) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                Sleep(1000);
            }
            
            while (true) {//判断背包容量是否足够
                showShopEgg(player);
                std::cout <<"你选择了"<< EGGNAME[kind-1] << "，请输入你要购买的数量：" << std::endl;
                cout << "按回车后继续...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                num = ch - 48;

                if (num > 0 && num+player->getBag()->getNowEggSize()<= player->getBag()->getEggCapacity()) {
                    break;
                }
                
                cout << "输入错误/背包容量不足！\n";
                Sleep(1000);
                cout << "请重新输入：\n";
                Sleep(500);
            }
            
            if (player->getMoney() < EGGPRICE[kind - 1] * num) { //判断金币是否足够
                std::cout << "金币不足！" << std::endl;
                Sleep(1000);
            }
            else {
                player->setMoney(player->getMoney() - EGGPRICE[kind - 1] * num);
                for (int i = 0; i < num; i++) //根据输入创建蛋对象
                {
                    Egg * egg = new Egg(kind);
                    player->getBag()->addEgg(egg);
                }
                cout << "成功购买" << num << "个" << EGGNAME[kind - 1] << "!" << std::endl;
                Sleep(1000);
            }
            
        }
        shop(player);
        break;
    case 2:
        for (int i = 0; i < player->getBag()->getNowSize(); i++) //判断宠物HP是否需要回复
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife())
            {
                k = 1;
            }
        }
        if (k == 0) {
            std::cout << "所有宠物HP均无需回复！" << std::endl;
            Sleep(1000);
        }
            
        else
        {
            if (player->getMoney() < HPPRICE) { //判断金币是否足够
                std::cout << "金币不足！" << std::endl;
                Sleep(1000);
            }
            else {
                player->setMoney(player->getMoney() - HPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //回复所有宠物HP
                {
                    player->getBag()->getPetByIndex(i)->setNowLife(player->getBag()->getPetByIndex(i)->getLife());
                }
                std::cout << "所有宠物HP均已回复！" << std::endl;
                Sleep(1000);
            }
        }
        shop(player);
        break;
    case 3:

        for (int i = 0; i < player->getBag()->getNowSize(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowPP() < player->getBag()->getPetByIndex(i)->getPP()) //判断宠物PP是否需要回复
            {
                m = 1;
            }
        }
        if (m == 0) {
            std::cout << "所有宠物PP均无需回复！" << std::endl;
            Sleep(1000);
        }
            
        else
        {
            if (player->getMoney() < PPPRICE) { // 判断金币是否足够
                std::cout << "金币不足！" << std::endl;
                Sleep(1000);
            }
            else {
                player->setMoney(player->getMoney() - PPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //回复所有宠物PP
                {
                    player->getBag()->getPetByIndex(i)->setNowPP(player->getBag()->getPetByIndex(i)->getPP());
                }
                std::cout << "所有宠物PP均已回复！" << std::endl;
                Sleep(1000);
            }
        }
        shop(player);
        break;
    default:
        std::cout << "报错。" << std::endl;
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
        for (int i = 0; i < 6; i++) { //展示地图
            if (i != pos) {
                switch (i) {
                case 0:
                    oss << j << ". " << MAP[i] << "(金)" << endl;
                    c->changeTextColor('Y', oss);
                    k[j++] = i;
                    break;
                case 1:
                    oss << j << ". " << MAP[i] << "(木)" << endl;
                    c->changeTextColor('G', oss);
                    k[j++] = i;
                    break;
                case 2:
                    oss << j << ". " << MAP[i] << "(水)" << endl;
                    c->changeTextColor('B', oss);
                    k[j++] = i;
                    break;
                case 3:
                    oss << j << ". " << MAP[i] << "(火)" << endl;
                    c->changeTextColor('R', oss);
                    k[j++] = i;
                    break;
                case 4:
                    oss << j << ". " << MAP[i] << "(土)" << endl;
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
        cout << "请选择你要切换的地图：" << endl;
        cout << "按回车后选择...";
        if (getchar() != '\n')
            while (true)if (getchar() == '\n')break;
        ch = getchar(); // 获取地图选择
        mapchoice = ch - 48;
        if (ch != '\n')
            while (true)if (getchar() == '\n')break;

        if (mapchoice > 0 && mapchoice < 6) {
            break;
        }
        cout << "请输入正确的选项！\n";
        Sleep(1000);
    }
    player.setPos(k[mapchoice]);
}

void Command::newshow() {
    system("cls");
    showMenu();
    oss << "************************************************************\n"
        << "* *欢迎来到《五行大陆》MUD游戏 * *\n"
        << "************************************************************" << endl;
    c->changeTextColor('Y', oss);
    cout << endl;
    cout << "几天前，一个神秘的力量席卷了整个大陆，大陆上的的宠物都发生了变异，掌握了五行之力。\n作为王国的勇士，你决定去调查这股神秘力量的来源，于是，你踏上了旅程......" << endl;
    cout << "请选择：" << endl;
    cout << "1.新游戏\n" << "2.继续游戏" << endl;
}
void showMapColor(int pos) {
    switch (pos) {
        case 0:
            oss << "目前所在地图：" << MAP[pos] << "(金)" << endl;
            c->changeTextColor('Y', oss);
            break;
        case 1:
            oss << "目前所在地图：" << MAP[pos] << "(木)" << endl;
            c->changeTextColor('G', oss);
            break;
        case 2:
            oss << "目前所在地图：" << MAP[pos] << "(水)" << endl;
            c->changeTextColor('B', oss);
            break;
        case 3:
            oss << "目前所在地图：" << MAP[pos] << "(火)" << endl;
            c->changeTextColor('R', oss);
            break;
        case 4:
            oss << "目前所在地图：" << MAP[pos] << "(土)" << endl;
            c->changeTextColor('O', oss);
            break;
        case 5:
            oss << "目前所在地图：" << MAP[pos] << endl;            
            c->changeTextColor('W', oss);
            break;
    }
}
void Command::showChoice(int pos) {
    system("cls");
    showMapColor(pos);
    cout << "1. 切换地图（属性克制：金->木->水->火->土->金->...）" << endl;
    cout << "2. 商店" << endl;
    cout << "3. 仓库" << endl;
    cout << "4. 挑战隐藏Boss(或它的小喽啰)" << endl;
    cout << "5. (保存数据并)退出游戏" << endl;
}
void Command::showMapChoice(int pos) {
    system("cls");
    showMapColor(pos);
    cout << "1. 切换地图（属性克制：金->木->水->火->土->金->...）" << endl;
    cout << "2. 战斗升级或捕捉宠物" << endl;
    cout << "3. (保存数据并)退出游戏" << endl;
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
            while (true)if (getchar() == '\n')break; //判断输入是否正确
        if (iscontinue > 0 && iscontinue <= 2) {
            break;
        }
        cout << "请输入正确的选项！\n";
        Sleep(1000);
    }

    if (!(iscontinue - 1))
    {
        string name;
        cout << "请输入你的昵称：" << endl;
        std::cin >> name; //获取玩家昵称
        player->setName(name);

        std::cout << "请选择你的初始宠物：" << std::endl;
        std::cout << "1." << PETLIST[0] << "  2." << PETLIST[1] << "  3." << PETLIST[2]
            << "  4." << PETLIST[3] << "  5." << PETLIST[4] << std::endl;
        char ch;
        int  petnum = -1;
        int round = 0;
        while (true) {
            system("cls");
            std::cout << "请选择你的初始宠物：" << std::endl;
            std::cout << "1." << PETLIST[0] << "  2." << PETLIST[1] << "  3." << PETLIST[2]
                << "  4." << PETLIST[3] << "  5." << PETLIST[4] << std::endl;
            if (round)cout << "按回车后继续选择...\n";
            if(getchar() != '\n')
                while (true)if (getchar() == '\n')break;
            ch = getchar(); //获取宠物选择
            petnum = ch - 48;
            if (ch != '\n')
                while (true)if (getchar() == '\n')break;

            if (petnum > 0 && petnum <= 5 ) {
                break;
            }
            cout << "请输入正确的选项！\n";
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
                cout << "按回车后继续选择...\n";
                if (getchar() != '\n')
                   while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if(ch!='\n')
                    while (true)if (getchar() == '\n')break; //判断输入是否正确
                if (choice > 0 && choice <= 5) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                Sleep(1000);
                
                
            }
            
            switch (choice) {
            case 1:
                changeMap(pos, *player); //切换地图
                continue;
            case 2:
                shop(player); //进入商店
                break;
            case 4:
                battle = new Battle(*player); //创建新战斗
                break;
            case 5:
                saveGameData(player, house, filename); //保存游戏
                isplay = false;
                break;
            case 3:
                House(player,house);
                break;
            default:
                cout << "输入无效请重新输入！！！" << endl;
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
            
            while (true) {//判断输入是否正确
                showMapChoice(pos);
                cout<<"按回车后继续选择...";
                if (getchar() != '\n')
                    while (true)if (getchar() == '\n')break;
                ch = getchar();
                choice = ch - 48;
                if (ch != '\n')
                    while (true)if (getchar() == '\n')break;
                
                if (choice > 0 && choice <= 3) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                round++;
                Sleep(1000);
            }
            switch (choice) {
            case 1:
                changeMap(pos, *player); //切换地图
                continue;
            case 2:
                
                for (int i = 0; i < player->getBag()->getNowSize(); i++) {
                    if (player->getBag()->getPetByIndex(i)->getNowLife() > 0)k = 1;
                }
                if (k)
                    battle = new Battle(*player); //创建新战斗
                else
                    cout << "宠物全部阵亡，请带宠物到商店回复HP/PP值！\n";
                Sleep(1000);
                break;
            case 3:
                saveGameData(player, house, filename); //保存游戏存档
                isplay = false;
                break;
            default:
                cout << "退出报错。" << endl;
                break;
            }
            break;
        default:
            cout << "地图切换报错。" << endl;
            break;
        }
    }

}
void Command::clearCin()
{
    //清除缓冲区的出错信息
    cin.clear();
    //清除缓冲区的无效残留信息

    // numeric_limits<streamsize>::max() 返回输入缓冲的大小。
    // ignore 函数在此将把输入流中的数据清空。
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    //system("pause");
    //system("cls");

}