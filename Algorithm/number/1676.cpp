#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long func(int n)
{
	unsigned long long ret = 0;
	while (n >= 5)
	{
		ret += n / 5;
		n /= 5;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, temp;
	unsigned long long top = 0, bottom = 0;
	cin >> N >> M;

	temp = N - M;
	top = func(N);
	bottom += func(M) + func(temp);
	cout << top - bottom;
	return 0;
}