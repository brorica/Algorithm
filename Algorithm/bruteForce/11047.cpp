#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K, i, sum=0;
	int coin[16] = { 0, };
	cin >> N >> K;
	for (i = 0; i < N; i++)
		cin >> coin[i];
	for (i = N - 1; i >= 0; i--)
	{
		sum += K / coin[i];
		//cout << coin[i] << ' ' << K / coin[i] << '\n';
		K = K % coin[i];
		
		if (K == 0)
			break;
	}
	cout << sum;
	return 0;
}