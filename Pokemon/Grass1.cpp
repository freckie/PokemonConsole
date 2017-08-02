#include "Grass1.h"

Grass1::Grass1()
{
	__evol_names[0] = "¿ÃªÛ«ÿææ";
	__evol_names[1] = "¿ÃªÛ«ÿ«Æ";
	__evol_names[2] = "¿ÃªÛ«ÿ≤…";
	__evol_price[0] = 300;
	__evol_price[1] = 600;
	__evol_price[2] = 1000;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Grass;
	pokemonid = PokemonID::grass1;
	id = 310;

	setSkill();
}

Grass1::~Grass1()
{
}

void Grass1::setSkill()
{
	Skill* sk1 = new Skill("ææª—∏Æ±‚", 70, 20);
	Skill* sk2 = new Skill("µ¢±º√§¬Ô", 55, 90);
	Skill* sk3 = new Skill("¿Ÿ≥Ø∞°∏£±‚", 30, 200);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}