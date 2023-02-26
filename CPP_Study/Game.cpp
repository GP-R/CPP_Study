#include "Game.h"
#include <iostream>
using namespace std;
#include"Player.h"
#include "Field.h"

void Game::Init()
{
	_field = new Field();
}

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();
	
	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}
	_field->Update(_player);
}

void Game::CreatePlayer()
{
	cout << "-----------------------" << endl;
	cout << "캐릭터를 선택해주세요" << endl;
	cout << "(1) 전사 (2) 궁수 (3) 법사" << endl;
	cout << "-----------------------" << endl;
	cout << "> ";

	int input;
	cin >> input;

	if (input == PT_Knight)
	{
		_player = new Knight();
	}
	else if (input == PT_Archer)
	{
		_player = new Archer();
	}
	else if (input == PT_Mage)
	{
		_player = new Mage();
	}
}
