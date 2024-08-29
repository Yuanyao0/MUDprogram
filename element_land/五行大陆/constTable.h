#pragma once
#ifndef __CONSTTABLE_H__
#define __CONSTTABLE_H__
const int PETLISTCOUNT = 10;//宠物最大数目
const std::string PETLIST[PETLISTCOUNT] = { "黄金兽","猿神","小水怪","烈焰狮","土拨鼠" ,
											"金刚狼" ,"花精灵","蓝鲸" ,"火云牛" ,"沙尘豹"
													 };	//怪物名称
const int INITPETLIFE[PETLISTCOUNT] = {100 , 150,100,120,100,90,80,150,110,200};	//体力
const int INITPETPOWER[PETLISTCOUNT] = { 50,40 ,45,40,45,40,65,30,60,50};	//攻击力
const int INITPETPROTECT[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20};	//防御力
const int INITPETMONEY[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20 };	//金钱
const int INITPETEXP[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20 };	//经验
const int INITPETLEVEL[PETLISTCOUNT] = { 1,1,1,1,1,2,2,2,2,2};	//等级
const int ELEMENTCOUNT =5;														//元素个数
const int MAXPETCOUNT = 2;														//最大宠物数








#endif // !__CONSTTABLE_H__