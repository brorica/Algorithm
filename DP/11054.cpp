#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, j, ans1 = 1, ans2 = 0, result = 0;
	vector <int> v(1024);
	int upCache[1024] = { 1, };
	int downCache[1024] = { 1, };

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	for (i = 1; i < n; i++)
	{
		upCache[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (v[i] > v[j])
				upCache[i] = max(upCache[i], upCache[j] + 1);
			ans1 = max(ans1, upCache[i]);
		}
	}
	for (i = n - 1; i >= 0; i--)
	{
		downCache[i] = 1;
		for (j = n - 1; j >= i; j--)
		{
			if (v[i] > v[j])
				downCache[i] = max(downCache[i], downCache[j] + 1);
			ans2 = max(ans2, downCache[i]);
		}
	}
	for (i = 0; i < n; i++)
		result = max(result, downCache[i] + upCache[i]);
	cout << result - 1;
	return 0;
}