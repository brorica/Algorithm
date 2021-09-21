#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 0x7FFFFFFF
vector<pair<int, int>> v[401];

int search(int start, int V)
{
	priority_queue< pair<int, int> > q;
	int visit[401];
	int here, hereDistance, there, thereDistance, size, res = INF;
	for (int i = 0; i <= V; i++)
		visit[i] = INF;
	visit[start] = 0;
	q.push({ 0, start });
	while (!q.empty())
	{
		here = q.top().second;
		hereDistance = q.top().first * -1;
		size = v[here].size();
		q.pop();
		for (int i = 0; i < size; i++)
		{
			there = v[here][i].first;
			thereDistance = v[here][i].second + hereDistance;
			if (there == start)
				res = min(res, thereDistance);
			if (thereDistance < visit[there])
			{
				visit[there] = thereDistance;
				q.push({ -thereDistance, there });
			}
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E, res = INF;
	int a, b, c;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	for (int i = 1; i <= V; i++)
		res = min(res, search(i, V));
	if (res == INF)
		cout << "-1\n";
	else
		cout << res << '\n';
	return 0;
}