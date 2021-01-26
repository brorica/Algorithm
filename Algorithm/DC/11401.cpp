#include <iostream>
using namespace std;

typedef long long ll;

ll calc(ll bottom, ll mod, ll mod2)
{
	ll ans = 1;
	while (mod2)
	{
		if (mod2 % 2)
		{
			ans *= bottom;
			ans %= mod;
		}
		bottom *= bottom;
		bottom %= mod;
		mod2 /= 2;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, N, K;
	ll top = 1, bottom = 1, mod = 1000000007, temp;
	cin >> N >> K;
	for (i = 1; i <= N; i++)
		top = (top * i) % mod;
	for (i = 1; i <= K; i++)
		bottom = (bottom * i) % mod;
	for (i = 1; i <= N - K; i++)
		bottom = (bottom * i) % mod;
	temp = calc(bottom, mod, mod - 2);
	cout << top * temp % mod;
	return 0;
}