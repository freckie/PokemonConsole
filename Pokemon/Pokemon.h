#pragma once

/*
	Note:
		Pokemon Class names : pokemon.txt
*/


#include<string>
#include<iostream>
#include<ctime>
#include"SetUI.h"

class Skill; //Skill.h�� Skill ���� ����

#define LEVEL_MAX 100	//�ִ� ����

#define INIT_HP 30 //�ʱ� ü��

#define FACTOR_HPMAX 20 //�ִ�ü�� ���(level�� ����)
#define FACTOR_EXPMAX 50 //�ִ��ġ ���(level�� ����)

#define RATE_MONSTER 3 //���ͺ� Ȯ�� 30%
#define RATE_SUPER 6 //���ۺ� Ȯ�� 60%
#define RATE_MASTER 8 //�����ͺ� Ȯ�� 80%

#define EVOL_LEVEL1 20	//ù��° ��ȭ ����
#define EVOL_LEVEL2 50	//�ι�° ��ȭ ����

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
	string name;	//���ϸ� �̸�
	Type type;		//���ϸ� �Ӽ�
	int evol;		//��ȭ �ܰ�(1~3)
	int hp;			//ü��
	int hpmax;		//�ִ� ü�� (level*30)
	int level;		//����
	int exp;		//���� ����ġ
	int expmax;		//�ִ� ����ġ
	int price;		//���� ����
	bool isDie;		//���� �׾�����
	int id;			//���ϸ� ������ȣ
	PokemonID pokemonid; //���ϸ� enum��ȣ
	int prob;		//���ϸ� �߰� Ȯ��(1~10)
	bool isLegend = false;

	string __evol_names[3];	//��ȭ�ܰ躰 �̸�.
	int __evol_price[3];	//��ȭ�ܰ躰 ���� ����.

public:
	Skill *skill[3];

	Pokemon();
	Pokemon(bool _isTemp); //�ӽ����ϸ�����.
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

	void heal(int _heal);	//ü��ȸ��
	void incExpVal(int _val);	//����ġ ��ġ ����
	void incExpProp(int _prop);	//������ŭ ����ġ ����
	bool capture(Ball _ball);	//���� ���
	void levelup();
	bool evolution();	//��ȭ
};