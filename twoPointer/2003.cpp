#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[10002] = { 0, };
	int N, M;
	int start = 0, end = 0, sum = 0, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	while (end <= N)
	{
		if (sum >= M)
		{
			sum -= board[start];
			start++;
		}
		else
		{
			sum += board[end];
			end++;
		}
		if (sum == M)
			ans++;
	}
	cout << ans;
	return 0;
}