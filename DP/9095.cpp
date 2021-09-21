#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
int func(int sum)
{
	if (sum > n)
		return 0;
	else if (sum == n)
		ans++;
	return func(sum + 1) + func(sum + 2) + func(sum + 3);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, i;
	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> n;
		ans = 0;
		func(0);
		cout << ans << '\n'; 
	}
	return 0;
}