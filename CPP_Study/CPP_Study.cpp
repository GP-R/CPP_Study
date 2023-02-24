#include <iostream>
using namespace std;

class Player
{
public:
	virtual void move() { cout << "move" << endl; }
};

class Knight : public Player
{
public:
	virtual void move() override { cout << "Knight move" << endl; }
};
int main()
{
	Player p;
	p.move();

	Knight k;
	k.move();
	return 0;
}