#pragma once
#ifndef __CONSTTABLE_H__
#define __CONSTTABLE_H__

const int PETLISTCOUNT = 10;//���������Ŀ
const int MAXPETLEVEL = 20;//�������ȼ�
const std::string PETLIST[PETLISTCOUNT] = { "�ƽ���","Գ��","Сˮ��","����ʨ","������" ,
											"�����" ,"������","����" ,"����ţ" ,"ɳ����"
};	//��������
const int INITPETLIFE[PETLISTCOUNT] = { 100 , 150,100,120,100,90,80,150,110,200 };	//����
const int INITPETPP[PETLISTCOUNT] = { 50 , 75,50,60,50,45,40,75,55,100 };	//pp
const int INITPETPOWER[PETLISTCOUNT] = { 50,40 ,45,40,45,40,65,30,60,50 };	//������
const int INITPETPROTECT[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20 };	//������
const int INITPETMONEY[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20 };	//��Ǯ
const int INITPETELEMENT[PETLISTCOUNT] = { 0,1,2,3,4,0,1,2,3,4};	
const int ELEMENTCOUNT = 5;														//Ԫ�ظ���
const std::string ELEMENT[ELEMENTCOUNT] = {"��","ľ", "ˮ", "��", "��" };
const int EGGKINDCOUNT = 3;													//��׽������
const std::string EGGNAME[EGGKINDCOUNT] = { "��ͨ��","��Ӣ��", "��ʦ��"};
const double EGGPROBABILITY[EGGKINDCOUNT] = { 0.5,0.8,1};					//��׽����
const int EGGPRICE[EGGKINDCOUNT] = { 10,25,50 };
const int MAXPETCOUNT = 2;													//��������
const int HPPRICE = 10;
const int PPPRICE = 20;
const int CAPACITY = 4;



#endif // !__CONSTTABLE_H__