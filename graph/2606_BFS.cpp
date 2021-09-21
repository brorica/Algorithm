#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v(101);
int ans = 0;
int bfs(int start)
{
	bool visit[101] = { 0, };
	int size = v[start].size();
	int here, there;
	queue<int> q;
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		here = q.front();
		q.pop();
		for (int i = 0; i < v[here].size(); i++)
		{
			there = v[here][i];
			if (!visit[there])
			{
				ans++;
				q.push(there);
				visit[there] = 1;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, first, second, i;
	cin >> N >> M;
	for (i = 0; i < M; i++)
	{
		cin >> first >> second;
		v[first].push_back(second);
		v[second].push_back(first);
	}
	for (i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());
	bfs(1);
	cout << ans;
	return 0;
}

