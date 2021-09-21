#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll G, low, mid, high, count = 0;
	cin >> G;
	for (ll i = 1; i < 100000; i++)
	{
		low = 1;
		high = i;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (i * i - mid * mid > G)
				low = mid + 1;
			else if (i * i - mid * mid < G)
				high = mid - 1;
			else
			{
				count++;
				cout << i << '\n';
				break;
			}
		}
	}
	if (count == 0)
		cout << "-1\n";
	return 0;
}