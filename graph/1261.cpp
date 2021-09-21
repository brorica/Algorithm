#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x7FFFFFFF

char map[101][101];
int cache[101][101] = { 0, };
int dx[4] = { 1, -1, 0, 0, };
int dy[4] = { 0, 0, 1, -1 };
int M, N;
int dfs(int x, int y)
{
	queue<pair<int, int>> q;
	int hereX, hereY, thereX, thereY, ans = INF;
	q.push({ x, y });
	cache[y][x] = 0;
	while (!q.empty())
	{
		hereX = q.front().first;
		hereY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			thereX = hereX + dx[i];
			thereY = hereY + dy[i];
			if (0 <= thereX && thereX < M && 0 <= thereY && thereY < N)
			{
				if (map[thereY][thereX] == '1')
				{
					if (cache[hereY][hereX] + 1 < cache[thereY][thereX])
					{
						cache[thereY][thereX] = min(cache[hereY][hereX] + 1, cache[thereY][thereX]);
						q.push({ thereX, thereY });
					}
				}
				else
				{
					if (cache[hereY][hereX] < cache[thereY][thereX])
					{
						cache[thereY][thereX] = min(cache[hereY][hereX], cache[thereY][thereX]);
						q.push({ thereX, thereY });
					}
				}
			}
		}
	}
	return cache[N - 1][M - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ret;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cache[i][j] = 0x7FFFFFFF;
	ret = dfs(0, 0);
	if (ret == INF)
		cout << 0;
	else
		cout << ret;
	return 0;
}