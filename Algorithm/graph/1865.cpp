#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x7FFFFFFF

vector<pair<int, int>> v[512];
long long upper[512];

int Bellman(int N)
{
	int size, there, cost;
	upper[1] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int here = 1; here <= N; here++)
		{
			size = v[here].size();
			for (int j = 0; j < size; j++)
			{
				there = v[here][j].first;
				cost = v[here][j].second;
				if (upper[there] > upper[here] + cost)
				{
					upper[there] = upper[here] + cost;
					if (i == N)
						return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int TC;
	int N, M, W, S, E, T;
	cin >> TC;
	while (TC--)
	{
		cin >> N >> M >> W;
		for (int i = 0; i <= N; i++)
		{
			v[i].clear();
			upper[i] = INF;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> S >> E >> T;
			v[S].push_back({ E, T });
			v[E].push_back({ S, T });
		}
		for (int i = 0; i < W; i++)
		{
			cin >> S >> E >> T;
			v[S].push_back({ E, -T });
		}
		if (Bellman(N))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}