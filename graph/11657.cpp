#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x7FFFFFFF

vector<pair<int, int>> v[512];
long long upper[512];

int Bellman(int N)
{
	int i, size, there, cost;
	upper[1] = 0;
	for (i = 1; i <= N; i++)
	{
		for (int here = 1; here <= N; here++)
		{
			size = v[here].size();
			for (int j = 0; j < size; j++)
			{
				there = v[here][j].first;
				cost = v[here][j].second;
				if (upper[here] != INF && upper[there] > upper[here] + cost)
				{
					upper[there] = upper[here] + cost;
					// 마지막 탐색임에도 수정할 값이 있다는 것은 음수 사이클
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
	int N, M;
	int A, B, C;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
	}
	for (int i = 0; i <= N; i++)
		upper[i] = INF;
	if (Bellman(N))
		cout << "-1\n";
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (upper[i] == INF)
				cout << "-1\n";
			else
				cout << upper[i] << '\n';
		}
	}
	return 0;
}