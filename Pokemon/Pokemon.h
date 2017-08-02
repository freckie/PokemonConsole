#pragma once

/*
	Note:
		Pokemon Class names : pokemon.txt
*/


#include<string>
#include<iostream>
#include<ctime>
#include"SetUI.h"

class Skill; //Skill.h의 Skill 전방 선언

#define LEVEL_MAX 100	//최대 레벨

#define INIT_HP 30 //초기 체력

#define FACTOR_HPMAX 20 //최대체력 계수(level에 곱함)
#define FACTOR_EXPMAX 50 //최대경치 계수(level에 곱함)

#define RATE_MONSTER 3 //몬스터볼 확률 30%
#define RATE_SUPER 6 //수퍼볼 확률 60%
#define RATE_MASTER 8 //마스터볼 확률 80%

#define EVOL_LEVEL1 20	//첫번째 진화 레벨
#define EVOL_LEVEL2 50	//두번째 진화 레벨

enum Type
{
	Fire, Water, Grass, Light, None
};

enum Ball
{
/*
	"Capturing Ball EnumType"
		MonsterBall : 40%
		SuperBall : 60%
		MasterBall : 80%
*/
	Monster, Super, Master
};

enum PokemonID
{
/*
	Note:
		This ID is for Random Pokemon Generating.
		'enum ID'.
*/
	fire1, water1, grass1, light1,
	fire2, water2, grass2,
	fire3, water3, grass3,
	legend1, legend2,
	none = 999
};

using namespace std;

/*
	Note:
		set '__evol_names, __evol_price'
			at Derived Class
*/

class Pokemon
{
protected:
	string name;	//포켓몬 이름
	Type type;		//포켓몬 속성
	int evol;		//진화 단계(1~3)
	int hp;			//체력
	int hpmax;		//최대 체력 (level*30)
	int level;		//레벨
	int exp;		//현재 경험치
	int expmax;		//최대 경험치
	int price;		//상점 가격
	bool isDie;		//몬스터 죽었는지
	int id;			//포켓몬 고유번호
	PokemonID pokemonid; //포켓몬 enum번호
	int prob;		//포켓몬 발견 확률(1~10)
	bool isLegend = false;

	string __evol_names[3];	//진화단계별 이름.
	int __evol_price[3];	//진화단계별 상점 가격.

public:
	Skill *skill[3];

	Pokemon();
	Pokemon(bool _isTemp); //임시포켓몬인지.
	Pokemon(Pokemon& _mon);
	~Pokemon();

	/* Get Set Functions */

	void setName(string _name);
	void setType(Type _type);
	void setEvol(int _evol);
	void setHP(int _hp);
	void setHpMax();
	void setLevel(int _level);
	void setExp(int _exp);
	void setExpMax();
	void setPrice();
	void setDie(bool _die);

	string getName();
	Type getType();
	int getEvol();
	int getHP();
	int getHpMax();
	int getLevel();
	int getExp();
	int getExpMax();
	int getPrice();
	bool getDie();
	int getID();
	PokemonID getPokemonID();

	void printType();

	/* Functions */

	void heal(int _heal);	//체력회복
	void incExpVal(int _val);	//경험치 수치 증가
	void incExpProp(int _prop);	//비율만큼 경험치 증가
	bool capture(Ball _ball);	//몬스터 잡기
	void levelup();
	bool evolution();	//진화
};