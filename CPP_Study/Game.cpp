#include "Game.h"
#include <iostream>
using namespace std;


void Game::Init()
{
	
}

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();
	
	
}

void Game::CreatePlayer()
{
	cout << "-----------------------" << endl;
	cout << "ĳ���͸� �������ּ���" << endl;
	cout << "(1) ���� (2) �ü� (3) ����" << endl;
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
