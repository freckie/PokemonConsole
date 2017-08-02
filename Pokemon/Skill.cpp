#include "Skill.h"

Skill::Skill()
{
	srand((unsigned int)time(NULL));
	name = "noname skill";
	hitrate = 100;
	damage = 0;
}

Skill::Skill(string _name, int _hitrate, int _damage)
{
	srand((unsigned int)time(NULL));
	name = _name;
	hitrate = _hitrate;
	damage = _damage;
}

Skill::~Skill()
{
}

string Skill::getName()
{
	return name;
}

int Skill::getHitrate()
{
	return hitrate;
}

int Skill::getDamage()
{
	return damage;
}

void Skill::setName(string _name)
{
	name = _name;
}

void Skill::setHitrate(int _hitrate)
{
	hitrate = _hitrate;
}

void Skill::setDamage(int _damage)
{
	damage = _damage;
}

bool Skill::attack(Type _mytype, Pokemon* enemy)
{
	int temp = rand() % 100 + 1;
	int newDamage = damage + (int)damage*0.3;
	int enemyhp = enemy->getHP();

	// 상성 체크 :: 이기는 경우
	if ((_mytype == Type::Fire && enemy->getType() == Type::Grass) ||
		(_mytype == Type::Water && enemy->getType() == Type::Fire) ||
		(_mytype == Type::Grass && enemy->getType() == Type::Water))
	{
		newDamage = damage + (int)damage*0.3;
	}

	// 상성 체크 :: 지는 경우
	else if ((_mytype == Type::Fire && enemy->getType() == Type::Water) ||
		(_mytype == Type::Water && enemy->getType() == Type::Grass) ||
		(_mytype == Type::Grass && enemy->getType() == Type::Fire))
	{
		newDamage = damage - (int)damage*0.3;
	}

	// 상성 체크 :: 비기는 경우
	else
	{
		newDamage = damage;
	}

	// 명중률 체크
	if (temp >= 1 && temp <= hitrate)
	{
		if (enemyhp - newDamage > 0)
		{
			enemy->setHP(enemyhp - newDamage);
			enemy->setDie(false);
		}
		else
		{
			enemy->setHP(0);
			enemy->setDie(true);
		}
		return true;
	}
	else
		return false;
}
