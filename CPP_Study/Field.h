#pragma once
class Player;
class Monster;

class Field
{
public:
	Field() : _monster(nullptr)
	{

	}
	virtual ~Field()
	{
		if (_monster != nullptr)
			delete _monster;
	}

	void Update(Player* player);

	void CreateMonster();
	void StartBattle(Player* player);
private:
	Monster* _monster;
};

