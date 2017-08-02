#include "Water1.h"

Water1::Water1()
{
	__evol_names[0] = "꼬부기";
	__evol_names[1] = "어니부기";
	__evol_names[2] = "거북왕";
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
	Skill* sk1 = new Skill("물대포", 70, 20);
	Skill* sk2 = new Skill("물의 파동", 55, 90);
	Skill* sk3 = new Skill("하이드로펌프", 30, 200);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}