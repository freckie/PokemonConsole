#include "Fire2.h"

Fire2::Fire2()
{
	__evol_names[0] = "����";
	__evol_names[1] = "����";
	__evol_names[2] = "����";
	__evol_price[0] = 300;
	__evol_price[1] = 600;
	__evol_price[2] = 1200;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Fire;
	pokemonid = PokemonID::fire2;
	id = 120;

	setSkill();
}

Fire2::~Fire2()
{
}

void Fire2::setSkill()
{
	Skill* sk1 = new Skill("�Ҳɼ���", 70, 20);
	Skill* sk2 = new Skill("�Ҵ빮��", 55, 95);
	Skill* sk3 = new Skill("ȭ�����", 27, 210);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}