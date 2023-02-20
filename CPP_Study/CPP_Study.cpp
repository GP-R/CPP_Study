#include <iostream>
using namespace std;

struct PlayerInfo
{
	short hp;
	int attack;
	char defence;
	__int64 damage;
};

void Sort(int numbers[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i +1; j < length; j++)
		{
			if (numbers[i] > numbers[j])
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

void CreateSixNum(int numbers[])
{
	for (int i = 0; i < 6; i++)
	{
		int createNum = rand() % 45 + 1;
		for (int j = i; j < 6; j++)
		{
			if (createNum == numbers[j])
				i -= 1;
		}
		numbers[i] = createNum;
	}
	Sort(numbers, 6);
}
int main()
{
	srand(unsigned(time(0)));

	int numbers[6] = {};
	CreateSixNum(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << ' ';
	}
    return 0;
}

