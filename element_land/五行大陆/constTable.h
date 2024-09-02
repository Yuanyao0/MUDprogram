#pragma once
#ifndef __CONSTTABLE_H__
#define __CONSTTABLE_H__

const int PETLISTCOUNT = 10;//宠物最大数目
const int MAXPETLEVEL = 20;//宠物最大等级
const std::string PETLIST[PETLISTCOUNT] = { "黄金兽","猿神","小水怪","烈焰狮","土拨鼠" ,
											"金刚狼" ,"花精灵","蓝鲸" ,"火云牛" ,"沙尘豹"
};	//怪物名称
const int INITPETLIFE[PETLISTCOUNT] = { 100 , 150,100,120,100,90,80,150,110,200 };	//体力
const int INITPETPP[PETLISTCOUNT] = { 50 , 75,50,60,50,45,40,75,55,100 };	//pp
const int INITPETPOWER[PETLISTCOUNT] = { 50,40 ,45,40,45,40,65,30,60,50 };	//攻击力
const int INITPETPROTECT[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20 };	//防御力
const int INITPETMONEY[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20 };	//金钱
const int INITPETELEMENT[PETLISTCOUNT] = { 0,1,2,3,4,0,1,2,3,4};	
const int ELEMENTCOUNT = 5;														//元素个数
const std::string ELEMENT[ELEMENTCOUNT] = {"金","木", "水", "火", "土" };
const int EGGKINDCOUNT = 3;													//捕捉蛋种类
const std::string EGGNAME[EGGKINDCOUNT] = { "普通球","精英球", "大师球"};
const double EGGPROBABILITY[EGGKINDCOUNT] = { 0.5,0.8,1};					//捕捉概率
const int EGGPRICE[EGGKINDCOUNT] = { 10,25,50 };
const int MAXPETCOUNT = 2;													//最大宠物数
const int HPPRICE = 10;
const int PPPRICE = 20;
const int CAPACITY = 4;



#endif // !__CONSTTABLE_H__