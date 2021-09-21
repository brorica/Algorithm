#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int hay[10001] = { 0, };
	int T, sum = 0, average, ans = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> hay[i];
		sum += hay[i];
	}
	average = sum / T;
	for (int i = 0; i < T; i++)
	{
		if (hay[i] < average)
			ans += average - hay[i];
	}
	cout << ans;
	return 0;
}