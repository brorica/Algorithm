#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
string gear[4];
int leftIndex[4], rightIndex[4], topIndex[4];
int ableGear[4];

// 1 : 시계 방향, -1 : 반시계 방향
int action(int num)
{
	for (int i = 0; i < 4; i++)
	{
		if (ableGear[i] != 0)
		{
			leftIndex[i] = (leftIndex[i] + (ableGear[i] * -1)) % 8;
			if (leftIndex[i] == -1)
				leftIndex[i] = 7;
			rightIndex[i] = (rightIndex[i] + (ableGear[i] * -1)) % 8;
			if (rightIndex[i] == -1)
				rightIndex[i] = 7;
			topIndex[i] = (topIndex[i] + (ableGear[i] * -1)) % 8;
			if (topIndex[i] == -1)
				topIndex[i] = 7;
		}
	}
	return 0;
}

int checkActionAble(int gear1, int gear2, int turn)
{
	if (gear[gear1][rightIndex[gear1]] != gear[gear2][leftIndex[gear2]])
	{
		if (turn == 1)
			return -1;
		else
			return 1;
	}
	return 0;
}

int check(int gear, int turn)
{
	if (gear == 0)
	{
		ableGear[0] = turn;
		ableGear[1] = checkActionAble(0, 1, ableGear[0]);
		if (ableGear[1] == 0)
			return 0;
		ableGear[2] = checkActionAble(1, 2, ableGear[1]);
		if (ableGear[2] == 0)
			return 0;
		ableGear[3] = checkActionAble(2, 3, ableGear[2]);
	}

	else if (gear == 1)
	{
		ableGear[1] = turn;
		ableGear[0] = checkActionAble(0, 1, ableGear[1]);
		ableGear[2] = checkActionAble(1, 2, ableGear[1]);
		if (ableGear[2] == 0)
			return 0;
		ableGear[3] = checkActionAble(2, 3, ableGear[2]);
	}
	else if (gear == 2)
	{
		ableGear[2] = turn;
		ableGear[3] = checkActionAble(2, 3, ableGear[2]);
		ableGear[1] = checkActionAble(1, 2, ableGear[2]);
		if (ableGear[1] == 0)
			return 0;
		ableGear[0] = checkActionAble(0, 1, ableGear[1]);
	}
	else if (gear == 3)
	{
		ableGear[3] = turn;
		ableGear[2] = checkActionAble(2, 3, ableGear[3]);
		if (ableGear[2] == 0)
			return 0;
		ableGear[1] = checkActionAble(1, 2, ableGear[2]);
		if (ableGear[1] == 0)
			return 0;
		ableGear[0] = checkActionAble(0, 1, ableGear[1]);
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K, ans = 0;
	int num, direct;
	for (int i = 0; i < 4; i++)
	{
		cin >> gear[i];
		topIndex[i] = 0;
		rightIndex[i] = 2;
		leftIndex[i] = 6;
	}
	cin >> K;
	while (K--)
	{
		cin >> num >> direct;
		memset(ableGear, 0, sizeof(ableGear));
		check(num - 1, direct);
		action(num - 1);
	}
	for (int i = 0; i < 4; i++)
	{
		if (gear[i][topIndex[i]] == '1')
			ans += pow(2, i);
	}
	cout << ans;
	return 0;
}