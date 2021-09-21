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
	int N, start, end, data;
	ll sum = 0, MIN = LLONG_MAX;
	vector<int> ans(3);
	vector<ll> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 2; i++)
	{
		start = i + 1;
		end = N - 1;
		while (start < end)
		{
			sum = v[start] + v[end] + v[i];
			if (llabs(sum) < MIN)
			{
				MIN = llabs(sum);
				ans[0] = i;
				ans[1] = start;
				ans[2] = end;
			}
			if (sum < 0)
				start++;
			else if(sum > 0)
				end--;
			else
			{
				i == N;
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << v[ans[0]] << ' ' << v[ans[1]] << ' ' << v[ans[2]];
	return 0;
}