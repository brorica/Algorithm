#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// 100001로 바꾸기
	int list[1000] = { 0, };
	int i, n, MAX;
	cin >> n;

	for (i = 0; i < n; i++)
		cin >> list[i];
	MAX = list[0];
	for (i = 1; i < n; i++)
	{
		if (list[i - 1] > 0 && list[i] + list[i - 1] > 0)
			list[i] += list[i - 1];
		if (MAX < list[i])
			MAX = list[i];
	}
	cout << MAX;
}