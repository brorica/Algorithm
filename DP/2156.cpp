#include <iostream>
#include <algorithm>
using namespace std;

// 10001로 바꾸기
int redWine[10002] = { 0, };
unsigned long long cache[10002] = { 0, };
int n;
int dp(int count)
{
	if (count < 0)
		return 0;
	if (cache[count] == 0)
	{
		int temp1, temp2;
		temp1 = max(dp(count - 2), dp(count - 3) + redWine[count - 1]) + redWine[count];
		temp2 = dp(count - 1);
		cache[count] = max(temp1, temp2);
	}
	return cache[count];

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (auto i = 0; i < n; i++)
		cin >> redWine[i];
	cache[0] = redWine[0];
	cout << dp(n);
	return 0;
}