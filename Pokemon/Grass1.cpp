#include "Grass1.h"

Grass1::Grass1()
{
	__evol_names[0] = "�̻��ؾ�";
	__evol_names[1] = "�̻���Ǯ";
	__evol_names[2] = "�̻��ز�";
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
	Skill* sk1 = new Skill("���Ѹ���", 70, 20);
	Skill* sk2 = new Skill("����ä��", 55, 90);
	Skill* sk3 = new Skill("�ٳ�������", 30, 200);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}