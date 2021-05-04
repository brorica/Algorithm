#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int board[128][128] = { 0, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int melt(int startX, int startY) 
{
	bool visit[128][128] = { 0, };
	queue<pair<int, int>> cheese;
	int hereX, hereY, thereX, thereY;
	visit[startY][startX] = 1;
	cheese.push({ startX, startY });
	while (!cheese.empty())
	{
		hereX = cheese.front().first;
		hereY = cheese.front().second;
		cheese.pop();
		for (int i = 0; i < 4; i++)
		{
			thereX = hereX + dx[i];
			thereY = hereY + dy[i];
			if (thereX < 0 || thereX > M || thereY < 0 || thereY > N || visit[thereY][thereX] == 1)
				continue;
			else
			{
				visit[thereY][thereX] = 1;
				if (board[thereY][thereX] == 1)
					board[thereY][thereX] = -1;
				else if (board[thereY][thereX] == 0)
					cheese.push({ thereX, thereY });
			}
		}
	}
	return 0;
}
int cheeseCount(int start)
{
	int ret = 0;
	for (int i = start; i <= N; i++)
	{
		for (int j = start; j <= M; j++)
		{
			if (board[i][j] == -1)
				board[i][j] = 0;
			else if (board[i][j] == 1)
				ret++;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int startX = 0, startY = 0, count;
	int ans = 0, ret = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				ans++;
		}
	}
	for(count = 1;;count++)
	{
		melt(startX, startY);
		startX++;
		startY++;
		ret = cheeseCount(startX);
		if (ret == 0)
			break;
		ans = ret;
	}
	cout << count << '\n' << ans;
	return 0;
}