#include <iostream>
#include <string.h>
using namespace std;

unsigned long long cache[128] = { 1, 1, 1 };
unsigned long long dp(int T)
{
	if (T <= 2)
		return cache[T];
	if (cache[T] == 0)
		cache[T] = (dp(T - 2) + dp(T - 3));
	return cache[T];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		dp(N - 1);
		cout << cache[N - 1] << '\n';
	}
	return 0;
}