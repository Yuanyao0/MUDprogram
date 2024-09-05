#pragma once
#ifndef __CONSTTABLE_H__
#define __CONSTTABLE_H__
#include<string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
const int PETLISTCOUNT = 11;//���������Ŀ
const int MAXPETLEVEL = 20;//�������ȼ�
const int MAPCOUNT = 6; //��ͼ��Ŀ
const std::string PETLIST[PETLISTCOUNT] = { "�ƽ���","Գ��","Сˮ��","����ʨ","������" ,
											"�����" ,"������","����" ,"����ţ" ,"ɳ����","������"
};	//��������
const int INITPETLIFE[PETLISTCOUNT] = { 300 , 450,300,360,300,270,240,450,330,600,1000 };	//����
const int INITPETPP[PETLISTCOUNT] = { 50 , 75,50,60,50,45,40,75,55,100,0 };	//pp
const int INITPETPOWER[PETLISTCOUNT] = { 17,13 ,15,13,15,13,22,10,20,17,100 };	//������
const int INITPETPROTECT[PETLISTCOUNT] = { 150 , 250,100,240,300,240,150,150,210,600,500 };	//������
const int INITPETMONEY[PETLISTCOUNT] = { 50 , 50,100,80,100,80,50,50,70,20,1000 };	//��Ǯ
const int INITPETELEMENT[PETLISTCOUNT] = { 0,1,2,3,4,0,1,2,3,4,5 };
const int SKILLCOUNT[PETLISTCOUNT] = { 4,4,4,4,4,4,4,4,4,4,4 };		//���ܸ���
const int SKILLALLCOUNT = 44;
const std::string SKILLNAME[SKILLALLCOUNT] = { "����˺ҧ","ͭǽ����","�ƽ��ײ","��ʯ�ɽ�",
"Ҷ��ȭ","��������","������","ɭ������","����ˮ��","ˮ���߾�","���Һ���","ˮ��ף��",
"����˻��","�����һ�","����һ��","����ף��","��������","��֮زز","˺ҧ","����",
"����צ��","ͭǽ����","�ƽ��ײ","Ӳ��","Ҷ��ȭ","��������","��������","ɭ������",
"����ˮ��","ˮ���߾�","��������","ˮ��ף��","�����ײ","�����һ�","����һ��","����а��",
"��ɳ��ʯ","ɳ֮����", "˺ҧ","ɳ����","�������","��������","��Ȼ����","�������" };				//��������
const int SKILLunavoidable[SKILLALLCOUNT] = { //׷�� �޷����ܵ��˺�
	0,0,0,20,  0,0,0,20,0,0,0,30,0,0,0,20,0,0,0,40,0,30,0,0,
	0,0,0,0,   0,0,0,0, 0,0,0,0,    0,30,0,0,   100,0,0,0
};
const double SKILLunavoidablePERCENT[SKILLALLCOUNT] = { //׷�ٰٷֱ� �ٷֱ��˺�
	0,0,0,0,   0,0.17,0,0, 0,0.14,0,0,    0,0.17,0,0,   -0.2,0,0,0,     0,0,0,0,
	0,0.17,0,0,   0,0.14,0,0, 0,0.17,0,0,    0,0,0,0,   0.2,0,0,0
};
const int SKILLavoidable[SKILLALLCOUNT] = { //���� 
	120,0,0,0,    100,0,150,0,          100,0,250,0,           100,0,200,0,        100,0,150,0,      100,0,80,0,
	100,0,80,0,    100,0,300,0,          120,0,200,0,           120,0,150,200,        0,0,0,0
};
const double SKILLavoidablePERCENT[SKILLALLCOUNT] = { //���˰ٷֱ� 
	0,0.1,0,0,    0,0,0,0,          0,0.1,0,0,           0,0,0,0,        0,0.1,0,0,      0,0,0,0.1,
	0,0,0,0.1,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0,0,0
};
const bool SKILLpowerKEY[SKILLALLCOUNT] = { //����key �Ƿ����ӹ�����
	0,0,1,0,    0,0,0,0,          0,0,0,1,           0,0,0,1,        0,0,0,0,      0,0,1,0,
	0,0,0,0,    0,0,0,1,          0,0,0,1,           0,0,0,0,        0,0,0,1
};
const double SKILLpowerBUFF[SKILLALLCOUNT] = { //���� ���ӵĹ������ٷֱ�
	0,0,0.25,0,    0,0,0,0,          0,0,0,0.3,           0,0,0,0.3,        0,0,0,0,      0,0,0.2,0,
	0,0,0,0,    0,0,0,0.3,          0,0,0,1.0,           0,0,0,0,        0,0,0,0.5
};
const bool SKILLprotectpowerKEY[SKILLALLCOUNT] = { //����key �Ƿ����ӹ�����
	0,1,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0,0,1,      0,1,0,0,
	0,0,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,1,0,0
};
const double SKILLprotectpowerBUFF[SKILLALLCOUNT] = { //���� ���ӵķ����ٷֱ�
	0,0.3,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0,0,0.3,      0,0.3,0,0,
	0,0,0,0,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,0.5,0,0
};
const bool SKILLhpKEY[SKILLALLCOUNT] = { //HPkey �Ƿ�����HP
	0,0,0,0,    0,0,0,1,          0,0,1,0,           0,0,1,0,        0,0,0,0,      0,0,0,1,
	0,0,1,1,    0,0,1,0,          0,0,1,1,           0,1,0,1,        0,0,1,1
};
const int SKILLhp[SKILLALLCOUNT] = { //HP ���ӵ�HP
	0,0,0,0,    0,0,0,0,          0,0,-250,0,           0,0,0,0,        0,0,0,0,      0,0,0,100,
	0,0,50,0,    0,0,-300,0,          0,0,0,0,           0,0,0,-100,        0,0,0,0
};
const double SKILLhpPERCENT[SKILLALLCOUNT] = { //HP�ٷֱ�  ���ӵ�HP�ٷֱ�
	0,0,0,0,    0,0,0,0.25,          0,0,0,0,           0,0,-0.5,0,        0,0,0,0,      0,0,0,0,
	0,0,0,0.25,    0,0,0,0,          0,0,-0.5,-0.5,           0,0.2,0,0,        0,0,0.2,0.1
};
const int SKILLppCONSUME[SKILLALLCOUNT] = { //PP����
	10,5,5,5,    5,5,12,5,      5,5,1,5,    5,5,5,5,       10,5,5,5,       10,5,5,5,
	10,5,5,5,    5,5,1,5,       5,5,5,5,    10,5,5,1,     1,1,1,1
};
const int SKILLround[SKILLALLCOUNT] = { //�غ� ���ܳ����Ļغ�
	1,1,1,1,    1,3,1,4,          1,5,1,1,           1,3,1,1,        1,1,1,1,      1,1,1,1,
	1,3,1,4,    1,5,1,1,          1,3,1,1,           1,1,1,1,        2,1,1,1
};
const bool SKILLlifeKEY[SKILLALLCOUNT] = { //����key �Ƿ����ٱ���1hp
	0,0,0,0,    0,0,0,0,          0,0,1,0,           0,0,1,0,        0,0,1,0,      0,0,0,0,
	0,0,0,0,    0,0,0,0,          0,0,1,1,           0,0,0,0,        0,0,0,0
};
const bool SKILLmissKEY[SKILLALLCOUNT] = { //misskey �Ƿ�����
	0,0,0,1,    0,0,0,0,          0,0,0,0,           0,0,0,0,        0,1,0,0,      0,0,0,1,
	0,0,0,0,    0,0,0,0,          0,0,0,0,           0,1,0,0,        0,1,1,0
};

const int ELEMENTCOUNT = 5;														//Ԫ�ظ���
const std::string ELEMENT[ELEMENTCOUNT + 1] = { "��","ľ", "ˮ", "��", "��" ,"����" };
const std::string MAP[MAPCOUNT] = { "�ƽ�֮��", "����֮ɭ", "���⺣̲", "����ɳĮ", "�籩ɳĮ", "����" };
const int EGGKINDCOUNT = 3;													//��׽������
const std::string EGGNAME[EGGKINDCOUNT] = { "��ͨ��","��Ӣ��", "��ʦ��" };
const double EGGPROBABILITY[EGGKINDCOUNT] = { 0.5,0.8,1 };					//��׽����
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
const int MAXPETCOUNT = 2;//��������

const int CAPACITY = 4;//������������
const int EGGCAPACITY = 10;//������׽������

const int PPPRICE = 20;

const int EGGPRICE[EGGKINDCOUNT] = { 10,25,50 };
const int HOUSECAPACITY = 20;//�ֿ�����
const int HPPRICE = 10;
#endif // !__CONSTTABLE_H__