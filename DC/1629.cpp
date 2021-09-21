#include <iostream>
using namespace std;

int func(long long a, long long b, long long c)
{
	if (b == 1)
		return a;
	long long temp = func(a, b / 2, c);
	if (b % 2)
		return (temp * temp % c) * a % c;
	return (temp * temp) % c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << func(a % c, b, c);
	return 0;
}