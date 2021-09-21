#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, i, j;
	int cache[10001] = { 1,  };
	int coin[128] = { 0, };
	cin >> n >> k;

	for (i = 1; i <= n; i++)
		cin >> coin[i];

	for (i = 1; i <= n; i++)
	{
		for (j = coin[i]; j <= k; j++)
			cache[j] += cache[j - coin[i]];
	}
	cout << cache[k];
	return 0;
}