#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Input
{
	int Y;
	int X;
	int W;
};

char map[1024][1024];
short visit[1024][1024][2] = { 0, };
int N, M;

int bfs()
{
	queue<Input> q;
	int hereX, hereY, wall, dx, dy;
	int X[4] = { 1,-1, 0, 0 }, Y[4] = { 0, 0, 1,-1 };
	q.push({ 0, 0, 1 });
	visit[0][0][1] = 1;
	visit[0][0][0] = 1;
	while (!q.empty())
	{
		hereX = q.front().X;
		hereY = q.front().Y;
		wall = q.front().W;
		q.pop();
		if (hereY == N - 1 && hereX == M - 1)
			return visit[hereY][hereX][wall];
		for (int i = 0; i < 4; i++)
		{
			dx = hereX + X[i];
			dy = hereY + Y[i];
			if (dx >= 0 && dx < M && dy >= 0 && dy < N)
			{
				// º® »Ñ¼ö±â
				if (map[dy][dx] == '1' && wall == 1)
				{
					visit[dy][dx][0] = visit[hereY][hereX][wall] + 1;
					q.push({ dy, dx, 0 });
				}
				if (map[dy][dx] == '0' && visit[dy][dx][wall] == 0)
				{
					visit[dy][dx][wall] = visit[hereY][hereX][wall] + 1;
					q.push({ dy, dx, wall });
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < N; i++)
		cin >> map[i];
	cout << bfs();
	return 0;
}