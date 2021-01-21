#include <iostream>
#include <queue>
using namespace std;

char movie[64][64];

int DC(int N, int x, int y)
{
	int zeroCount = 0, oneCount = 0;
	int flag = 0;
	for (int i = y; i < N + y; i++)
	{
		for (int j = x; j < N + x; j++)
		{
			if (movie[i][j] == '1')
				oneCount++;
			else
				zeroCount++;
			if (oneCount > 0 && zeroCount > 0)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag)
	{
		cout << '(';
		DC(N / 2, x, y);
		DC(N / 2, N / 2 + x, y);
		DC(N / 2, x, N / 2 + y);
		DC(N / 2, N / 2 + x, N / 2 + y);
		cout << ')';
	}
	else
	{
		if (oneCount > 0)
			cout << 1;
		else
			cout << 0;
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
		cin >> movie[i];
	DC(N, 0, 0);
	return 0;
}