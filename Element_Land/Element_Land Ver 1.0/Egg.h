#pragma once
#ifndef _EGG_H
#define _EGG_H
#include <string>
class Egg {
public:
	Egg(int x);
	void setKind(int x);
	int getKind()const;
	std::string getName();
	double getProbability()const;

private:
	int kind;//				1--普通	2--精英 3--大师
};


#endif // !__EGG_H__