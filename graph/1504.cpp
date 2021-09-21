#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x7FFFFFFF

vector<pair<int, int>> graph[801];
int visit[801];

int dfs(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int size, here, hereCost, there, thereCost;
	for (int i = 0; i <= end; i++)
		visit[i] = INF;
	visit[start] = 0;
	q.push({ 0, start });
	while (!q.empty())
	{
		here = q.top().second;
		hereCost = q.top().first;
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
				q.push({ visit[there], there });
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, E, i;
	int u, v, w, v1, v2;
	int onetov1, onetov2, v1tov2, v1toN, v2toN;
	long long ans = INF;
	cin >> N >> E;
	for (i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	cin >> v1 >> v2;
	dfs(1, N);
	onetov1 = visit[v1];
	onetov2 = visit[v2];
	dfs(v1, N);
	v1tov2 = visit[v2];
	v1toN = visit[N];
	dfs(v2, N);
	v2toN = visit[N];
	ans = min(ans, (long long)onetov1 + (long long)v1tov2 + (long long)v2toN);
	ans = min(ans, (long long)onetov2 + (long long)v1tov2 + (long long)v1toN);
	if (v1tov2 == INF || ans == INF)
		cout << "-1\n";
	else
		cout << ans;
	return 0;
}