#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int bfs(vector<vector<int>>& v)
{
	int i, j, vSize = v.size();
	int here, there, paint = 1;
	int color[20001];
	queue<int> q;
	memset(color, -1, sizeof(color));
	for (i = 0; i < vSize; i++)
	{
		// 색칠된 정점이거나, 연결된 정점이 없으면 넘어감
		if (v[i].size() == 0 || color[i] != -1)
			continue;
		else
		{
			q.push(i);
			color[i] = paint;
		}
		while (!q.empty())
		{
			here = q.front();
			q.pop();
			for (j = 0; j < v[here].size(); j++)
			{
				there = v[here][j];
				// 색칠 안 된 정점이면 칠함
				if (color[there] == -1)
				{
					q.push(there);
					color[there] = !color[here];
				}
				// 색칠된 정점인 경우, 현재 위치의 색과 같은지 확인
				else if (color[there] == color[here])
					return 0;
			}
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int K, V, E, i;
	int a, b;
	cin >> K;
	while (K--)
	{
		cin >> V >> E;
		vector<vector<int>> v(V + 1);
		for (i = 0; i < E; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		if (bfs(v))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}