#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long NArray[41] = { 0, };
int N, C;

int dfs(int start, int end, long long sum, vector<long long>& v)
{
	if (start == end)
	{
		v.push_back(sum);
		return 0;
	}
	dfs(start + 1, end, sum, v);
	dfs(start + 1, end, sum + NArray[start], v);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<long long> first;
	vector<long long> second;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> NArray[i];
	dfs(0, N / 2, 0, first);
	dfs(N / 2, N, 0, second);
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	int size = first.size();
	long long ans = 0;
	for (int i = 0; i < size; i++)
		ans += upper_bound(second.begin(), second.end(), C - first[i]) - second.begin();
	cout << ans;
	return 0;
}