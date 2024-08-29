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
	virtual void setExp(int exp);//设置经验
	int getLevel()const;
	void setLevel(int level);
	int getMoney()const;
	void setMoney(int money);
	void showInfo();//打印属性
	void initRevive(int life, int energy);//战斗致死，回到战斗前状态。
	void getMaxLife()const;//获取最大生命值
	void restoreSkillPP();//恢复技能使用次数

private:
	string name;
	int life;//生命值
	int power;//攻击力
	int protectPower;//护甲
	int exp;//经验
	int level;//等级
	int money;//金钱
};
#endif // !__PET_H__