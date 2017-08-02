#include "User.h"

User::User()
{
	name = "noname";
	pokenum = 0;
	for (int i = 0; i < 5; i++)
		poke[i] = nullptr;
	money = INIT_MONEY;

	nonamemon = new Pokemon(false); //임시 포켓몬
	mainMon = nonamemon;
}

User::User(string _name)
{
	name = _name;
	pokenum = 0;
	for (int i = 0; i < 5; i++)
		poke[i] = nullptr;
	money = INIT_MONEY;

	nonamemon = new Pokemon(false); //임시 포켓몬
	mainMon = nonamemon;
}

User::~User()
{
	delete nonamemon;
}

int User::getMoney()
{
	return money;
}

Pokemon* User::getMain()
{
	return mainMon;
}

Pokemon* User::getPoke(int _idx)
{
	return poke[_idx];
}

int User::getPokenum()
{
	return pokenum;
}

string User::getName()
{
	return name;
}

string User::getID()
{
	return id;
}

string User::getPW()
{
	return pw;
}

Inventory User::getInven()
{
	return inven;
}

void User::setName(string _name)
{
	name = _name;
}

void User::setMoney(int _money)
{
	if (_money >= MAX_MONEY)
		money = MAX_MONEY;
	else
		money = _money;
}

void User::addMoney(int _money)
{
	if (money + _money >= MAX_MONEY)
		money = MAX_MONEY;
	else
		money += _money;
}

void User::setPokenum(int _num)
{
	pokenum = _num;
}

void User::setMain(Pokemon& _mon)
{
	mainMon = &_mon;
}

void User::setID(string _id)
{
	id = _id;
}

void User::setPW(string _pw)
{
	pw = _pw;
}

void User::setInven(InvenType _inven, int _num)
{
	switch (_inven)
	{
	case InvenType::monster:
		inven.monster += _num;
		break;
	case InvenType::super:
		inven.super += _num;
		break;
	case InvenType::master:
		inven.master += _num;
		break;
	case InvenType::medic:
		inven.medic += _num;
		break;
	}
}

bool User::capture(Pokemon& _mon, Ball _ball)
{
	switch (_ball)
	{
	case Ball::Monster:
		inven.monster--;
		break;
	case Ball::Super:
		inven.super--;
		break;
	case Ball::Master:
		inven.master--;
		break;
	}

	if (_mon.capture(_ball) == true)
	{
		if (pokenum == 0)
		{
			addPokemon(_mon);
			mainMon = &_mon;
		}
		else if (pokenum == 6)
		{
			cout << "잡았으나 추가 불가. User::capture()" << endl;
		}
		else
			addPokemon(_mon);

		return true;
	}
	else
		return false;

}

void User::addPokemon(Pokemon& _mon)
{
	if (pokenum == 6)
	{
		cout << "추가 불가. User::addPokemon()" << endl;
		_getch();
	}

	else if (pokenum == 0)
	{
		poke[0] = &_mon;
		setMain(_mon);
		pokenum++;
	}
	else
	{
		for(int i=0; i<5; i++)
		{
			if (poke[i] == nullptr)
			{
				poke[i] = &_mon;
				break;
			}
		}
		pokenum++;
	}
}

void User::sellPokemon(int _idx)
{
	if (mainMon == poke[_idx])
	{
		cout << "대표 포켓몬은 팔 수 없음. User::sellPokemon()" << endl;
		return;
	}

	addMoney(poke[_idx]->getPrice());
	poke[_idx] = nullptr;
	pokenum--;
}