#pragma once

#include"Pokemon.h"
#include<conio.h>

#define INIT_MONEY 300	//초기 자금
#define MAX_MONEY 1000000 //최대 자금

/*
	Note:
		User MUST HAVE 1 Inventory.
		When print Inventory,
			do not print 0 item
*/

struct Inventory
{
	int medic = 0;
	int monster = 0;
	int super = 0;
	int master = 0;
};

enum InvenType
{
	medic, monster, super, master
};

/*
	Note:
		App MUST HAVE 1 User.
*/

class User
{
private:
	string name;
	int money;
	Pokemon* poke[6];
	int pokenum;	//가지고 있는 포켓몬 수
	Pokemon* mainMon; //대표 포켓몬
	string id;
	string pw;

	Pokemon* nonamemon; //임시 포켓몬. 시작하면 사라짐

public:
	Inventory inven;

	User();
	User(string _name);
	~User();

	int getMoney();
	Pokemon* getMain(); //대표포켓몬 리턴
	Pokemon* getPoke(int _idx);	//포켓몬 리턴
	int getPokenum();
	string getName();
	string getID();
	string getPW();
	Inventory getInven();

	void setName(string _name);
	void setMoney(int _money);	//_money로 돈 설정
	void addMoney(int _money);	//돈 일정 추가
	void setMain(Pokemon& _mon);	//대표포켓몬 설정
	void setPokenum(int _num);
	void setID(string _id);
	void setPW(string _pw);
	void setInven(InvenType _inven, int _num);	//해당 볼

	bool capture(Pokemon& _mon, Ball _ball); //포켓몬 잡기(pokemon::capture 호출하기)

	void addPokemon(Pokemon& _mon); //포켓몬 추가
	void sellPokemon(int _idx);	//포켓몬 팔기(포켓몬가방의 인덱스)
};

