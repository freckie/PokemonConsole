#include "Fire3.h"

Fire3::Fire3()
{
	__evol_names[0] = "포니타";
	__evol_names[1] = "날쌩마";
	__evol_names[2] = "날쌩마";
	__evol_price[0] = 300;
	__evol_price[1] = 600;
	__evol_price[2] = 1200;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Fire;
	pokemonid = PokemonID::fire3;
	id = 130;

	setSkill();
}

Fire3::~Fire3()
{
}

void Fire3::setSkill()
{
	Skill* sk1 = new Skill("화염자동차", 70, 20);
	Skill* sk2 = new Skill("니트로차지", 55, 95);
	Skill* sk3 = new Skill("플레어드라이브", 29, 215);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}