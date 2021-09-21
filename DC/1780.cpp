#include <iostream>
using namespace std;
// 2188
int paper[2200][2200] = { 0, };
int minusOne = 0, zero = 0, one = 0;

int DC(int N, int x, int y)
{
	int minusCount = 0, zeroCount = 0, oneCount = 0;
	int flag = 0;
	for (int i = y; i < N + y; i++)
	{
		for (int j = x; j < N + x; j++)
		{
			if (paper[i][j] == 1)
				oneCount++;
			else if (paper[i][j] == -1)
				minusCount++;
			else
				zeroCount++;
			if ((minusCount > 0 && zeroCount > 0) ||
				(minusCount > 0 && oneCount > 0) ||
				(zeroCount > 0 && oneCount > 0))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	if (flag)
	{
		int first = N / 3;
		int second = (N + N) / 3;
		DC(N / 3, x, y);
		DC(N / 3, x + first, y);
		DC(N / 3, x + second, y);

		DC(N / 3, x, y + first);
		DC(N / 3, x + first, y + first);
		DC(N / 3, x + second, y + first);

		DC(N / 3, x, y + second);
		DC(N / 3, x + first, y + second);
		DC(N / 3, x + second, y + second);
	}
	else
	{
		if (oneCount > 0)
			one++;
		else if (zeroCount > 0)
			zero++;
		else if (minusCount > 0)
			minusOne++;

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
	cout << minusOne << '\n' << zero << '\n' << one;
	return 0;
}