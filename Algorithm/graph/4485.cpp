#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INF 0x7FFFFFFF
int map[128][128];
int cost[128][128];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dijkstra(int N)
{
	priority_queue<pair<int, pair<int, int>>> q; // money, x, y;
	int hereX, hereY, hereCost;
	int thereX, thereY, thereCost;
	q.push({ -map[0][0], { 0, 0} });
	cost[0][0] = map[0][0];
	while (!q.empty())
	{
		hereCost = q.top().first * -1;
		hereX = q.top().second.first;
		hereY = q.top().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			thereX = hereX + dx[i];
			thereY = hereY + dy[i];
			if (thereX < 0 || thereX >= N || thereY < 0 || thereY >= N)
				continue;
			thereCost = hereCost + map[thereY][thereX];
			if (thereCost < cost[thereY][thereX])
			{
				cost[thereY][thereX] = thereCost;
				q.push({ thereCost * -1, { thereX, thereY } });
			}
		}
	}
	return cost[N - 1][N - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count = 1;
	while (1)
	{
		int N;
		cin >> N;
		if (N == 0)
			break;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				cost[i][j] = INF;
			}
		}
		cout << "Problem " << count << ": " << dijkstra(N) << '\n';
		count++;
	}
	return 0;
}