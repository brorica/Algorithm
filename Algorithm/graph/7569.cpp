#include <iostream>
#include <queue>
using namespace std;

struct Input
{
	int H;
	int N;
	int M;
};

short tomato[128][128][128] = { 0, };
queue<Input> q;

int bfs(int H, int N, int M)
{
	int i, j, k, qSize = 0, count = -1;
	int hereX, hereY, hereZ, dz, dx, dy;
	short X[4] = { 1, -1, 0, 0 }, Y[4] = { 0, 0, 1, -1 }, Z[2] = { -1, 1 };
	while (!q.empty())
	{
		qSize = q.size();
		for (i = 0; i < qSize; i++)
		{
			hereX = q.front().M;
			hereY = q.front().N;
			hereZ = q.front().H;
			q.pop();
			for (j = 0; j < 2; j++)
			{
				dz = hereZ + Z[j];
				if (dz >= 0 && dz < H)
				{
					if (tomato[dz][hereY][hereX] == -1)
						tomato[dz][hereY][hereX] = 1;
					else if (tomato[dz][hereY][hereX] == 0)
					{
						tomato[dz][hereY][hereX] = 1;
						q.push({ dz, hereY, hereX });
					}
				}
			}
			for (j = 0; j < 4; j++)
			{
				dx = hereX + X[j];
				dy = hereY + Y[j];
				if (dx >= 0 && dx < M && dy >= 0 && dy < N)
				{
					if (tomato[hereZ][dy][dx] == -1)
						tomato[hereZ][dy][dx] = 1;
					else if (tomato[hereZ][dy][dx] == 0)
					{
						tomato[hereZ][dy][dx] = 1;
						q.push({ hereZ, dy, dx });
					}
				}

			}

		}
		count++;
	}
	for (k = 0; k < H; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (tomato[k][i][j] == 0)
					return -1;
			}
		}
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, N, H, i, j, k;
	cin >> M >> N >> H;
	for (k = 0; k < H; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				cin >> tomato[k][i][j];
				if (tomato[k][i][j] == 1)
					q.push({ k, i, j });
			}
		}
	}
	cout << bfs(H, N, M);
	return 0;
}