#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cost[512] = { 0, };
int cache[512][512] = { 0, };

int dp(int i, int j)
{
	int k, temp, sum = 0;
	if (i == j)
		return 0;
	int& ret = cache[i][j];
	if (ret != -1)
		return ret;
	for (k = i; k <= j; k++)
		sum += cost[k];
	for (k = i; k <= j - 1; k++)
	{
		temp = dp(i, k) + dp(k + 1, j) + sum;
		if (ret == -1 || ret > temp)
			ret = temp;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, K;
	cin >> T;
	while (T--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> K;
		for (int i = 0; i < K; i++)
			cin >> cost[i];
		cout << dp(0, K - 1) << '\n';
	}
	return 0;
}