#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

char map[12][6];
bool visit[12][6];

typedef struct
{
	int y, x;
}Dir;

Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int play();
int gravity();
int crash(int y, int x, char status);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];
	while (1)
	{
		if (play())
			ans++;
		else
			break;
	}
	cout << ans;
	return 0;
}

int play()
{
	char currentStatus;
	int ret = 0;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			currentStatus = map[i][j];
			if (currentStatus == '.' || visit[i][j] == 1)
				continue;
			ret = max(ret, crash(i, j, currentStatus));
		}
	}
	gravity();
	return ret;
}

int crash(int y, int x, char status)
{
	queue<Dir> q;
	queue<Dir> crash;
	int hereX, hereY, thereX, thereY;
	memset(visit, 0, sizeof(visit));
	q.push({ y,x });
	crash.push({ y,x });
	while (!crash.empty())
	{
		hereY = crash.front().y;
		hereX = crash.front().x;
		visit[hereY][hereX] = true;
		crash.pop();
		for (int i = 0; i < 4; i++)
		{
			thereY = hereY + dir[i].y;
			thereX = hereX + dir[i].x;
			if (thereX < 0 || thereX >= 6 || thereY < 0 || thereY >= 12 || map[thereY][thereX] != status)
				continue;
			if (visit[thereY][thereX])
				continue;
			q.push({ thereY, thereX });
			crash.push({ thereY, thereX });
		}
	}
	// 터질 때
	if (q.size() >= 4)
	{
		while (!q.empty())
		{
			hereY = q.front().y;
			hereX = q.front().x;
			q.pop();
			map[hereY][hereX] = '.';
		}
		return 1;
	}
	// 안 터질 때
	return 0;
}

int gravity()
{
	queue<Dir> line;
	int hereY, hereX;
	for (int j = 0; j < 6; j++)
	{
		for (int i = 11; i >= 0; i--)
		{
			if (map[i][j] != '.')
				line.push({ i,j });
		}
		int lineIndex = 11;
		while (!line.empty())
		{
			hereY = line.front().y;
			hereX = line.front().x;
			line.pop();
			if (map[lineIndex][j] == '.')
			{
				map[lineIndex][j] = map[hereY][hereX];
				map[hereY][hereX] = '.';
			}
			lineIndex--;
		}
	}
	return 0;
}