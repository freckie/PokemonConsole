#include "Pokemon.h"

Pokemon::Pokemon()
{
	srand((unsigned int)time(NULL));
	isDie = false;
	level = 1; evol = 1;
	setHpMax(); setExpMax();
	exp = 0; hp = hpmax;
	for (int i = 0; i < 3; i++)
		skill[i] = nullptr;
	type = Type::None;
}

Pokemon::Pokemon(bool _isTemp)
{
	Pokemon();
	name = "없음";
	level = 0;
	hp = 0; exp = 0;
	hpmax = 0; expmax = 0;
}

Pokemon::~Pokemon()
{
}

Pokemon::Pokemon(Pokemon& _mon)
{
	name = _mon.name;
	type = _mon.type;
	evol = _mon.evol;
	hp = _mon.hp;
	hpmax = _mon.hpmax;
	level = _mon.level;
	exp = _mon.exp;
	expmax = _mon.expmax;
	price = _mon.price;
	isDie = _mon.isDie;
	id = _mon.id;
	pokemonid = _mon.pokemonid;
	for (int i = 0; i < 3; i++)
	{
		__evol_names[i] = _mon.__evol_names[i];
		__evol_price[i] = _mon.__evol_price[i];
		skill[i] = _mon.skill[i];
	}
}

void Pokemon::setName(string _name)
{
	name = _name;
}

void Pokemon::setType(Type _type)
{
	type = _type;
}

void Pokemon::setEvol(int _evol)
{
	evol = _evol;
}

void Pokemon::setHP(int _hp)
{
	hp = _hp;
}

void Pokemon::setHpMax()
{
	hpmax = INIT_HP + level*FACTOR_HPMAX;
}

void Pokemon::setLevel(int _level)
{
	level = _level;
	if (_level <= 0)
		level = 5;
	setHpMax(); setExpMax();
	hp = hpmax;
}

void Pokemon::setExp(int _exp)
{
	exp = _exp;
}

void Pokemon::setExpMax()
{
	expmax = level*FACTOR_EXPMAX;
}

void Pokemon::setPrice()
{
	price = __evol_price[evol - 1];
}

void Pokemon::setDie(bool _die)
{
	isDie = _die;
}

string Pokemon::getName()
{
	return name;
}

Type Pokemon::getType()
{
	return type;
}

int Pokemon::getEvol()
{
	return evol;
}

int Pokemon::getHP()
{
	return hp;
}

int Pokemon::getHpMax()
{
	return hpmax;
}

int Pokemon::getLevel()
{
	return level;
}

int Pokemon::getExp()
{
	return exp;
}

int Pokemon::getExpMax()
{
	return expmax;
}

int Pokemon::getPrice()
{
	return price;
}

bool Pokemon::getDie()
{
	return isDie;
}

int Pokemon::getID()
{
	return id;
}

PokemonID Pokemon::getPokemonID()
{
	return pokemonid;
}

void Pokemon::printType()
{
	if(isLegend == true)
		coutColor("전설, ", 0x000D, 0, 0);

	switch (type)
	{
	case Type::Fire:
		coutColor("불", 0x000C, 0, 0);
		break;
	case Type::Grass:
		coutColor("풀", 0x000A, 0, 0);
		break;
	case Type::Water:
		coutColor("물", 0x000B, 0, 0);
		break;
	case Type::Light:
		coutColor("전기", 0x000E, 0, 0);
		break;
	case Type::None:
		cout << "없음";
		break;
	}
}

void Pokemon::heal(int _heal)
{
	if (hp + _heal >= hpmax)
		hp = hpmax;
	else
		hp += _heal;
}

void Pokemon::incExpVal(int _val)
{
	exp += _val;
	if (exp >= expmax)
		levelup();
}

void Pokemon::incExpProp(int _prop)
{
	int temp = (int)((_prop*0.01) * expmax);
	incExpVal(temp);
}

bool Pokemon::capture(Ball _ball)
{
	int temp = rand() % 10 + 1;

	switch (_ball)
	{
	case Ball::Monster:
		return (temp >= 1 && temp <= RATE_MONSTER);
	case Ball::Super:
		return (temp >= 1 && temp <= RATE_SUPER);
	case Ball::Master:
		return (temp >= 1 && temp <= RATE_MASTER);
	}
}

void Pokemon::levelup()
{
	level++;
	setHpMax();
	setExpMax();
	exp = 0;
	hp = hpmax;
}

bool Pokemon::evolution()
{
	if (evol == 1)
	{
		if (level >= EVOL_LEVEL1)
		{
			evol++;
			id++;
			setName(__evol_names[1]);
			setHpMax();
			hp = hpmax;
			return true;
		}
		else
			return false;
	}

	else if (evol == 2)
	{
		if (level >= EVOL_LEVEL2)
		{
			evol++;
			id++;
			setName(__evol_names[2]);
			setHpMax();
			hp = hpmax;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}