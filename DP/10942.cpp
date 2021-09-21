#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int num[2048];
int cache[2048][2048];

int dp(int S, int E)
{
	if (S >= E)
		return 1;
	int& ret = cache[S][E];
	if (ret != -1)
		return ret;
	if (num[S] == num[E])
		ret = dp(S + 1, E - 1);
	else
		ret = 0;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, i, S, E;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> num[i];
	cin >> M;
	memset(cache, -1, sizeof(cache));
	for (i = 0; i < M; i++)
	{
		cin >> S >> E;
		cout << dp(S, E) << '\n';
	}
	return 0;
}