#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector <int>& a, int find)
{
	int left = 0, mid, right;
	right = a.size();
	while (left < right)
	{
		mid = (left + right) / 2;
		if (find < a[mid])
			right = mid;
		else if (find > a[mid])
			left = mid + 1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, data;
	vector<int> v;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		cout << search(v, data) << '\n';
	}
	return 0;
}