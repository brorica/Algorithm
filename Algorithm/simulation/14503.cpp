#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 51

typedef struct
{
	int y, x;
}Dir;

Dir dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int map[MAX][MAX] = { 0, };
int N, M, ans = 0;

int search(int y, int x, int d);
int turn(int d);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int startX, startY, d;
	cin >> N >> M;
	cin >> startY >> startX >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	search(startY, startX, d);
	cout << ans;
	return 0;
}
// 1 : 寒, 0 : 没家 x, -1 : 没家 o
int search(int y, int x, int d)
{
	int hereX, hereY, hereD, thereX, thereY, thereD, copyD;
	bool flag;
	queue<pair<Dir, int>> q;
	q.push({ {y, x}, d });
	while (!q.empty())
	{
		hereY = q.front().first.y;
		hereX = q.front().first.x;
		hereD = q.front().second;
		copyD = hereD;
		if (map[hereY][hereX] == 0)
		{
			map[hereY][hereX] = -1;
			ans++;
		}
		q.pop();

		flag = true;
		for (int i = 0; i < 4; i++)
		{
			thereD = turn(hereD);
			thereY = hereY + dir[thereD].y;
			thereX = hereX + dir[thereD].x;

			if (thereX < 0 || thereX > M || thereY < 0 || thereY > N || map[thereY][thereX] != 0)
			{
				hereD = thereD;
				continue;
			}
			if (map[thereY][thereX] == 0)
			{
				q.push({ { thereY, thereX }, thereD });
				flag = false;
				break;
			}
		}

		if (flag)
		{
			thereY = hereY - dir[copyD].y;
			thereX = hereX - dir[copyD].x;
			if (thereX < 0 || thereX > M || thereY < 0 || thereY > N || map[thereY][thereX] == 1)
				break;
			else
				q.push({ { thereY, thereX }, copyD });
		}
	}
	return 0;
}

int turn(int d)
{
	if (d == 0)
		return 3;
	else if (d == 1)
		return 0;
	else if (d == 2)
		return 1;
	return 2;
}