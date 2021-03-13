#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000
int student[1024][1024];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, X, MAX = 0;
	int u, v, t;
	int i, j, k;
	cin >> N >> M >> X;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (i == j)
				student[i][j] = 0;
			else
				student[i][j] = INF;
		}
	}

	for (i = 0; i < M; i++)
	{
		cin >> u >> v >> t;
		student[u][v] = t;
	}

	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				student[i][j] = min(student[i][j], student[i][k] + student[k][j]);
			}
		}
	}
	int temp;
	for (i = 1; i <= N; i++)
	{
		temp = student[X][i] + student[i][X];
		if (MAX < temp)
			MAX = temp;
	}
	cout << MAX;
	return 0;
}