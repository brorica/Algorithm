#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, len, ans, temp;
	vector <int> v;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> len;
		v.push_back(len);
	}
	sort(v.begin(), v.end(), greater<int>());
	ans = v[0];
	for (i = 1; i < n; i++)
	{
		temp = v[i] * (i + 1);
		if (temp > ans)
			ans = temp;
	}
	cout << ans;

	return 0;
}