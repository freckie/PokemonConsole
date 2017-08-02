#pragma once

#include"Pokemon.h"
#include"Skill.h"

/*
	Type = Fire
	Name = "파이리", "리자드", "리자몽"
*/

class Fire1 : public Pokemon
{
public:
	Fire1();
	~Fire1();

	void setSkill();	//스킬 설정.
};

