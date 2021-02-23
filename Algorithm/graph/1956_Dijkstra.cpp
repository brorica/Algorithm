#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000
int v[401][401];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E, res = INF;
	int a, b, c;
	cin >> V >> E;
	for (int i = 0; i <= V; i++)
	{
		for (int j = 0; j <= V; j++)
		{
			if (i == j)
				v[i][j] = 0;
			else
				v[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		v[a][b] = c;
	}
	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if(v[i][j] != 0 && v[j][i] != 0)
				res = min(res, v[j][i] + v[i][j]);
		}
	}
	if (res == INF)
		cout << "-1\n";
	else
		cout << res << '\n';
	return 0;
}