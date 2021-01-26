#include <iostream>
using namespace std;
long long N, ans = 0;
long long cache[1024] = { 0, 1, 3, };

long long func(int count)
{
	if (count == 1)
	{
		return 1;
	}
	long long& ret = cache[count];
	if (ret != 0)
		return ret;
	else
		ret += (func(count - 1) + func(count - 2) * 2) % 10007;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cout << func(N);
	return 0;
}