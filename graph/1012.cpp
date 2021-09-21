#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[64][64] = { 0, };
bool map[64][64] = { 0, };
int X[4] = { 1, -1, 0, 0 };
int Y[4] = { 0, 0, 1, -1 };

int bfs(int M, int N, int y, int x)
{
	int hereX, hereY;
	int dx, dy;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;
	while (!q.empty())
	{
		hereY = q.front().first;
		hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			dx = X[i] + hereX;
			dy = Y[i] + hereY;
			if (dx >= 0 && dy >= 0 && dx < M && dy < N)
			{
				if (!visit[dy][dx] && map[dy][dx] == 1)
				{
					visit[dy][dx] = 1;
					q.push(make_pair(dy, dx));
				}
			}
		}
	}
	return 0;
}

int Input(int M, int N, int K)
{
	int first, second, count = 0;
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < K; i++)
	{
		cin >> first >> second;
		map[second][first] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
			{
				bfs(M, N, i, j);
				count++;
			}
		}
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, i, M, N, K;
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		cout << Input(M, N, K) << '\n';
	}
	return 0;
}