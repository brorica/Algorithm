#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[32][32] = { 0, };
char map[32][32];
int X[4] = { 1, -1, 0, 0 };
int Y[4] = { 0, 0, 1, -1 };
vector<int> ans;

int dfs(int y, int x)
{
	int dx, dy, count = 1;
	if (map[y][x] == '0' || x < 0 || y < 0)
		return 0;
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		dx = X[i] + x;
		dy = Y[i] + y;
		if (!visit[dy][dx] && map[dy][dx] == '1')
		{
			visit[dy][dx] = 1;
			count += dfs(dy, dx);
		}
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j;
	cin >> N;
	memset(map, 0, sizeof(map));
	for (i = 0; i < N; i++)
		cin >> map[i];

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (!visit[i][j] && map[i][j] == '1')
			{
				ans.push_back(dfs(i, j));
			}
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}