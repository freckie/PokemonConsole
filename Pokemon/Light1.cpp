#include "Light1.h"

Light1::Light1()
{
	__evol_names[0] = "««√Ú";
	__evol_names[1] = "««ƒ´√Ú";
	__evol_names[2] = "∂Û¿Ã√Ú";
	__evol_price[0] = 900;
	__evol_price[1] = 1700;
	__evol_price[2] = 2100;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Light;
	pokemonid = PokemonID::light1;
	id = 410;

	setSkill();
}

Light1::~Light1()
{
}

void Light1::setSkill()
{
	Skill* sk1 = new Skill("¿¸±‚ ºÓ≈©", 70, 25);
	Skill* sk2 = new Skill("¿¸±§ºÆ»≠", 55, 120);
	Skill* sk3 = new Skill("10∏∏ ∫º∆Æ", 25, 350);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}