#include "Water1.h"

Water1::Water1()
{
	__evol_names[0] = "���α�";
	__evol_names[1] = "��Ϻα�";
	__evol_names[2] = "�źϿ�";
	__evol_price[0] = 300;
	__evol_price[1] = 600;
	__evol_price[2] = 1000;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Water;
	pokemonid = PokemonID::water1;
	id = 210;

	setSkill();
}

Water1::~Water1()
{
}

void Water1::setSkill()
{
	Skill* sk1 = new Skill("������", 70, 20);
	Skill* sk2 = new Skill("���� �ĵ�", 55, 90);
	Skill* sk3 = new Skill("���̵������", 30, 200);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}