#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MOD 1000000000
int N;
long long cache[128][10] = { 0, };

long long dp(int numLen, int index)
{
	if (index < 0 || index > 9)
		return 0;
	if (numLen == N)
		return 1;
	if (cache[numLen][index] == -1)
		cache[numLen][index] = (dp(numLen + 1, index - 1) + dp(numLen + 1, index + 1)) % MOD;
	return cache[numLen][index];
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	long long sum = 0;
	cin >> N;
	for (i = 0; i < 102; i++)
		memset(cache[i], -1, sizeof(long long) * 10);
	for (i = 1; i <= 9; i++)
		sum = (sum + dp(1, i)) % MOD;
	cout << sum;
	return 0;
}