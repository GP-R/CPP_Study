#include <iostream>
using namespace std;

enum PlayerType {
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType {
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo {
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void CreatePlayer();
void EnterGame(StatInfo& playerInfo);
int CreateMonsters(StatInfo& Monster);
void EnterBattle(StatInfo& playerInfo);
void PrintMsg(const char* msg);
int main()
{
	srand(unsigned(time(0)));
	EnterLobby();
    return 0;
}

void PrintMsg(const char* msg)
{
	cout << "**************************" << endl;
	cout << msg << endl;
	cout << "**************************" << endl;
}
void EnterLobby()
{
	while (true)
	{
		PrintMsg("로비에 입장했습니다");
		PrintMsg("(1) 플레이어 생성 (2) 게임 종료");
		cout << ">";

		int input;
		cin >> input;
		if (input == 1)
			CreatePlayer();
		else if (input == 2)
			break;
		else
			cout << "잘못된값 입력" << endl;
	}
}

void CreatePlayer()
{
	PrintMsg("플레이어를 선택해주세요");
	cout << "(1) 전사 (2) 궁수 (3) 마법사" << endl;
	cout << ">";
		
	int input;
	cin >> input;

	StatInfo playerInfo;

	if (input == PT_Knight)
	{
		playerInfo.hp = 200;
		playerInfo.attack = 10;
		playerInfo.defence = 5;
	}
	else if (input == PT_Archer)
	{
		playerInfo.hp = 150;
		playerInfo.attack = 12;
		playerInfo.defence = 4;
	}
	else if (input == PT_Mage)
	{
		playerInfo.hp = 130;
		playerInfo.attack = 15;
		playerInfo.defence = 3;
	}
	else
		cout << "잘못된 값 입력" << endl;

	EnterGame(playerInfo);
}

void EnterGame(StatInfo& playerInfo)
{
	while (true)
	{
		PrintMsg("게임에 입장했습니다!");
		cout << "(1) 필드로 (2) 로비로" << endl;
		cout << ">";

		int input;
		cin >> input;
		if (input == 1)
			EnterBattle(playerInfo);
		else if (input == 2)
			break;
		else
			cout << "잘못된 값 입력" << endl;
	}
}

void EnterBattle(StatInfo& playerInfo)
{
	PrintMsg("랜덤 몬스터 생성");
	StatInfo Monster;
	int MonsterType = CreateMonsters(Monster);
	if (MonsterType == MT_Slime)
		cout << "슬라임 등장" << "HP : " << Monster.hp << "Attack : " << Monster.attack <<"Def : " << Monster.defence << endl;
	else if (MonsterType == MT_Orc)
		cout << "오크 등장" << "HP : " << Monster.hp << "Attack : " << Monster.attack << "Def : " << Monster.defence << endl;
	else if (MonsterType == MT_Skeleton)
		cout << "스켈레톤 등장" << "HP : " << Monster.hp << "Attack : " << Monster.attack << "Def : " << Monster.defence << endl;
	
	cout << "(1) 전투 (2) 도망" << endl;
	cout << ">";

	int input;
	cin >> input;
	if (input == 1)
	{
		while (true)
		{
			cout << "Player HP: " << playerInfo.hp << endl;
			cout << "Monster HP: " << Monster.hp << endl;

			Monster.hp = Monster.hp - (playerInfo.attack - Monster.defence);
			if (Monster.hp < 0)
			{
				Monster.hp = 0;
				cout << "승리" << endl;
				return;
			}
			playerInfo.hp = playerInfo.hp - (Monster.attack - playerInfo.defence);
			if (playerInfo.hp < 0)
			{
				playerInfo.hp = 0;
				cout << "사망" << endl;
				return;
			}
		}
		
	}
	else if (input == 2)
	{
		return;
	}
}

int CreateMonsters(StatInfo& Monster)
{
	int randomNum = rand() % 3 + 1;
	if (randomNum == MT_Slime)
	{
		Monster.hp = 50;
		Monster.attack = 1;
		Monster.defence = 1;
	}
	else if (randomNum == MT_Orc)
	{
		Monster.hp = 70;
		Monster.attack = 2;
		Monster.defence = 1;
	}
	else if (randomNum == MT_Skeleton)
	{
		Monster.hp = 100;
		Monster.attack = 3;
		Monster.defence = 2;
	}

	return randomNum;
}