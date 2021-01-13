#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int array[1024] = { 0, };
	int cache[1024] = { 1, };
	int n, i, j, ans=1;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> array[i];
	reverse(array, array + n);
	for (i = 1; i < n; i++)
	{
		cache[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (array[i] > array[j])
				cache[i] = max(cache[i], cache[j] + 1);
		}
		ans = max(ans, cache[i]);
	}
	cout << ans;
	return 0;
}