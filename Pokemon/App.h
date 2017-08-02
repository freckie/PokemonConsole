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

#define PROB_FIND 40 //���ϸ��� �ִ� Ǯ�� �߰� Ȯ��
#define PROB_NONE 20 //���ϸ��� Ǯ���� ���� Ȯ��
#define PROB_1 7 //��ȭ1 ���ϸ� �߰� Ȯ��
//#define PROB_2 10 //��ȭ2 ���ϸ� �߰� Ȯ��
//#define PROB_3 5 //��ȭ3 ���ϸ� �߰� Ȯ��
#define PROB_L 4 //���� ���ϸ� �߰� Ȯ��
#define PROB_36 25 //���� ������ Ȯ��

using namespace std;

// ��� : (admin / administrator)

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
	bool isAdmin = false;	//��ڱ���
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

	bool fieldMenu();	//main���� ����1
	void pokeMenu();	//main���� ����2
	void invenMenu();	//main���� ����3
	void storeMenu();	//main���� ����4
	void clinicMenu();	//main���� ����5

	PokemonID fieldFind();	//�߻����� ���ϸ� �߰� �Լ�

	void battleMenu(PokemonID _pid); //battle to capture
	bool captureMenu(Pokemon* _mon, double _hpprop);	//��ȹ �޴�(��� ü�� ����)
	void battleEnd(bool _win, bool _legend);	//���� ���� ��.
	void sellMenu();	//���ϸ� �Ǹ� �޴�
};

