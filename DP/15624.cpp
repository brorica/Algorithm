#include <iostream>
using namespace std;
int N;
int cache[1000001] = { 0, 1, };
int func(int n)
{
	if (n < 0)
		return 0;
	int& ret = cache[n];
	if (ret != 0)
		return ret;
	ret = ((func(n - 1) % 1000000007) + (func(n - 2) % 1000000007)) % 1000000007;
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