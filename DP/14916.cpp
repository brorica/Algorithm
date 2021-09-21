#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int temp[2] = { 5, 2 };
int cache[100002] = { 0, };
int func(int money)
{
	if (money == 0)
		return cache[money];
	else if (money < 0)
		return 0x7FFFFF;
	int& ret = cache[money];
	if (ret != -1)
		return ret;
	ret = 0x7FFFFF;
	for (auto i = 0; i < 2; i++)
		ret = min(ret, func(money - temp[i]) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans;
	cin >> N;
	memset(cache, -1, sizeof(cache));
	ans = func(N);
	if (ans == 0x7FFFFF)
		cout << "-1";
	else
		cout << ans + 1;
	return 0;
}