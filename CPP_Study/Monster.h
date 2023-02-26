#pragma once
#include "Creature.h"

enum MonsterType {
	MT_Slime = 0,
	MT_Orc = 1,
	MT_Skeleton = 2,
};
class Monster : public Creature
{
public:
	Monster(int monsterType) 
		: Creature(CT_Monster), _monsterType(monsterType)
	{

	}
	virtual ~Monster()
	{

	}
	virtual void PrintInfo() override;
protected:
	int _monsterType;
};

class Slime : public Monster {
public:
	Slime() : Monster(MT_Slime)
	{
		_hp = 50;
		_attack = 5;
		_defence = 3;
	}
	virtual ~Slime()
	{

	}
};

class Orc : public Monster {
public:
	Orc() : Monster(MT_Orc)
	{
		_hp = 70;
		_attack = 6;
		_defence = 4;
	}
	virtual ~Orc()
	{

	}
};

class Skeleton : public Monster {
public:
	Skeleton() : Monster(MT_Skeleton)
	{
		_hp = 100;
		_attack = 7;
		_defence = 5;
	}
	virtual ~Skeleton()
	{

	}
};
