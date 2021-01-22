#include <iostream>
#include <algorithm>
using namespace std;
long long N, B;
long long ans[6][6];
long long original[6][6] = { 0, };
int calc(long long a[6][6],long long b[6][6])
{
	long long i = 0, j = 0, k = 0;
	long long tempArray[6][6] = { 0, };
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
				tempArray[i][j] += a[i][k] * b[k][j];
			tempArray[i][j] %= 1000;
		}
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = tempArray[i][j];
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long i = 0, j = 0;
	cin >> N >> B;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> original[i][j];
		}
		ans[i][i] = 1;
	}
	while (B)
	{
		if (B % 2)
			calc(ans, original);
		calc(original, original);
		B /= 2;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}