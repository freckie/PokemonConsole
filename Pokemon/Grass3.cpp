#include "Grass3.h"

Grass3::Grass3()
{
	__evol_names[0] = "�ƶ�";
	__evol_names[1] = "����";
	__evol_names[2] = "����";
	__evol_price[0] = 270;
	__evol_price[1] = 650;
	__evol_price[2] = 1100;
	name = __evol_names[evol - 1];
	price = __evol_price[evol - 1];
	type = Type::Grass;
	pokemonid = PokemonID::grass3;
	id = 330;

	setSkill();
}

Grass3::~Grass3()
{
}

void Grass3::setSkill()
{
	Skill* sk1 = new Skill("�ָ��", 95, 10);
	Skill* sk2 = new Skill("������Ű�׽ý�", 65, 80);
	Skill* sk3 = new Skill("�ֶ��", 28, 210);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}