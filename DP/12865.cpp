#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <pair <int, int>> bag;
	unsigned long long dp[102][100004] = { 0, };
	int N, K, W = 0, V = 0;
	int i, j, weightTemp, valueTemp;
	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> W >> V;
		bag.push_back(make_pair(W, V));
	}
	sort(bag.begin(), bag.end());
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j <= K; j++)
		{
			weightTemp = bag[i - 1].first;
			valueTemp = bag[i - 1].second;
			if (weightTemp > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weightTemp] + valueTemp);
		}
	}
	cout << dp[N][K];
	return 0;
}