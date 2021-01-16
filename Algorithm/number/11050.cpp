#include <iostream>
#include <algorithm>
using namespace std;

int cache[16][16] = { 1, 0 };
int n, k;

int binomial(int a, int b, int maxB)
{
	if (b == 0 || b == maxB)
		return 1;
	int& ret = cache[a][b];
	if (ret != 0)
		return cache[a][b];
	ret = binomial(a - 1, b - 1, maxB - 1) + binomial(a - 1, b, maxB - 1);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cout << binomial(n, k, n);
	return 0;
}