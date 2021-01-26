#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> x;

int search(int size, int count)
{
	int left = 1, mid, right, ans = x[1] - x[0];
	right = x[size - 1] - x[0];
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		int temp = 1, start = x[0];
		for (int i = 1; i < size; i++)
		{
			if (x[i] - start >= mid)
			{
				temp++;
				start = x[i];
			}
		}
		if (temp >= count)
		{
			ans = mid;
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, C, data;
	cin >> N >> C;
	for (auto i = 0; i < N; i++)
	{
		cin >> data;
		x.push_back(data);
	}
	sort(x.begin(), x.end());
	cout << search(N, C);
	return 0;
}