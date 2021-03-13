#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 100000000
int N, M, X, MAX = 0;

int dijkstra(int start, vector<pair<int, int>> v[], int* array)
{
	priority_queue <pair<int, int>> q;
	int here, hereCost, there, thereCost, size;
	q.push({ 0, start });
	array[start] = 0;
	while (!q.empty())
	{
		hereCost = q.top().first * -1;
		here = q.top().second;
		size = v[here].size();
		q.pop();
		for (int i = 0; i < size; i++)
		{
			there = v[here][i].first;
			if (there == start)
				continue;
			thereCost = hereCost + v[here][i].second;
			if (thereCost < array[there])
			{
				array[there] = thereCost;
				q.push({ -thereCost, there });
			}
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> goPartyVector[1024];
	vector<pair<int, int>> goHomeVector[1024];
	int u, v, t;
	int i, j;
	int goParty[1024];
	int goHome[1024];
	cin >> N >> M >> X;

	for (i = 0; i < M; i++)
	{
		cin >> u >> v >> t;
		goPartyVector[u].push_back({ v,t });
		goHomeVector[v].push_back({ u, t });
	}
	for (int i = 1; i <= N; i++)
	{
		goParty[i] = INF;
		goHome[i] = INF;
	}
	dijkstra(X, goPartyVector, goParty);
	dijkstra(X, goHomeVector, goHome);
	for (i = 1; i <= N; i++)
	{
		MAX = max(MAX, goParty[i] + goHome[i]);
	}
	cout << MAX;
	return 0;
}