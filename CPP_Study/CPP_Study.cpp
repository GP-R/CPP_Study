#include <iostream>
using namespace std;

enum PlayerType {
    PT_Knight,
    PT_Archer,
    PT_Magician,
};

enum EnemyType {
    ET_Slime,
    ET_Orc,
    ET_Skeleton
};

struct ObjectInfo {
    int hp;
    int attack;
    int defence;
    int Type;
};

void EnterLobby();
void SelectCharacter();
void EnterField();
void FightEnemy();
void CreateRandomEnemy();

ObjectInfo Player;
ObjectInfo Enemy;

int main()
{
    srand(time(0));

    EnterLobby();
    return 0;
}

void EnterLobby()
{
    while (true)
    {
        cout << "------------------------" << endl;
        cout << "(1) 게임 입장 (2) 게임 종료" << endl;
        cout << "> ";
        int input;
        cin >> input;

        if (input == 1)
            SelectCharacter();
        else if (input == 2)
            return;
        else
            cout << "잘못된 값 입력" << endl;
    }
    
}

void SelectCharacter()
{
    while (true)
    {
        cout << "-----------------------------------" << endl;
        cout << "캐릭터를 선택해주세요" << endl;
        cout << "(1) 전사 (2) 궁수 (3) 법사" << endl;
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            Player.hp = 150;
            Player.attack = 7;
            Player.defence = 5;
            Player.Type = PlayerType::PT_Knight;
            break;
        case 2:
            Player.hp = 100;
            Player.attack = 10;
            Player.defence = 3;
            Player.Type = PlayerType::PT_Archer;
            break;
        case 3:
            Player.hp = 80;
            Player.attack = 13;
            Player.defence = 1;
            Player.Type = PlayerType::PT_Magician;
            break;
        default:
            cout << "잘못된값 입력" << endl;
            continue;
            break;
        }
        EnterField();
        break;
    }
    
}

void EnterField()
{
    while (true)
    {
        cout << "-----------------------------------" << endl;
        cout << "(1) 필드 입장 (2) 초기 화면으로" << endl;

        int input;
        cin >> input;
        if (input == 1)
            FightEnemy();
        else if (input == 2)
            return;
    }
    

}

void FightEnemy()
{
    CreateRandomEnemy();
    cout << "-----------------------------------" << endl;
    switch (Enemy.Type)
    {
    case 0:
        cout << "슬라임 등장" << endl;
        break;
    case 1:
        cout << "오크 등장" << endl;
        break;
    case 2:
        cout << "스켈레톤 등장" << endl;
        break;

    }
    cout << "--------------------------------" << endl;
    cout << "(1) 싸우기 (2) 도주하기" << endl;
    int input;
    cin >> input;
    if (input == 1)
    {
        while (true)
        {
            //선빵
            Enemy.hp = Enemy.hp - (Player.attack - Enemy.defence);
            if (Enemy.hp <= 0)
            {
                Enemy.hp = 0;
                cout << "승리" << endl;
                return;
            }

            Player.hp = Player.hp - (Enemy.attack - Player.defence);
            if (Player.hp <= 0)
            {
                Player.hp = 0;
                cout << "사망" << endl;
                return;
            }

            cout << "현재 Enemy 체력 : " << Enemy.hp << endl;
            cout << "현재 Player 체력 : " << Player.hp << endl;


        }
    }
    else if (input == 2)
        return;
}
    

void CreateRandomEnemy()
{
    int num = rand() % 3;
    switch (num)
    {
    case 0:
        Enemy.hp = 50;
        Enemy.attack = 2;
        Enemy.defence = 1;
        Enemy.Type = EnemyType::ET_Slime;
        break;
    case 1:
        Enemy.hp = 70;
        Enemy.attack = 3;
        Enemy.defence = 2;
        Enemy.Type = EnemyType::ET_Orc;
        break;
    case 2:
        Enemy.hp = 100;
        Enemy.attack = 5;
        Enemy.defence = 3;
        Enemy.Type = EnemyType::ET_Skeleton;
        break;
    default :
        cout << "error" << endl;
        break;
    }
}