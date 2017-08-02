#include "Grass2.h"

Grass2::Grass2()
{
	__evol_names[0] = "�ѹ���";
	__evol_names[1] = "������";
	__evol_names[2] = "���÷��þ�";
	__evol_price[0] = 300;
	__evol_price[1] = 600;
	__evol_price[2] = 1000;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Grass;
	pokemonid = PokemonID::grass2;
	id = 320;

	setSkill();
}

Grass2::~Grass2()
{
}

void Grass2::setSkill()
{
	Skill* sk1 = new Skill("���鰡��", 90, 15);
	Skill* sk2 = new Skill("�ް��巹��", 68, 80);
	Skill* sk3 = new Skill("�ֶ��", 24, 220);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}