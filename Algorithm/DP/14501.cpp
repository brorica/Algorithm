#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int n, i, j, t, p, MAX = 0, temp;
	int dp[20] = { 0, };
	vector<pair<int, int>> schedule;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> t >> p;
		schedule.push_back(make_pair(t, p));
	}
	for (i = 0; i < n; i++)
	{
		temp = schedule[i].first;
		dp[i] = max(dp[i], MAX);
		if (i + temp <= n)
			dp[i + temp] = max(dp[i + temp], dp[i] + schedule[i].second);
		MAX = max(MAX, dp[i]);
	}
	cout << max(dp[n], MAX);
	return 0;
}