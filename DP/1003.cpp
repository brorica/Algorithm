#include <iostream>
#include <string.h>
using namespace std;

unsigned long long cache[256] = { 0, 1 };
int fibo(int n)
{
	if (n == 0 || n == 1)
		return cache[n];
	if (cache[n] == 0)
		cache[n] = fibo(n - 1) + fibo(n - 2);
	return cache[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, result;
	cin >> T;
	while (T--)
	{
		cin >> n;
		fibo(n);
		if (n == 0)
			cout << "1 " << "0\n";
		else
			cout << cache[n - 1] << ' ' << cache[n] << '\n';
		
	}

	return 0;
}