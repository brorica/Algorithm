#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 0x7FFFFFFF

vector<pair<int, int>> graph[20001];
int visit[20001];

int dfs(int start)
{
	priority_queue< pair<int, int> > q;
	int size, here, hereCost, there, thereCost;
	q.push({ 0, start });
	while (!q.empty())
	{
		here = q.top().second;
		hereCost = q.top().first * -1;
		size = graph[here].size();
		q.pop();
		if (visit[here] < hereCost) 
			continue;
		for (int i = 0; i < size; i++)
		{
			there = graph[here][i].first;
			thereCost = hereCost + graph[here][i].second;
			if (thereCost < visit[there])
			{
				visit[there] = thereCost;
				q.push({ visit[there] * -1, there });
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E, K; 
	int u, v, w;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	for (int i = 0; i <= V; i++)
		visit[i] = INF;
	visit[K] = 0;
	dfs(K);
	for (int i = 1; i <= V; i++)
	{
		if (visit[i] == INF)
			cout << "INF\n";
		else
			cout << visit[i] << '\n';
	}


	return 0;
}