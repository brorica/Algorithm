#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;

matrix operator * (const matrix &a, const matrix &b)
{
	int i = 0, j = 0, k = 0;
	int n = a.size();
	matrix temp(n, vector<long long>(n));
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
				temp[i][j] += a[i][k] * b[k][j];
			temp[i][j] %= mod;
		}
	}
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	matrix a = { {1,0},{0,1} };
	matrix b = { {1,1},{1,0} };
	long long N;
	cin >> N;
	if (N <= 1)
	{
		cout << N << '\n';
		return 0;
	}
	while (N)
	{
		if (N % 2)
			a = a * b;
		b = b * b;
		N /= 2;
	}
	cout << a[0][1] << '\n';
	return 0;
}