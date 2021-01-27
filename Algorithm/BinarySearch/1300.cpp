#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, K;
	long long left = 1, mid, right, count = 0, ans, temp;
	cin >> N >> K;
	right = K;
	while (left <= right)
	{
		count = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= N; i++)
		{
			temp = mid / i;
			if (temp > N)
				count += N;
			else
				count += temp;
		}
		if (count < K)
			left = mid + 1;
		else if (count >= K)
		{
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}