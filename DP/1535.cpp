#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, j, ans;
	int total[22][102] = { 0, };
	int lose[22] = { 0, }, loseTemp;
	int get[22] = { 0, }, getTemp;
	vector <pair<int, int>> status;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> lose[i];
	for (i = 0; i < n; i++)
		cin >> get[i];
	for (i = 0; i < n; i++)
		status.push_back(make_pair(lose[i], get[i]));
	sort(status.begin(), status.end());
	for (i = 1; i <= n; i++)
	{
		loseTemp = status[i - 1].first;
		getTemp = status[i - 1].second;
		for (j = 1; j <= 100; j++)
		{
			if (loseTemp >= j)
				total[i][j] = total[i - 1][j];
			else
			{
				total[i][j] = max(getTemp + total[i - 1][j - loseTemp], total[i - 1][j]);
				ans = max(total[i][j], ans);
			}
		}
	}
	cout << total[n][100];
	return 0;
}