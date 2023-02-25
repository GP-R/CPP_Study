#pragma once
#include"Player.h"

class Game
{
public:
	Game() : _player(nullptr)
	{

	}
	virtual ~Game()
	{
		delete _player;
	}

	void Init();
	void Update();

	void CreatePlayer();
private:
	Player* _player;
};

