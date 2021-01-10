#include <iostream>
#include <algorithm>
using namespace std;

int n;
int house[1001][3] = { 0, };
int cache[1001][3] = { 0, };
int RGB(int count, int current)
{
	if (count == n)
		return 0;
	int& ret = cache[count][current];
	if (ret != 0)
		return cache[count][current];
	if (current == 0)
		ret = min(RGB(count + 1, 1), RGB(count + 1, 2)) + house[count][current];
	if (current == 1)
		ret = min(RGB(count + 1, 0), RGB(count + 1, 2)) + house[count][current];
	if (current == 2)
		ret = min(RGB(count + 1, 0), RGB(count + 1, 1)) + house[count][current];
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, ans = 0x7FFFFFF;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			cin >> house[i][j];
	for (i = 0; i < 3; i++)
	{
		ans = min(ans, RGB(0, i));
	}
	cout << ans;
	return 0;
}