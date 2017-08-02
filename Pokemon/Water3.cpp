#include "Water3.h"

Water3::Water3()
{
	__evol_names[0] = "잉어킹";
	__evol_names[1] = "갸라도스";
	__evol_names[2] = "메가갸라도스";
	__evol_price[0] = 350;
	__evol_price[1] = 720;
	__evol_price[2] = 1250;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Water;
	pokemonid = PokemonID::water3;
	id = 230;

	setSkill();
}

Water3::~Water3()
{
}

void Water3::setSkill()
{
	Skill* sk1 = new Skill("거품광선", 70, 20);
	Skill* sk2 = new Skill("파도타기", 55, 92);
	Skill* sk3 = new Skill("하이드로펌프", 35, 190);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}