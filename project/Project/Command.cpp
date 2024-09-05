#include "Command.h"
using namespace std;
void Command::showShop(){
    system("cls");
    std::cout << "欢迎来到商店！" << std::endl;
    std::cout << "1.购买宠物球  2.回复HP  3.回复PP" << std::endl;
    std::cout << "请选择(输入序号)：";
}
void Command::showShopEgg(Player* player) {
    system("cls");
    std::cout << "请输入你要购买的种类：" << std::endl;
    for (int i = 0; i < EGGKINDCOUNT; i++)cout << i + 1 << "." << EGGNAME[i] << "(捕捉概率" 
        << EGGPROBABILITY[i] << ")\t" << "价格：" << EGGPRICE[i] << endl;
    std::cout << "背包现有：\n";
    player->getBag()->EggshowInfo();
    cout << "你现在有：" << player->getMoney()<<endl;
}

void Command::shop(Player* player) {
    char ch;
    int choice=-1;
    while (true) { //获取选择并判断输入是否正确
        showShop();
        ch = getchar();
        choice = ch - 48;
        while (true)if (getchar() == '\n')break;
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
                ch = getchar();
                kind = ch - 48;
                while (true)if (getchar() == '\n')break;
                if (kind > 0 && kind <= 3) {
                    break;
                }
                cout << "请输入正确的选项！\n";
                Sleep(1000);
            }
            
            while (true) { //判断背包容量是否足够
                std::cout <<"你选择了"<< EGGNAME[kind-1] << "，请输入你要购买的数量：" << std::endl;
                ch = getchar();
                num = ch - 48;
                while (true)if (getchar() == '\n')break;
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
            }
            else {
                player->setMoney(player->getMoney() - EGGPRICE[kind - 1] * num);
                for (int i = 0; i < num; i++) //根据输入创建蛋对象
                {
                    Egg * egg = new Egg(kind);
                    player->getBag()->addEgg(egg);
                }
            }
            cout << "成功购买" << num << "个" << EGGNAME[kind - 1] << "!" << std::endl;
        }
        shop(player);
        break;
    case 2:
        for (int i = 1; i <= player->getBag()->getNowSize(); i++) //判断宠物HP是否需要回复
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife())
            {
                k = 1;
            }
        }
        if (k == 0)
            std::cout << "所有宠物HP均无需回复！" << std::endl;
        else
        {
            if (player->getMoney() < HPPRICE) { //判断金币是否足够
                std::cout << "金币不足！" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - HPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //回复所有宠物HP
                {
                    player->getBag()->getPetByIndex(i)->setNowLife(player->getBag()->getPetByIndex(i)->getLife());
                }
                std::cout << "所有宠物HP均已回复！" << std::endl;
            }
        }
        shop(player);
        break;
    case 3:

        for (int i = 1; i <= player->getBag()->getNowSize(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife()) //判断宠物PP是否需要回复
            {
                m = 1;
            }
        }
        if (m == 0)
            std::cout << "所有宠物PP均无需回复！" << std::endl;
        else
        {
            if (player->getMoney() < PPPRICE) { // 判断金币是否足够
                std::cout << "金币不足！" << std::endl;
            }
            else {
                player->setMoney(player->getMoney() - PPPRICE);
                for (int i = 0; i < player->getBag()->getNowSize(); i++) //回复所有宠物PP
                {
                    player->getBag()->getPetByIndex(i)->setNowPP(player->getBag()->getPetByIndex(i)->getPP());
                }
                std::cout << "所有宠物PP均已回复！" << std::endl;
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
    
    int k[6], j = 1;
    for (int i = 0; i < 6; i++) { //展示地图
        if (i != pos) {
            cout << j << ". " << MAP[i] << endl;
            k[j++] = i;
        }
    }

    char ch;
    int  mapchoice = -1;
    while (true) {
        cout << "请选择你要切换的地图：" << endl;
        ch = getchar(); // 获取地图选择
        mapchoice = ch - 48;
        while (true)if (getchar() == '\n')break; //判断输入是否正确
        if (mapchoice > 0 && mapchoice <= 6) {
            break;
        }
        cout << "请输入正确的选项！\n";
        Sleep(1000);
    }
    player.setPos(k[mapchoice]);
}

void Command::newshow() {
    system("cls");
    cout << "************************************************************\n"
        << " * *欢迎来到《五行大陆》MUD游戏 * *\n"
        << " * ***********************************************************" << endl;
    cout << "几天前，一个神秘的力量席卷了整个大陆，大陆上的的宠物都发生了变异，掌握了五行之力。\n作为王国的勇士，你决定去调查这股神秘力量的来源，于是，你踏上了旅程......" << endl;
    cout << "请选择：" << endl;
    cout << "1. 新游戏\n" << "2.继续游戏" << endl;
}
void Command::showChoice(int pos) {
    system("cls");
    cout << "目前所在地图：" << MAP[pos] << endl;
    cout << "1. 切换地图" << endl;
    cout << "2. 商店" << endl;
    cout << "3. 挑战隐藏Boss" << endl;
    cout << "4. 退出游戏" << endl;
}
void Command::showMapChoice(int pos) {
    system("cls");
    cout << "目前所在地图：" << MAP[pos] << endl;
    cout << "1. 切换地图" << endl;
    cout << "2. 战斗升级或捕捉宠物" << endl;
    cout << "3. 退出游戏" << endl;
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
        std::cout << "1.黄金兽  2.猿神  3.小水怪  4.烈焰狮  5.土拨鼠" << std::endl;
        char ch;
        int  petnum = -1;
        while (true) {
            //...
            getchar();
            ch = getchar(); //获取宠物选择
            petnum = ch - 48;
            while (true)if (getchar() == '\n')break;
            if (petnum > 0 && petnum <= 5 ) {
                break;
            }
            cout << "请输入正确的选项！\n";
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
                while (true)if (getchar() == '\n')break; //判断输入是否正确
                if (choice > 0 && choice <= 4) {
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
            case 3:
                battle = new Battle(*player); //创建新战斗
                battle->beginBattle();
                break;
            case 4:
                saveGameData(player, house, filename); //保存游戏
                break;
            default:
                cout << "输入无效请重新输入！！！" << endl;
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
                while (true)if (getchar() == '\n')break; //判断输入是否正确
                if (choice > 0 && choice <= 3) {
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
                battle = new Battle(*player); //创建新战斗
                battle->beginBattle();
                break;
            case 3:
                saveGameData(player, house, filename); //保存游戏存档
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