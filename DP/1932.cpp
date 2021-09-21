#include <iostream>
#include <algorithm>
using namespace std;

int triangle[501][501] = { 0, };
int cache[501][501] = { 0, };
int n;
int dp(int count, int way)
{
	// ÀÌÅ» ¹æÁö
	if (count > n || way > count)
		return 0;
	if (count == n)
		return triangle[count][way];
	if (cache[count][way] != 0)
		return cache[count][way];
	else
	{
		cache[count][way] = max(dp(count + 1, way), dp(count + 1, way + 1));
		cache[count][way] += triangle[count][way];
	}
	return cache[count][way];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j <= i; j++)
			cin >> triangle[i][j];
	cout << dp(0, 0);
	return 0;
}