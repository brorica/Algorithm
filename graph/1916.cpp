#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 0x7FFFFFFF

vector<pair<int, int>> graph[1024];
int visit[1024];

int search(int start, int end)
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
	return visit[end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, start, end;
	int u, v, c;
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		visit[i] = INF;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}
	cin >> start >> end;
	cout << search(start, end);

	return 0;
}