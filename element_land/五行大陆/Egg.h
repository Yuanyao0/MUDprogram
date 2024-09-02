#pragma once
#ifndef _EGG_H
#define _EGG_H
#include <string>
class Egg {
public:
	void setKind(int x);
	int getKind()const;
	std::string getName();
	double getProbability()const;

private:
	int kind;
};


#endif // !__EGG_H__