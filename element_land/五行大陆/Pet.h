#pragma once
#ifndef _PET_H
#define _PET_H
#include <string>
class Pet
{
public:
	Pet();
	Pet(std::string name,int life,
		int power, int exp, int protectPower,
		int level, int money);
	~Pet();
	std::string getName();
	void setName(std::string name);
	int getLife()const;
	void setLife(int life);
	int getPower()const;
	void setPower(int power);
	int getProtectPower()const;
	void setProtectPower(int protectPower);
	int getExp()const;
	virtual void setExp(int exp);//���þ���
	int getLevel()const;
	void setLevel(int level);
	int getMoney()const;
	void setMoney(int money);
	void showInfo();//��ӡ����
	void initRevive(int life, int energy);//ս���������ص�ս��ǰ״̬��
	void getMaxLife()const;//��ȡ�������ֵ
	void restoreSkillPP();//�ָ�����ʹ�ô���

private:
	string name;
	int life;//����ֵ
	int power;//������
	int protectPower;//����
	int exp;//����
	int level;//�ȼ�
	int money;//��Ǯ
};
#endif // !__PET_H__