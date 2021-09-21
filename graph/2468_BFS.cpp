#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int visit[101][101];
int map[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int BFS(int startX, int startY, int water)
{
	queue<pair<int, int>> q;
	int newX, newY, tempX, tempY;
	visit[startY][startX] = 1;
	q.push({ startX, startY });
	while (!q.empty())
	{
		tempX = q.front().first;
		tempY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			newX = tempX + dx[i];
			newY = tempY + dy[i];
			if (newY < 0 || newY > N || newX < 0 || newX > N || visit[newY][newX] == 1 || map[newY][newX] <= water)
				continue;
			else
			{
				visit[newY][newX] = 1;
				q.push({ newX, newY });
			}
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
		memset(visit, 0, sizeof(visit));
		count = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (map[i][j] > low && visit[i][j] == 0)
					count += BFS(j, i, low);
			}
		}
		ans = max(ans, count);
		low++;
	}
	cout << ans;
	return 0;
}