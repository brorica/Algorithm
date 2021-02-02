#include <iostream>
#include <cstring>
using namespace std;

int map[512][512] = { 0, };
int cache[512][512];
int dx[4] = { 1, -1,0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;

int dp(int y, int x)
{
	if (x == N && y == M)
		return 1;
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x, ny = dy[i] + y;
		if (0 < nx && nx <= N && 0 < ny && ny <= M)
		{
			if (map[y][x] > map[ny][nx])
				ret += dp(ny, nx);
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	cin >> M >> N;
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++)
			cin >> map[i][j];
	memset(cache, -1, sizeof(cache));
	cout << dp(1, 1);
	return 0;
}