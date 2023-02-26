#pragma once


class Player;
class Field;

class Game
{
public:
	Game() : _player(nullptr), _field(nullptr)
	{

	}
	virtual ~Game()
	{
		if(_player != nullptr)
			delete _player;
	}

	void Init();
	void Update();

	void CreatePlayer();
private:
	Player* _player;
	Field* _field;
};

