#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

char map[128][128];

int bfs(int N, int M)
{
	queue<pair<int, int>> q;
	int ans[128][128] = { 0, };
	int X[4] = { 1, -1, 0, 0 }, Y[4] = { 0,0,-1,1 };
	int hereX, hereY, dx, dy, i;
	q.push(make_pair(0, 0));
	ans[0][0] = 1;
	while (!q.empty())
	{
		hereX = q.front().second;
		hereY = q.front().first;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			dx = hereX + X[i];
			dy = hereY + Y[i];
			if (dx >= 0 && dx < M && dy >= 0 && dy < N)
			{
				if (!ans[dy][dx] && map[dy][dx] == '1')
				{
					ans[dy][dx] = ans[hereY][hereX] + 1;
					q.push(make_pair(dy, dx));
				}
			}
		}
	}
	return ans[N-1][M-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < N; i++)
		cin >> map[i];
	cout << bfs(N, M);
	return 0;
}