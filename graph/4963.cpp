#include <iostream>
#include <cstring>
using namespace std;

int w, h;
int visit[51][51];
int map[51][51];
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int dfs(int startX, int startY)
{
	int newX, newY;
	for (int i = 0; i < 8; i++)
	{
		newX = startX + dx[i];
		newY = startY + dy[i];
		if (newY < 0 || newY > h || newX < 0 || newX > w || visit[newY][newX] == 1 || map[newY][newX] == 0)
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
	int ans;
	while (1)
	{
		ans = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visit[i][j] == 0 && map[i][j] == 1)
				{
					visit[i][j] = 1;
					ans += dfs(j, i);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}