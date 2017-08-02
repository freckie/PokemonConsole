#include "Water2.h"

Water2::Water2()
{
	__evol_names[0] = "°í¶óÆÄ´ö";
	__evol_names[1] = "°ñ´ö";
	__evol_names[2] = "°ñ´ö";
	__evol_price[0] = 300;
	__evol_price[1] = 650;
	__evol_price[2] = 1130;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Water;
	pokemonid = PokemonID::water2;
	id = 220;

	setSkill();
}

Water2::~Water2()
{
}

void Water2::setSkill()
{
	Skill* sk1 = new Skill("°ÅÇ°±¤¼±", 82, 25);
	Skill* sk2 = new Skill("ÇÏÀÌµå·ÎÆßÇÁ", 62, 84);
	Skill* sk3 = new Skill("ÆÄµµÅ¸±â", 34, 207);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}