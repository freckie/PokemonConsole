#pragma once

#include<string>
#include<ctime>
#include"Pokemon.h"

using namespace std;

class Skill
{
private:
	int hitrate;	//명중률
	int damage;		//공격력
	string name;	//스킬이름

public:
	Skill();
	Skill(string _name, int _hitrate, int _damage);
	~Skill();

	string getName();
	int getHitrate();
	int getDamage();

	void setName(string _name);
	void setHitrate(int _hitrate);
	void setDamage(int _damage);

	bool attack(Type _mytype, Pokemon* enemy);
};

