#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j, ans = 0;
	int array[1024] = { 0, };
	int sum[1024] = { 0, };
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> array[i];
	for (i = 0; i < N ; i++)
	{
		sum[i] = array[i];
		for (j = 0; j < i; j++)
		{
			if (array[i] > array[j])
				sum[i] = max(sum[i], sum[j] + array[i]);
		}
		ans = max(sum[i], ans);
	}
	cout << ans;
	return 0;
}