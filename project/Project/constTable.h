#pragma once
#ifndef __CONSTTABLE_H__
#define __CONSTTABLE_H__
#include<string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
const int PETLISTCOUNT = 11;//宠物最大数目
const int MAXPETLEVEL = 20;//宠物最大等级
const int MAPCOUNT = 6; //地图数目
const std::string PETLIST[PETLISTCOUNT] = { "黄金兽","猿神","小水怪","烈焰狮","土拨鼠" ,
											"金刚狼" ,"花精灵","蓝鲸" ,"火云牛" ,"沙尘豹","五灵王"
};	//怪物名称
const int INITPETLIFE[PETLISTCOUNT] = { 300 , 450,300,360,300,270,240,450,330,600,1000 };	//体力
const int INITPETPP[PETLISTCOUNT] = { 50 , 75,50,60,50,45,40,75,55,100,0 };	//pp
const int INITPETPOWER[PETLISTCOUNT] = { 17,13 ,15,13,15,13,22,10,20,17,100 };	//攻击力
const int INITPETPROTECT[PETLISTCOUNT] = { 150 , 250,100,240,300,240,150,150,210,600,500 };	//防御力
const int INITPETMONEY[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20,1000 };	//金钱
const int INITPETELEMENT[PETLISTCOUNT] = { 0,1,2,3,4,0,1,2,3,4,5 };
const int SKILLCOUNT[PETLISTCOUNT] = { 4,4,4,4,4,4,4,4,4,4,4 };		//技能个数
const int SKILLALLCOUNT = 44;
const std::string SKILLNAME[SKILLALLCOUNT] = { "钢铁撕咬","铜墙铁壁","黄金冲撞","点石成金",
"叶刃拳","寄生种子","春眠掌","森罗万象","急速水弹","水淹七军","混乱洪流","水神祝福",
"烈焰嘶吼","熊熊烈火","舍身一击","火神祝福","嘴下留情","逃之夭夭","撕咬","土盾",
"钢铁爪牙","铜墙铁壁","黄金冲撞","硬化","叶刃拳","寄生种子","生命长河","森罗万象",
"急速水弹","水淹七军","灭世洪流","水神祝福","烈焰冲撞","熊熊烈火","舍身一击","火云邪神",
"飞沙走石","沙之壁垒", "撕咬","沙尘暴","天崩地裂","寒冰王冠","自然力量","金戈尤在" };				//技能名称
const int SKILLunavoidable[SKILLALLCOUNT] = { //追踪 无法闪避的伤害
	0,0,0,20,  0,0,0,20,0,0,0,30,0,0,0,20,0,0,0,40,0,30,0,0,
	0,0,0,0,   0,0,0,0, 0,0,0,0,    0,30,0,0,   100,0,0,0
};
const double SKILLunavoidablePERCENT[SKILLALLCOUNT] = { //追踪百分比 百分比伤害
	0,0,0,0,   0,0.17,0,0, 0,0.14,0,0,    0,0.17,0,0,   -0.2,0,0,0,     0,0,0,0,
	0,0.17,0,0,   0,0.14,0,0, 0,0.17,0,0,    0,0,0,0,   0.2,0,0,0
};
const int SKILLavoidable[SKILLALLCOUNT] = { //真伤 
	120,0,0,0,    100,0,150,0,          100,0,250,0,           100,0,200,0,        100,0,150,0,      100,0,80,0,
	100,0,80,0,    100,0,300,0,          120,0,200,0,           120,0,150,200,        0,0,0,0
};
const double SKILLavoidablePERCENT[SKILLALLCOUNT] = { //真伤百分比 
	0,0.1,0,0,    0,0,0,0,          0,0.1,0,0,           0,0,0,0,        0,0.1,0,0,      0,0,0,0.1,
	0,0,0,0.1,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0,0,0
};
const bool SKILLpowerKEY[SKILLALLCOUNT] = { //攻击key 是否增加攻击力
	0,0,1,0,    0,0,0,0,          0,0,0,1,           0,0,0,1,        0,0,0,0,      0,0,1,0,
	0,0,0,0,    0,0,0,1,          0,0,0,1,           0,0,0,0,        0,0,0,1
};
const double SKILLpowerBUFF[SKILLALLCOUNT] = { //攻击 增加的攻击力百分比
	0,0,0.25,0,    0,0,0,0,          0,0,0,0.3,           0,0,0,0.3,        0,0,0,0,      0,0,0.2,0,
	0,0,0,0,    0,0,0,0.3,          0,0,0,1.0,           0,0,0,0,        0,0,0,0.5
};
const bool SKILLprotectpowerKEY[SKILLALLCOUNT] = { //防御key 是否增加攻击力
	0,1,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0,0,1,      0,1,0,0,
	0,0,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,1,0,0
};
const double SKILLprotectpowerBUFF[SKILLALLCOUNT] = { //防御 增加的防御百分比
	0,0.3,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0,0,0.3,      0,0.3,0,0,
	0,0,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0.5,0,0
};
const bool SKILLhpKEY[SKILLALLCOUNT] = { //HPkey 是否增加HP
	0,0,0,0,    0,0,0,1,          0,0,1,0,           0,0,1,0,        0,0,0,0,      0,0,0,1,
	0,0,1,1,    0,0,1,0,          0,0,1,1,           0,1,0,1,        0,0,1,1
};
const int SKILLhp[SKILLALLCOUNT] = { //HP 增加的HP
	0,0,0,0,    0,0,0,0,          0,0,-250,0,           0,0,0,0,        0,0,0,0,      0,0,0,100,
	0,0,50,0,    0,0,-300,0,          0,0,0,0,           0,0,0,-100,        0,0,0,0
};
const double SKILLhpPERCENT[SKILLALLCOUNT] = { //HP百分比  增加的HP百分比
	0,0,0,0,    0,0,0,0.25,          0,0,0,0,           0,0,-0.5,0,        0,0,0,0,      0,0,0,0,
	0,0,0,0.25,    0,0,0,0,          0,0,-0.5,-0.5,           0,0.2,0,0,        0,0,0.2,0.1
};
const int SKILLppCONSUME[SKILLALLCOUNT] = { //PP消耗
	10,5,5,5,    5,5,12,5,      5,5,1,5,    5,5,5,5,       10,5,5,5,       10,5,5,5,
	10,5,5,5,    5,5,1,5,       5,5,5,5,    10,5,5,1,     1,1,1,1
};
const int SKILLround[SKILLALLCOUNT] = { //回合 技能持续的回合
	1,1,1,1,    1,3,1,4,          1,5,1,1,           1,3,1,1,        1,1,1,1,      1,1,1,1,
	1,3,1,4,    1,5,1,1,          1,3,1,1,           1,1,1,1,        2,1,1,1
};
const bool SKILLlifeKEY[SKILLALLCOUNT] = { //保命key 是否至少保留1hp
	0,0,0,0,    0,0,0,0,          0,0,1,0,           0,0,1,0,        0,0,1,0,      0,0,0,0,
	0,0,0,0,    0,0,0,0,          0,0,1,1,           0,0,0,0,        0,0,0,0
};
const bool SKILLmissKEY[SKILLALLCOUNT] = { //misskey 是否闪避
	0,0,0,1,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,1,0,0,      0,0,0,1,
	0,0,0,0,    0,0,0,0,          0,0,0,0,           0,1,0,0,        0,1,1,0
};

