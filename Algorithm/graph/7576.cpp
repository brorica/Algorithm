#include <iostream>
#include <queue>
using namespace std;

short tomato[1024][1024] = { 0, };
queue<pair<int, int>> q;

int bfs(int N, int M)
{
	int i, j, qSize = 0, count = -1;
	int hereX, hereY, dx, dy;
	int X[4] = { 1, -1, 0, 0 } , Y[4] = { 0, 0, 1, -1 };
	while (!q.empty())
	{
		qSize = q.size();
		for (i = 0; i < qSize; i++)
		{
			hereX = q.front().second;
			hereY = q.front().first;
			q.pop();
			for (j = 0; j < 4; j++)
			{
				dx = hereX + X[j];
				dy = hereY + Y[j];
				if (dx >= 0 && dx < M && dy >= 0 && dy < N)
				{
					if (tomato[dy][dx] == -1)
						tomato[dy][dx] = 1;
					else if (tomato[dy][dx] == 0)
					{
						tomato[dy][dx] = 1;
						q.push(make_pair(dy, dx));
					}
				}

			}
			
		}
		count++;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (tomato[i][j] == 0)
				return -1;
		}
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, N, i, j;
	cin >> M >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	cout << bfs(N, M);
	return 0;
}