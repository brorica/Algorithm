#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, u, v, MAX = INF, ans = 1;
	int relation[101][101] = { 0, }, sum[101] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				relation[i][j] = 0;
			else
				relation[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		relation[u][v] = 1;
		relation[v][u] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				relation[i][j] = min(relation[i][j], relation[i][k] + relation[k][j]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
				sum[i] += relation[i][j];
		}
		if (MAX > sum[i])
		{
			MAX = sum[i];
			ans = i;
		}
	}
	cout << ans;
	return 0;
}