#pragma once

#include"Pokemon.h"
#include<conio.h>

#define INIT_MONEY 300	//�ʱ� �ڱ�
#define MAX_MONEY 1000000 //�ִ� �ڱ�

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
	int pokenum;	//������ �ִ� ���ϸ� ��
	Pokemon* mainMon; //��ǥ ���ϸ�
	string id;
	string pw;

	Pokemon* nonamemon; //�ӽ� ���ϸ�. �����ϸ� �����

public:
	Inventory inven;

	User();
	User(string _name);
	~User();

	int getMoney();
	Pokemon* getMain(); //��ǥ���ϸ� ����
	Pokemon* getPoke(int _idx);	//���ϸ� ����
	int getPokenum();
	string getName();
	string getID();
	string getPW();
	Inventory getInven();

	void setName(string _name);
	void setMoney(int _money);	//_money�� �� ����
	void addMoney(int _money);	//�� ���� �߰�
	void setMain(Pokemon& _mon);	//��ǥ���ϸ� ����
	void setPokenum(int _num);
	void setID(string _id);
	void setPW(string _pw);
	void setInven(InvenType _inven, int _num);	//�ش� ��

	bool capture(Pokemon& _mon, Ball _ball); //���ϸ� ���(pokemon::capture ȣ���ϱ�)

	void addPokemon(Pokemon& _mon); //���ϸ� �߰�
	void sellPokemon(int _idx);	//���ϸ� �ȱ�(���ϸ󰡹��� �ε���)
};

