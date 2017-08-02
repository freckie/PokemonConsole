#pragma once

#include"Pokemon.h"
#include"Skill.h"

/*
	Type = Grass
	Name = "이상해씨", "이상해풀", "이상해꽃"
*/

class Grass1 : public Pokemon
{
public:
	Grass1();
	~Grass1();

	void setSkill();	//스킬 설정.
};

