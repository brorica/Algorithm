#include <iostream>
#include <algorithm>
using namespace std;

int n;
int list[1024] = { 0, };
int cache[1024] = { 1, 0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, ans = 1;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> list[i];
	for (i = 1; i < n; i++)
	{
		cache[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (list[i] > list[j] && cache[i] < cache[j] + 1)
				cache[i] = cache[j] + 1;
		}
		ans = max(cache[i], ans);
	}
	cout << ans;

	return 0;
}