#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> memory, cost;
int cache[101][10001] = { 0, };
int N, M, MIN = 0x7FFFFFFF;
int dp()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= 10000; j++)
		{
			if (cost[i - 1] > j)
				cache[i][j] = cache[i - 1][j];
			else
			{
				cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - cost[i - 1]] + memory[i - 1]);
				if (cache[i][j] >= M)
					MIN = min(MIN, j);
					
			}
		}
	}
	return MIN;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, data;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		memory.push_back(data);
	}
	for (i = 0; i < N; i++)
	{
		cin >> data;
		cost.push_back(data);
	}
	cout << dp();
	return 0;
}