#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H, maxCount;
bool flag = 0;
bool ladder[32][16] = { 0, };

int backtracking(int depth, int count)
{
	if (flag)
		return 0;
	if (count == maxCount)
	{
		int row;
		for (int i = 1; i <= N; i++)
		{
			row = i;
			for (int j = 1; j <= H; j++)
			{
				if (ladder[j][row])
					row++;
				else if (row > 1 && ladder[j][row - 1])
					row--;
			}
			if (i != row)
			{
				flag = 0;
				return 0;
			}
		}
		flag = 1;
		return 0;
	}
	for (int i = depth; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0 && ladder[i][j] == 0)
			{
				ladder[i][j] = 1;
				backtracking(i, count + 1);
				ladder[i][j] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		cin >> b >> a;
		ladder[b][a] = 1;
	}
	for (maxCount = 0; maxCount <= 3; maxCount++)
	{
		backtracking(1, 0);
		if (flag)
		{
			cout << maxCount << '\n';
			return 0;
		}
	}
	cout << "-1";
	return 0;
}