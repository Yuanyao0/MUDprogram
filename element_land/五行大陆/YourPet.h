#pragma once
#ifndef _YOURPET_H
#define _YOURPET_H
#include "Pet.h"

class yourPet :public Pet{
public:
	yourPet();
	yourPet(const Pet & pet);
	

	~yourPet();
	void showInfo()const;//��ӡ����
private:
	std::string name;
	int element;
	int nowPP;
	int life;//������ֵ
	int nowLife;//����ֵ
	int power;//������
	int protectPower;//����
	int level;//�ȼ�
	int PP;
	int skillCount;
	int aseed;
	std::vector<Skill*> Skills;//���＼��
};

#endif // !__YOURPET_H__