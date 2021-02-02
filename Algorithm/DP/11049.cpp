#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 0x7FFFFFFF
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j, k, m;
	int d[512] = { 0, };
	int cache[512][512] = { 0, };

	cin >> N;
	cin >> d[0] >> d[1];
	for (i = 2; i <= N; i++)
		cin >> d[i - 1] >> d[i];
	for (m = 0; m < N; m++)
	{
		for (i = 1; i <= N - m; i++)
		{
			j = i + m;
			if (i != j)
			{
				cache[i][j] = MAX;
				for (k = i; k <= j - 1; k++)
					cache[i][j] = min(cache[i][j], cache[i][k] + cache[k + 1][j] + d[i - 1] * d[k] * d[j]);
			}
		}
	}
	cout << cache[1][N];
	return 0;
}