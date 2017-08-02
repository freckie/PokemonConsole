#include "Legend2.h"

Legend2::Legend2()
{
	__evol_names[0] = "���̾�";
	__evol_names[1] = "���̾�";
	__evol_names[2] = "���̾�";
	__evol_price[0] = 1550;
	__evol_price[1] = 2800;
	__evol_price[2] = 4700;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Fire;
	pokemonid = PokemonID::legend2;
	id = 920;
	isLegend = true;

	setSkill();
}

Legend2::~Legend2()
{
}

void Legend2::setSkill()
{
	Skill* sk1 = new Skill("ȸ�����Ҳ�", 80, 35);
	Skill* sk2 = new Skill("�Ҵ빮��", 65, 120);
	Skill* sk3 = new Skill("�һ�", 40, 310);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}