const int ELEMENTCOUNT = 5;														//元素个数
const std::string ELEMENT[ELEMENTCOUNT + 1] = { "金","木", "水", "火", "土" ,"五行" };
const std::string MAP[MAPCOUNT] = { "黄金之地", "精灵之森", "阳光海滩", "烈焰沙漠", "风暴沙漠", "主城" };
const int EGGKINDCOUNT = 3;													//捕捉蛋种类
const std::string EGGNAME[EGGKINDCOUNT] = { "普通球","精英球", "大师球" };
const double EGGPROBABILITY[EGGKINDCOUNT] = { 0.5,0.8,1 };					//捕捉概率
static bool catchPet(int eggkind) {
	int result = 0;
	int Yes = 0;
	int No = 1;
	unsigned seed = static_cast<unsigned>(time(NULL));
	switch (eggkind) {
	case 0:
		srand(seed);
		Yes = rand() % 2;
		if (Yes)result= 1;
		break;
	case 1:
		srand(seed);
		No = rand() % 5;
		if (!No)result = 1;
		break;
	case 2:
		result = 1;
	}
	return result;
}
const int MAXPETCOUNT = 2;//最大宠物数

const int CAPACITY = 4;//背包宠物容量
const int EGGCAPACITY = 10;//背包捕捉蛋容量

const int PPPRICE = 20;

const int EGGPRICE[EGGKINDCOUNT] = { 10,25,50 };
const int HOUSECAPACITY = 20;//仓库容量
const int HPPRICE = 10;
#endif // !__CONSTTABLE_H__