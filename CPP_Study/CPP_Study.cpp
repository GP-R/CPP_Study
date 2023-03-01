#include <iostream>
using namespace std;
#include <vector>

bool findNum(vector<int>& v, int num)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if (num == (*it))
		{
			return true;
		}
	}
	return false;
}

int isDivEleven(vector<int>& v)
{
	int count = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if ((*it)%11 == 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<int> v;
	for (int i = 1; i < 100; i++)
	{
		//int num = rand() % 100;
		v.push_back(i);
	}
	int input;
	cin >> input;
	bool result = findNum(v, input);
	cout << result << endl;
	int elecount = isDivEleven(v);
	cout << elecount << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		(*it) = (*it) * 3;
		cout << (*it) << endl;
	}
	
	return 0;
}