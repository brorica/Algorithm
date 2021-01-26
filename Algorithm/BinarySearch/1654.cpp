#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Search(vector <int>& v, int size, int find)
{
	long long left = 1, mid, right, ans = 0;
	right = v[size-1];
	while (left <= right)
	{
		long long sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < size; i++)
			sum += v[i] / mid;
		if (sum < find)
			right = mid - 1;
		else if (sum >= find)
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, data;
	vector <int> v;
	cin >> N >> K;
	while (N--)
	{
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	cout << Search(v, v.size(), K);

	return 0;
}