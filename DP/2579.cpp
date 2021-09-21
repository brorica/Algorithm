#include <iostream>
#include <algorithm>
using namespace std;
int stair[301] = { 0, };
int cache[301] = { 0, };
int N;

int dp(int count)
{
	int temp1, temp2;
	if (count <= 3)
		return cache[count];
	if (cache[count] != 0)
		return cache[count];
	temp1 = dp(count - 2) + stair[count];
	temp2 = dp(count - 3) + stair[count - 1] + stair[count];
	cache[count] = max(temp1, temp2);
	return cache[count];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (auto i = 1; i <= N; i++)
		cin >> stair[i];
	cache[1] = stair[1];
	cache[2] = stair[1] + stair[2];
	cache[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	dp(N);
	cout << cache[N];
	return 0;
}