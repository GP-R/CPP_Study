#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "-------------------------" << endl;
	cout << "[Monter Info] HP : " << _hp << "  ATK : " << _attack << "  DEF : " << _defence << endl;
	cout << "-------------------------" << endl;
}
