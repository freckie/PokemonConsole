#include "Fire1.h"

Fire1::Fire1()
{
	__evol_names[0] = "���̸�";
	__evol_names[1] = "���ڵ�";
	__evol_names[2] = "���ڸ�";
	__evol_price[0] = 300;
	__evol_price[1] = 600;
	__evol_price[2] = 1000;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Fire;
	pokemonid = PokemonID::fire1;
	id = 110;

	setSkill();
}

Fire1::~Fire1()
{
}

void Fire1::setSkill()
{
	Skill* sk1 = new Skill("������", 70, 20);
	Skill* sk2 = new Skill("�Ҳɼ���", 55, 90);
	Skill* sk3 = new Skill("ȸ�����Ҳ�", 30, 200);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}