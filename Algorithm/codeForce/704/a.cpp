#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned long long t, p, ans;
	unsigned long long swimmer[3];
	cin >> t;
	while (t--)
	{
		cin >> p >> swimmer[0] >> swimmer[1] >> swimmer[2];
		sort(swimmer, swimmer + 3);
		ans = -1;
		for (int j = 0; j < 3; j++)
		{
			if (p % swimmer[j] == 0)
			{
				ans = 0;
				break;
			}
			else if (p < swimmer[j])
				ans = min(ans, swimmer[j] - p);
			else if (p > swimmer[j])
			{
				unsigned long long temp = p / swimmer[j] + !(!(p % swimmer[j]));
				ans = min(ans, swimmer[j] * temp - p);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}