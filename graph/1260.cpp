#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v(1001);
bool visit[1001] = { false, };
int dfs(int start)
{
	visit[start] = 1;
	cout << start << ' ';
	for (int i = 0; i < v[start].size(); i++)
	{
		if (!visit[v[start][i]])
			dfs(v[start][i]);
	}
	return 0;
}

int bfs(int start)
{
	queue<int> q;
	bool visit[1001] = { false, };
	int here, there;
	q.push(start);
	visit[start] = 1;
	cout << start << ' ';
	while (!q.empty())
	{
		here = q.front();
		for (int i = 0; i < v[here].size(); i++)
		{
			there = v[here][i];
			if (!visit[there])
			{
				q.push(there);
				visit[there] = 1;
				cout << there << ' ';
			}
		}
		q.pop();
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, start, i, first, second;
	cin >> N >> M >> start;
	for (i = 0; i < M; i++)
	{
		cin >> first >> second;
		v[first].push_back(second);
		v[second].push_back(first);
	}
	for (i = 0; i < N; i++)
		sort(v[i].begin(), v[i].end());
	dfs(start);
	cout << '\n';
	bfs(start);
	return 0;
}