#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int X[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int Y[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int bfs(int I)
{
	queue<pair<int, int>> q;
	int chess[301][301] = { 0, };
	int startX, startY, endX, endY;
	int hereX, hereY, dx, dy;
	cin >> startX >> startY >> endX >> endY;
	q.push({ startY, startX });
	chess[startY][startX] = 0;
	while (!q.empty())
	{
		hereX = q.front().second;
		hereY = q.front().first;
		if (hereX == endX && hereY == endY)
			return chess[hereY][hereX];
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			dx = hereX + X[i];
			dy = hereY + Y[i];
			if (dx >= 0 && dx < I && dy >= 0 && dy < I)
			{
				if (!chess[dy][dx])
				{
					chess[dy][dx] = chess[hereY][hereX] + 1;
					q.push({ dy, dx });
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
	int T, I;
	cin >> T;
	while (T--)
	{
		cin >> I;
		cout << bfs(I) << '\n';
	}
	return 0;
}