#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n)
{
	vector <pair<int, int>> v;
	int a, b, i, ans = n, min = 0x7FFFFF;

	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (i = 0; i < n; i++)
	{
		if (min > v[i].second)
			min = v[i].second;
		else
			ans--;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}
