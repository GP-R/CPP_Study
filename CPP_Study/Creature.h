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

	virtual void PrintInfo() = 0;

	void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; }
protected:
	int _creatureType;
	int _hp = 0;
	int _attack = 0;
	int _defence = 0;
};

