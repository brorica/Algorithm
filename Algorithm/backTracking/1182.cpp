#include <iostream>
#include <algorithm>
using namespace std;

int n, s, ans=0;
// 100001 로 바꾸기
int list[1000] = { 0, };
int cache[1000] = { 0, };

int func(int index, int sum)
{
	if (index == n)
		return 0;
	sum += list[index];
	if (sum == s)
		ans++;
	func(index + 1, sum);
	func(index + 1, sum - list[index]);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	cin >> n >>  s;
	for (i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list + n);
	func(0, 0);
	cout << ans;
	return 0;
}