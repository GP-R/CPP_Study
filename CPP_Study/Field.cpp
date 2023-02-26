#include "Field.h"
#include <stdlib.h>
#include "Monster.h"
#include "Player.h"


void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();

	StartBattle(player);
}

void Field::CreateMonster()
{
	int randValue = rand() % 3;
	switch (randValue)
	{
	case MT_Slime :
		_monster = new Slime();
		break;
	case MT_Orc :
		_monster = new Orc();
		break;
	case MT_Skeleton :
		_monster = new Skeleton();
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		_monster->OnAttacked(player);
		_monster->PrintInfo();
		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}

		player->OnAttacked(_monster);
		player->PrintInfo();
		if (player->IsDead())
		{
			player->PrintInfo();
			break;
		}
	}
}

