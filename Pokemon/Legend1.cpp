#include "Legend1.h"

Legend1::Legend1()
{
	__evol_names[0] = "½ã´õ";
	__evol_names[1] = "½ã´õ";
	__evol_names[2] = "½ã´õ";
	__evol_price[0] = 1700;
	__evol_price[1] = 3000;
	__evol_price[2] = 5100;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Light;
	pokemonid = PokemonID::legend1;
	id = 910;
	isLegend = true;

	setSkill();
}

Legend1::~Legend1()
{
}

void Legend1::setSkill()
{
	Skill* sk1 = new Skill("Àü±â¼îÅ©", 80, 40);
	Skill* sk2 = new Skill("¹ø°³", 65, 130);
	Skill* sk3 = new Skill("Àü±âÀÚ¼®ÆÄ", 42, 325);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}