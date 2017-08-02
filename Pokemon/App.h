#pragma once

#include"User.h"
#include"PokemonClasses.h"
#include"Music.h"
#include"SetUI.h"
#include<iostream>
#include<fstream>
#include<conio.h>

#define ADMIN_ID "admin"
#define ADMIN_PW "administrator"

#define PROB_FIND 40 //포켓몬이 있는 풀숲 발견 확률
#define PROB_NONE 20 //포켓몬이 풀숲에 없을 확률
#define PROB_1 7 //진화1 포켓몬 발견 확률
//#define PROB_2 10 //진화2 포켓몬 발견 확률
//#define PROB_3 5 //진화3 포켓몬 발견 확률
#define PROB_L 4 //전설 포켓몬 발견 확률
#define PROB_36 25 //도망 성공할 확률

using namespace std;

// 운영자 : (admin / administrator)

struct LoginDB
{
	string id;
	string pw;
	string name;
	int money;
	int first;
};


class App
{
private:
	User user;
	bool isLogin = false;
	bool isAdmin = false;	//운영자권한
	bool isExit = false;
	//Music music;

public:
	Music music;
	LoginDB* ldb;
	int ldblen = 0;
	App();
	~App();

	void run();

	void loginMenu();
	void mainMenu();
	//void mainMenuAdmin();

	bool fieldMenu();	//main에서 선택1
	void pokeMenu();	//main에서 선택2
	void invenMenu();	//main에서 선택3
	void storeMenu();	//main에서 선택4
	void clinicMenu();	//main에서 선택5

	PokemonID fieldFind();	//야생에서 포켓몬 발견 함수

	void battleMenu(PokemonID _pid); //battle to capture
	bool captureMenu(Pokemon* _mon, double _hpprop);	//포획 메뉴(상대 체력 비율)
	void battleEnd(bool _win, bool _legend);	//전투 끝난 후.
	void sellMenu();	//포켓몬 판매 메뉴
};

