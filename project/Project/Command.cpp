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

    switch (choice) { 
    case 1:
        int noweggsize = player->getBag()->getNowEggSize(), capacity = player->getBag()->getEggCapacity();

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
                for (int i = 0; i < num; i++)  //根据输入创建蛋对象
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
        int k = 0;
        for (int i = 1; i <= player->getBag()->getNowSize(); i++)
        {
            if (player->getBag()->getPetByIndex(i)->getNowLife() < player->getBag()->getPetByIndex(i)->getLife()) //判断宠物HP是否需要回复
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
        break;
    case 3:
        int m = 0;
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
            if (player->getMoney() < PPPRICE) {
               std::cout << "金币不足！" << std::endl; //判断金币是否足够
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
        break;
    default:
        std::cout << "无效的选择。" << std::endl;
        break;
    }

}

void Command::changeMap(int& pos, Player& player) {
    cout << "请选择你要切换的地图：" << endl;
    int k[6], j = 1;
    for (int i = 0; i < 6; i++) { //展示地图
        if (i != pos) {
            cout << j++ << ". " << MAP[i] << endl;
            k[j] = i;
        }
    }
    int mapchoice;
    cin >> mapchoice; //获取地图选择
    player.setPos(k[mapchoice]);
}
void Command::newGame()
{
    cout << "************************************************************\n" << " * *欢迎来到《五行大陆》MUD游戏 * *\n" << " * ***********************************************************" << endl;
    cout << "几天前，一个神秘的力量席卷了整个大陆，大陆上的的宠物都发生了变异，掌握了五行之力。\n作为王国的勇士，你决定去调查这股神秘力量的来源，于是，你踏上了旅程......" << endl;
    cout << "请选择：" << endl;
    cout << "1. 新游戏\n" << "2.继续游戏" << endl;
    int iscontinue;
    Player* player;
    cin >> iscontinue;
    if (!(iscontinue - 1))
    {
        string name;
        cout << "请输入你的昵称：" << endl;
        std::cin >> name; //获取玩家昵称
        Bag bag = Bag(CAPACITY);
        player = new Player(name, 5, 100, bag);
        std::cout << "请选择你的初始宠物：" << std::endl;
        std::cout << "1."<<PETLIST[0]<<"  2."<<PETLIST[1]<<"  3."<<PETLIST[2]<<"  4."<<PETLIST[3]<<"  5."<<PETLIST[4] << std::endl;
        int petnum;
        cin >> petnum; //获取宠物选择
        Pet* pet = new Pet(petnum - 1); //创建宠物对象
        player->getBag()->add(pet);
    }
    if (iscontinue - 1) {
        Player* player = new Player(); //创建玩家对象从而继承存档数据
        player = readGameData(); //读取玩家存档
    }
    while (1) {
        int pos = player->getPos(); //读取玩家下一步操作
        switch (pos) { //根据输入执行对应的操作
        case '5':
            cout << "目前所在地图：" << MAP[pos] << endl;
            cout << "1. 切换地图" << endl;
            cout << "2. 商店" << endl;
            cout << "3. 挑战隐藏Boss" << endl;
            cout << "4. 退出游戏" << endl;
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
                cout << "输入无效请重新输入！！！" << endl;
                break;
            }
            break;
        case '4':
        case '3':
        case '2':
        case '1':
        case '0':
            cout << "目前所在地图：" << MAP[pos] << endl;
            cout << "1. 切换地图" << endl;
            cout << "2. 战斗升级或捕捉宠物" << endl;
            cout << "3. 退出游戏" << endl;
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
                cout << "输入无效请重新输入！！！" << endl;
                break;
            }
            break;
        default:
            cout << "地图不存在！！！" << endl;
            break;
        }
    }

}