#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int board[21][21] = { 0, };
int ans = 0x7FFFFF;
int isUsed[21] = { 0, };
int T, half;

int dfs(int count, int start)
{
	int i, j;
	if (count == half)
	{
		int startSum = 0, linkSum = 0;
		vector <int> start;
		vector <int> link;
		for (i = 0; i < T; i++)
		{
			if (isUsed[i]) link.push_back(i);
			else start.push_back(i);
		}
		for (i = 0; i < half; i++)
		{
			for (j = i + 1; j < half; j++)
			{
				startSum += board[start[i]][start[j]];
				startSum += board[start[j]][start[i]];
				linkSum += board[link[i]][link[j]];
				linkSum += board[link[j]][link[i]];
			}
		}
		ans = min(ans, abs(startSum - linkSum));
	}
	else
	{
		for (i = start; i < T; i++)
		{
			if (!isUsed[i])
			{
				isUsed[i] = 1;
				dfs(count + 1, i + 1);
				isUsed[i] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	cin >> T;
	for (i = 0; i < T; i++)
		for (j = 0; j < T; j++)
			cin >> board[i][j];
	half = T >> 1;
	dfs(0, 0);
	cout << ans;
	return 0;
}