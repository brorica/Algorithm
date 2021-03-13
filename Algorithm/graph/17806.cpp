#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x7FFFFFFF

int map[64][64];
queue<pair<int, int>> q;
int N, M;
int dx[8] = { 0, 0, 1, -1, 1, -1, -1 ,1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int bfs()
{
	int hereX, hereY, thereX, thereY;
	while (!q.empty())
	{
		hereY = q.front().first;
		hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			thereX = hereX + dx[i];
			thereY = hereY + dy[i];
			if (thereX >= 0 && thereX < M && thereY >= 0 && thereY < N)
			{
				if (map[thereY][thereX] > map[hereY][hereX] + 1)
				{
					map[thereY][thereX] = map[hereY][hereX] + 1;
					q.push({ thereY,thereX });
				}
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
	int MAX = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j])
				q.push({ i,j });
			else
				map[i][j] = INF;
		}
	}
	bfs();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			MAX = max(MAX, map[i][j]);
	cout << MAX - 1;
	return 0;
}