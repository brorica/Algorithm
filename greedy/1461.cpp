#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int solve(int size, vector<int> &v, int MAX);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> plus, minus;
	int data, MAX = -1, maxTemp = 0, count = 0, ans = 0;
	int plusIndex = 0, minusIndex = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		if (data > 0)
			plus.push_back(data);
		else
			minus.push_back(data);
		// 편도로 보낼 거
		if (abs(data) > MAX)
		{
			MAX = abs(data);
			maxTemp = data;
		}
	}
	// 한 쪽이 비어있다면 0 넣어주기
	if (plus.size() == 0)
		plus.push_back(0);
	if (minus.size() == 0)
		minus.push_back(0);
	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());
	if (abs(plus[0]) < abs(minus[0]))
	{
		ans += solve(plus.size(), plus, maxTemp);
		ans += solve(minus.size(), minus, maxTemp);
	}
	else
	{
		ans += solve(minus.size(), minus, maxTemp);
		ans += solve(plus.size(), plus, maxTemp);
	}
	cout << ans;
	return 0;
}

int solve(int size, vector<int>& v, int MAX)
{
	int index, ret = 0;
	for (index = 0; index < size; index += M)
	{
		if (v[index] == MAX)
			ret += abs(MAX);
		else
			ret += abs(v[index]) * 2;
	}
	return ret;
}