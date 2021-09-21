#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int visit[101][101];
int map[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dfs(int startX, int startY)
{
	int newX, newY;
	visit[startY][startX] = 1;
	for (int i = 0; i < 4; i++)
	{
		newX = startX + dx[i];
		newY = startY + dy[i];
		if (newY < 0 || newY > N || newX < 0 || newX > N || visit[newY][newX] == 1 || map[newY][newX] == 0)
			continue;
		else
		{
			visit[newY][newX] = 1;
			dfs(newX, newY);
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, high = 0, low = 127, ans = 1, count = 0;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > high)
				high = map[i][j];
			if (map[i][j] < low)
				low = map[i][j];
		}
	}
	while (low <= high)
	{
		for (int water = low; water <= high; water++)
		{
			// 침수 지역
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (map[i][j] <= water)
						map[i][j] = 0;
				}
			}
			memset(visit, 0, sizeof(visit));
			count = 0;
			// 침수 후 안전구역 검사
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (map[i][j] > 0 && visit[i][j] == 0)
					{
						count += dfs(j, i);
					}
				}
			}
			ans = max(ans, count);
		}
		low++;
	}
	cout << ans;
	return 0;
}