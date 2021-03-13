#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define INF 0x7FFFFFFF

string map[64];
int cost[64][64];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dijkstra(int N)
{
	queue <pair<int, pair<int, int>>> q;
	int hereX, hereY, hereCost;
	int thereX, thereY, thereCost;
	q.push({ 0,{ 0, 0 } });	// cost, x, y
	cost[0][0] = 0;
	while (!q.empty())
	{
		hereCost = q.front().first * -1;
		hereX = q.front().second.first;
		hereY = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			thereX = hereX + dx[i];
			thereY = hereY + dy[i];
			if (thereX >= 0 && thereX < N && thereY >= 0 && thereY < N)
			{
				thereCost = hereCost;
				// º® ¶Õ´Â »óÈ²
				if (map[thereY][thereX] == '0')
					thereCost += 1;
				if (thereCost < cost[thereY][thereX])
				{
					cost[thereY][thereX] = thereCost;
					q.push({ thereCost * -1,{ thereX, thereY } });
				}

			}
		}
	}
	return cost[N-1][N-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cost[i][j] = INF;
	cout << dijkstra(n);
	return 0;
}