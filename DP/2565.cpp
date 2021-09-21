#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, i=0,j=0;
	int len = 1, MAX = -1;
	int dp[101];
	vector <pair <int, int>> list;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		list.push_back(make_pair(a, b));
	}
	sort(list.begin(), list.end());
	cout << "\n\n";
	for (i = 0; i < n; i++)
		cout << list[i].first << ' ' << list[i].second << '\n';
	for (i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (list[i].second > list[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		MAX = max(dp[i], MAX);
	}
	cout << n - MAX;
	return 0;
}