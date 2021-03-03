#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, data, i, ans1, ans2;
	ll start = 0, end = 0, sum = 0, MIN = LLONG_MAX;
	vector<ll> v;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	end = N - 1;
	while (start < end)
	{
		sum = v[start] + v[end];
		if (llabs(sum) < MIN)
		{
			MIN = llabs(sum);
			ans1 = v[start];
			ans2 = v[end];
		}
		if (sum < 0)
			start++;
		else
			end--;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}