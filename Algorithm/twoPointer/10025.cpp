#include <iostream>
#include <vector>
using namespace std;
#define LEN 1000001
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v[LEN] = { 0, };
	int i, N, K, x, g, maxLen = 0, MAX=0;
	int start = 0;
	long long sum = 0;
	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> g >> x;
		v[x] = g;
		if (x > maxLen)
			maxLen = x;
	}
	for (i = 0; i <= K * 2 && i < LEN; i++)
		MAX += v[i];
	sum = MAX;
	for (i = K * 2 + 1; i < LEN; i++)
	{
		sum = sum - v[start] + v[i];
		start++;
		if (sum > MAX)
			MAX = sum;
	}
	cout << MAX;
	return 0;
}