#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	int i;
	int ans1;
	int tempN, tempM;
	cin >> N >> M;
	for (i = 1; i <= N && i <= M; i++)
	{
		if (N % i == 0 && M % i == 0)
			ans1 = i;
	}
	tempN = N;
	tempM = M;
	while (tempN != tempM)
	{
		if (tempM > tempN)
			tempN += N;
		if (tempN > tempM)
			tempM += M;
	}
	cout << ans1 << '\n' << tempN;

	return 0;
}