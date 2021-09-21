#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long T, n, m, x;
	long long ans;
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> x;
		long long startRow = (x / n) + !(!(x % n));
		long long startNum = 1 + (startRow - 1) * n;
		long long startColumn = x - startNum;
		ans = startColumn * m + startRow;
		cout << ans << '\n';

	}
	return 0;
}
