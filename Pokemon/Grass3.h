#pragma once

#include"Pokemon.h"
#include"Skill.h"

/*
	Type = Grass
	Name = "아라리", "나시"
*/

class Grass3 : public Pokemon
{
public:
	Grass3();
	~Grass3();

	void setSkill();	//스킬 설정.
};

