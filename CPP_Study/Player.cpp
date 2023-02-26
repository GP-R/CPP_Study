#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "-------------------------" << endl;
	cout << "[Player Info] HP : " << _hp << "  ATK : " << _attack << "  DEF : " << _defence << endl;
	cout << "-------------------------" << endl;
}

