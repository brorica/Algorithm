#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M, ans = 0x7FFFFFFF, totalCCTV;
int map[9][9] = { 0, };
int rotation[6] = { 0, 4, 2, 4, 4, 1 };
vector <pair<int, pair<int, int>>> cctv;

int calc(int x, int y, int dir);

int check()
{
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0)
				count++;
	return count;
}

int backtracking(int cctvNum)
{
	if (cctvNum == totalCCTV)
	{
		ans = min(ans, check());
		return 0;
	}
	int type = cctv[cctvNum].first;
	int y = cctv[cctvNum].second.first;
	int x = cctv[cctvNum].second.second;
	int backup[9][9] = { 0, };
	for (int i = 0; i < rotation[type]; i++)
	{
		memcpy(backup, map, sizeof(map));
		if (type == 5)
		{
			calc(x, y, 0);
			calc(x, y, 1);
			calc(x, y, 2);
			calc(x, y, 3);
		}
		else if (type == 4)
		{
			calc(x, y, i);
			calc(x, y, (i + 1) % 4);
			calc(x, y, (i + 2) % 4);
		}
		else if (type == 3)
		{
			calc(x, y, i);
			calc(x, y, (i + 1) % 4);
		}
		else if (type == 2)
		{
			calc(x, y, i);
			calc(x, y, (i + 2) % 4);
		}
		else if (type == 1)
		{
			calc(x, y, i);
		}
		backtracking(cctvNum + 1);
		memcpy(map, backup, sizeof(map));
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int maxIndex = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6)
				cctv.push_back({ map[i][j], { i, j } });
		}
	}
	sort(cctv.begin(), cctv.end());
	totalCCTV = cctv.size();
	backtracking(0);
	cout << ans;
	return 0;
}
// 0 : µ¿ / 1 : ³² / 2 : ¼­ / 3 : ºÏ
int calc(int x, int y, int dir)
{
	// µ¿
	if (dir == 0)
	{
		for (int i = x; i < M; i++)
		{
			if (map[y][i] == 6)
				return 0;
			if (map[y][i] != 0)
				continue;
			map[y][i] = 1;
		}
	}
	// ³²
	else if (dir == 1)
	{
		for (int i = y; i < N; i++)
		{
			if (map[i][x] == 6)
				return 0;
			if (map[i][x] != 0)
				continue;
			map[i][x] = 1;
		}
	}
	// ¼­
	else if (dir == 2)
	{
		for (int i = x; i >= 0; i--)
		{
			if (map[y][i] == 6)
				return 0;
			if (map[y][i] != 0)
				continue;
			map[y][i] = 1;
		}
	}
	// ºÏ
	else if (dir == 3)
	{
		for (int i = y; i >= 0; i--)
		{
			if (map[i][x] == 6)
				return 0;
			if (map[i][x] != 0)
				continue;
			map[i][x] = 1;
		}
	}
	return 0;
}