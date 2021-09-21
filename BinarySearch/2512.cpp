#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, data, sum = 0, MAX = 0;
	int left = 0, mid, right, ans;
	vector<int> city;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		city.push_back(data);
		MAX = max(MAX, data);
	}
	sort(city.begin(), city.end());
	cin >> M;
	right = MAX;
	while (left <= right)
	{
		sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++)
		{
			sum += min(mid, city[i]);
		}
		if (sum > M)
			right = mid - 1;
		else if (sum <= M)
		{
			ans = mid;
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}