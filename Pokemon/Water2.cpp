#include "Water2.h"

Water2::Water2()
{
	__evol_names[0] = "����Ĵ�";
	__evol_names[1] = "���";
	__evol_names[2] = "���";
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
	Skill* sk1 = new Skill("��ǰ����", 82, 25);
	Skill* sk2 = new Skill("���̵������", 62, 84);
	Skill* sk3 = new Skill("�ĵ�Ÿ��", 34, 207);
	skill[0] = sk1;
	skill[1] = sk2;
	skill[2] = sk3;
}