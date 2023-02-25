#pragma once

enum CreatureType {
	CT_Player = 0,
	CT_Monster = 1,

};
class Creature
{
public:
	Creature(int creatureType) : _creatureType(creatureType)
	{

	}

	virtual ~Creature()
	{

	}
protected:
	int _creatureType;
	int _hp = 0;
	int _attack = 0;
	int _defence = 0;
};

