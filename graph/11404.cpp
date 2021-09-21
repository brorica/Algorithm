#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int city[101][101];

#define INF 1000000000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int a, b, c;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i == j)
				city[i][j] = 0;
			else
				city[i][j] = INF;
			
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (city[a][b] != INF)
			city[a][b] = min(city[a][b], c);
		else
			city[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == INF)
				cout << "0 ";
			else
				cout << city[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}