#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> tree;

long long Search(int size, int M)
{
	long long left = 0, mid, right, ans = 0;
	right = tree[size - 1];
	while (left <= right)
	{
		long long sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < size; i++)
		{
			if(tree[i] >= mid)
				sum += tree[i] - mid;
		}
		if (sum < M)
			right = mid - 1;
		else
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
	int N, M, data;
	cin >> N >> M;
	while (N--)
	{
		cin >> data;
		tree.push_back(data);
	}
	sort(tree.begin(), tree.end());
	cout << Search(tree.size(), M);
	return 0;
}