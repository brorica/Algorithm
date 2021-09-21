#include <iostream>
using namespace std;
int paper[128][128] = { 0, };
int blue = 0, white = 0;

int DC(int N, int x, int y)
{
	int blueCount = 0, whiteCount = 0;
	int flag = 0;
	for (int i = y; i < N + y; i++)
	{
		for (int j = x; j < N + x; j++)
		{
			if (paper[i][j] == 1)
				blueCount++;
			else
				whiteCount++;
			if (blueCount > 0 && whiteCount > 0)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag)
	{
		DC(N / 2, x, y);
		DC(N / 2, N / 2 + x, y);
		DC(N / 2, x, N / 2 + y);
		DC(N / 2, N / 2 + x, N / 2 + y);
	}
	else
	{
		if (blueCount > 0)
			blue++;
		else
			white++;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j;
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> paper[i][j];
	DC(N, 0, 0);
	cout << white << '\n' << blue;
	return 0;
}