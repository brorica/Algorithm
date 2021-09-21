#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 20

int N, ans = -1;
int map[MAX][MAX] = { 0, };
int play(int count);
int move(int d);
int check(int map[][MAX]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	play(0);
	cout << ans;
	return 0;
}

int play(int count)
{
	if (count == 5)
		return check(map);

	int copyMap[MAX][MAX];
	memcpy(copyMap, map, sizeof(map));
	for (int i = 0; i < 4; i++)
	{
		move(i);
		play(count + 1);
		memcpy(map, copyMap, sizeof(map));
	}
	return 0;
}

int check(int map[][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ans < map[i][j])
				ans = map[i][j];
		}
	}
	return 0;
}

int move(int d)
{
	// ╩С го
	vector<int> oneLine;
	int lineIndex = 0, dx = 0;
	if (d == 0 || d == 1)
	{
		for (int j = 0; j < N; j++)
		{
			oneLine.clear();
			for (int i = 0; i < N; i++)
			{
				if (map[i][j] != 0)
				{
					oneLine.push_back(map[i][j]);
					map[i][j] = 0;
				}
			}
			lineIndex = 0;
			dx = 1;
			if (d == 1)
			{
				lineIndex = N - 1;
				dx = -1;
				reverse(oneLine.begin(), oneLine.end());
			}
			for (int i = 0; i < oneLine.size(); i++)
			{
				if (map[lineIndex][j] == 0)
					map[lineIndex][j] = oneLine[i];
				else if (map[lineIndex][j] != 0)
				{
					if (map[lineIndex][j] == oneLine[i])
					{
						map[lineIndex][j] *= 2;
						lineIndex += dx;
					}
					else
					{
						lineIndex += dx;
						map[lineIndex][j] = oneLine[i];
					}
				}
			}
		}
	}
	// аб ©Л
	else if (d == 2 || d == 3)
	{
		for (int i = 0; i < N; i++)
		{
			oneLine.clear();
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] != 0)
				{
					oneLine.push_back(map[i][j]);
					map[i][j] = 0;
				}
			}
			lineIndex = 0;
			dx = 1;
			if (d == 3)
			{
				lineIndex = N - 1;
				dx = -1;
				reverse(oneLine.begin(), oneLine.end());
			}
			for (int k = 0; k < oneLine.size(); k++)
			{
				if (map[i][lineIndex] == 0)
					map[i][lineIndex] = oneLine[k];
				else if (map[i][lineIndex] != 0)
				{
					if (map[i][lineIndex] == oneLine[k])
					{
						map[i][lineIndex] *= 2;
						lineIndex += dx;
					}
					else
					{
						lineIndex += dx;
						map[i][lineIndex] = oneLine[k];
					}
				}
				
			}
		}
	}
	return 0;
}