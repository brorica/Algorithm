#include <iostream>
#include <algorithm>
using namespace std;
int n;
int cache[1024] = { 0, 1 };
int tile(int x)
{
	if (x < 0)
		return 0;
	int& ret = cache[x];
	if (ret != 0)
		return ret;
	ret = (tile(x - 1) + tile(x - 2)) % 10007;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << tile(n + 1);
	return 0;
}